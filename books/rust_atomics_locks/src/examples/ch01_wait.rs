/// `s` in scope() is the environemnt which is the main thread
/// This is more clear in the chapter [02 code]( https://github.com/m-ou-se/rust-atomics-and-locks/blob/main/examples/ch2-03-progress-reporting-unpark.rs)

/// 4-6 steps much faster than 0-5 because producer sleeps for a huge time: 1s
fn queue_wait() {
    let queue = Mutex::new(VecDeque::new());
    let not_empty = Condvar::new();

    thread::scope(|s| {
        // 0. Spawn a new thread and keep going to producer
        s.spawn(|| {
            loop {
                let mut q = queue.lock().unwrap();
                let item = loop {
                    // 4 spawned thread locks the queue, gets the item , unlocks it
                    if let Some(item) = q.pop_front() {
                        println!("We get the following one item in the queue:");
                        break item;
                    } else {
                        // 6. loop starts again and queue happens to be empty
                        println!("Queus is empty so we wait ...");
                        q = not_empty.wait(q).unwrap();
                    }
                };
                drop(q);
                // 5. printing the item onto screen
                dbg!(item);
            }
        });

        // Producer is in the same scope as consumer thread(s)
        for i in 0..10 {
            // 1. Producer first locks queue, puts i32 into it, and unlocks it
            queue.lock().unwrap().push_back(i);
            // 2. Print this notification
            println!("Producer just pushed one item into the queue and we notify a thread");
            // 3. Notify one thread about the i32 put into the queue and sleep
            not_empty.notify_one();
            thread::sleep(Duration::from_secs(1));
        }
    });
}
