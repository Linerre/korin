use std::sync::atomic::AtomicUsize;
use std::sync::atomic::Ordering::Relaxed;
use std::thread;
use std::time::Duration;

fn fetch_via_4threads() {
    // Atomic types don't implement `Copy` so only reference can be moved below
    // Also, the ref will be used by the main(foreground) thread
    let num_done = &AtomicUsize::new(0);

    thread::scope(|s| {
        // Four background threads to process all 100 items, 25 each.
        for t in 0..4 {
            s.spawn(move || {// whatever vars appear in this scope moved into it
                for i in 0..25 {
                    // Assuming this takes some time.  Indeed if it doesn't,
                    // the 4 threads finish their jobs almost instantly, far less
                    // than within 1sec, resulting in my seeing the final 'Done!'
                    // also instantly

                    process_item(t * 25 + i);
                    num_done.fetch_add(1, Relaxed);
                }
            });
        }

        // The main thread shows status updates, every second.
        loop {
            let n = num_done.load(Relaxed);
            if n == 100 { break; }
            println!("Working.. {n}/100 done");
            thread::sleep(Duration::from_secs(1));
        }
    });

    println!("Done!");
}
