use std::sync::atomic::AtomicBool;
use std::sync::atomic::Ordering::{Acquire, Release};
use std::cell::UnsafeCell;
use std::ops::{Deref, DerefMut};

// AtomicBool allows multiple threads to interact with the lock simultaneously
pub struct SpinLock<T> {
    locked: AtomicBool,
    value: UnsafeCell<T>,
}

// The guard lives as long as the lock it tries to protect
pub struct Guard<'a, T> {
    lock: &'a SpinLock<T>,
}

// Tell compiler that `T` can be sent between threads
unsafe impl<T> Sync for SpinLock<T> where T: Send {}

impl<T> SpinLock<T> {
    pub const fn new(value: T) -> Self {
        Self {
            locked: AtomicBool::new(false),
            value: UnsafeCell::new(value),
        }
    }

    // Acquire ordering means it follows some Release that happens before
    // lifetime of self is elided since the returnef ref will exist as long
    // as the lock itself
    pub fn lock(&self) -> Guard<T> {
        while self.locked.swap(true, Acquire) {
            std::hint::spin_loop();
        }
        // unsafe { &mut *self.value.get() }
        Guard { lock: self }
    }

    // Safety: The &mut T from lock() must be gone!
    // (And no cheating by keeping reference to fields of that T around!)
    // The following method can be removed because of the impl of Drop trait
    // pub unsafe fn unlock(&self) {
    //     self.locked.store(false, Release);
    // }
}

impl<T> Deref for Guard<'_, T> {
    type Target = T;
    fn deref(&self) -> &T {// Also can be writted as `&Self::Target`
        // Safety: The very existence of this Guard
        // guarantees we've exclusively locked the lock.
        unsafe { &*self.lock.value.get() }
        //         ^guard.(spin)lock.value
    }
}

impl<T> DerefMut for Guard<'_, T> {
    fn deref_mut(&mut self) -> &mut T {
        // Safety: The very existence of this Guard
        // guarantees we've exclusively locked the lock.
        unsafe { &mut *self.lock.value.get() }
    }
}

impl<T> Drop for Guard<'_, T> {
    fn drop(&mut self) {
        self.lock.locked.store(false, Release);
    }
}
