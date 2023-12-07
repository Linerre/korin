use std::thread;
use std::sync::Mutex;
use std::time::Duration;
use std::sync::Condvar;
use std::collections::VecDeque;
use std::sync::atomic::AtomicUsize;
use std::sync::atomic::AtomicBool;
use std::sync::atomic::Ordering::Relaxed;

pub mod ch01_mutex;

fn main() {
    let num_done = AtomicUsize::new(0);

    let main_thread = thread::current();

    thread::scope(|s| {
        // A background thread to process all 100 items.
        s.spawn(|| {
            for i in 0..100 {
                process_item(i); // Assuming this takes some time.
                num_done.store(i + 1, Relaxed);
                main_thread.unpark(); // Wake up the main thread.
            }
        });

        // The main thread shows status updates.
        loop {
            let n = num_done.load(Relaxed);
            if n == 100 { break; }
            println!("Working.. {n}/100 done");
            thread::park_timeout(Duration::from_secs(1));
        }
    });

    println!("Done!");
}

fn process_item(i: usize) {
    for _x in i..i*10 {}
}
