use std::sync::Condvar;
use std::collections::VecDeque;

pub struct Channel<T> {
    queue: Mutex<VecDeque<T>>,
    item_ready: Condvar,
}

impl<T> Channel<T> {
    pub fn new() -> Self {
        Self {
            queue: Mutex::new(VecDeque::new()),
            item_ready: Condvar::new(),
        }
    }

    pub fn send(&self, message: T) {
        self.queue.lock().unwrap().push_back(message); // mutex unlocked after this
        self.item_ready.notify_one(); // happens after mutex unlocked
    }

    /// Remember that the Condvar::wait method will unlock the Mutex while waiting
    /// and relock it before returning. So, our receive function will not keep the
    /// mutex locked while waiting.  See Rust doc for std::sync::Condvar::wait
    /// https://doc.rust-lang.org/std/sync/struct.Condvar.html#method.wait
    pub fn receive(&self) -> T {
        let mut b = self.queue.lock().unwrap();
        loop {
            if let Some(message) = b.pop_front() {
                return message;
            }
            b = self.item_ready.wait(b).unwrap();
        }
    }
}
