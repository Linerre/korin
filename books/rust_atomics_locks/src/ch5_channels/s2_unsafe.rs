use std::cell::UnsafeCell;
use std::mem::MaybeUninit;
use std::sync::atomic::AtomicBool;
use std::sync::atomic::Ordering::{Acquire, Release};

pub struct Channel<T> {
    // bare bone verison of Option<T>; no checks for empty
    message: UnsafeCell<MaybeUninit<T>>,
    ready: AtomicBool,
}

// Tell compiler the T is (indeed safe to) `Send`
unsafe impl<T> Sync for Channel<T> where T: Send {}

impl<T> Channel<T> {
    pub const fn new() -> Self {
        Self {
            message: UnsafeCell::new(MaybeUninit::uninit()),
            ready: AtomicBool::new(false),
        }
    }

    // Calling send more than once might result in a data race, since the
    // second sender will be overwriting the data while the receiver might
    // be trying to read the first message.
    /// Safety: Only call this once!
    pub unsafe fn send(&self, message: T) {
        (*self.message.get()).write(message);
        // When receiver loads `true` using `Acquire` ordering,
        // this `Release` ensures receiver views that msg been
        // put into channel
        self.ready.store(true, Release);
    }

    pub fn is_ready(&self) -> bool {
        self.ready.load(Acquire)
    }

    // The `MaybeUninit` type does not track whether it has been
    // initialized or not, and will therefore not automatically drop
    // its contents when dropped. This means if a message is sent but
    // never received, the message will never be dropped
    /// Safety: Only call this once,
    /// and only after is_ready() returns true!
    pub unsafe fn receive(&self) -> T {
         // no parking here but user of this interface can, if they prefer to block
        (*self.message.get()).assume_init_read()
    }
}
