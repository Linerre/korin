// in first.rs
use std::mem;
// pub says we want people outside this module to be able to use List

pub struct List {
    head: Link,
}

enum Link {
    Empty,
    More(Box<Node>),
}

struct Node {
    elem: i32,
    next: Link,
}

impl List {
    pub fn new() -> Self {
        List { head: Link::Empty }
    }

    pub fn push(&mut self, elem: i32) {
        let new_node = Box::new(Node {
            elem: elem,
            next: mem::replace(&mut self.head, Link::Empty),
        });

        self.head = Link::More(new_node);
    }

    pub fn pop(&mut self) -> Option<i32> {
        match &self.head {
            Link::Empty => {
                // TODO
            }
            Link::More(node) => {
                // TODO
            }
        };
        unimplemented!()
    }
}
