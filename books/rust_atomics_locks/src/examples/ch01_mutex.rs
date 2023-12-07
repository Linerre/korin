//! The original code does not contain any `&mut` ref to `Mutex<i32>`.  They are used
//! here solely to respect Rust's ownership rules and also for the convenience of
//! comparison. See the original code:
//! 1. https://marabos.nl/atomics/basics.html#interior-mutability
//! 2. https://github.com/m-ou-se/rust-atomics-and-locks/tree/main/examples
use std::thread;
use std::sync::Mutex;
use std::time::Duration;

pub fn unlock_by_dropping(n: &mut Mutex<i32>) {
    thread::scope(|s| {
        for _ in 0..10 {
            s.spawn(|| {
                let mut guard = n.lock().unwrap(); // guard is a &mut T(i32)
                for _ in 0..100 {
                    *guard += 1; // use guard to access the inner int
                }
            }); // guard goes out of scope and gets dropped (mutex unlocked now)
        }
    })
}


/// This fn takes about 10 secs to finish because the `Mutex` is kept locking for
/// at least 1s for each thread, resulting in the effect of parallelism nullified
pub fn unlock_after_sleeping(n: &mut Mutex<i32>) {
    thread::scope(|s| {
        for _ in 0..10 {
            s.spawn(|| {
                let mut guard = n.lock().unwrap();
                for _ in 0..100 {
                    *guard += 1; // use guard to access the inner int
                }
                // Let's make other threads wait for 1 sec first
                thread::sleep(Duration::from_secs(1));
            }); // guard goes out of scope and gets dropped (mutex unlocked now)
            // other spawned thread now are awakened to try to lock `n`
            // ...
        }
    })
}

/// Unlock `Mutex` by first dropping it.  It is important to keep
/// "the amount of time a mutex is locked as short as possible."
pub fn unlock_after_dropping_first(n: &mut Mutex<i32>) {
    thread::scope(|s| {
        for _ in 0..10 {
            s.spawn(|| {
                let mut guard = n.lock().unwrap();
                for _ in 0..100 {
                    *guard += 1; // use guard to access the inner int
                }
                // drop the `Mutex` before it sleeps and goes out of scope and
                drop(guard);
                // Other threads start trying to lock the `Mutex` while the current
                // starts sleeping for 1s
                thread::sleep(Duration::from_secs(1));
            });

            // other spawned thread now are awakened to try to lock `n`
            // ...
        }
    })
}

#[cfg(test)]
mod tests {

    use super::*;

    // when any thread in the following fns panics,
    // the Mutex to be marked as 'posioned' not no threads will
    // be able to lock or access the data inside

    #[test]
    fn test_unlock_by_dropping() {
        let mut n = Mutex::new(0);
        unlock_by_dropping(&mut n);
        assert_eq!(n.into_inner().unwrap(), 1000);
}
}
