use std::collections::{ BTreeSet, HashMap, VecDeque };

struct Node {
    adj: HashMap<String, u32>,
}

fn dp_tsp(nodes: &HashMap<String, Node>, start: &str, mut counter: i32) -> Option<(Vec<String>, u32)> {
    let mut memo : HashMap<(BTreeSet<String>, String), (String, u32)> = HashMap::new();
    let mut queue : VecDeque<(BTreeSet<String>, String)> = VecDeque::new();
    let mut nodes_set : BTreeSet<String> = BTreeSet::new();
    
    for (i, _) in &mut nodes.iter() {
        nodes_set.insert(i.to_owned());
    }
    let temp : BTreeSet<_> = [start.to_owned()].iter().cloned().collect();
    memo.insert((temp.clone(), start.to_owned()), (start.to_owned(), 0));
    queue.push_back((temp, start.to_owned()));

    let temp = start.to_owned();
    while !queue.is_empty() {
        let x = queue.pop_front().unwrap();
        let y = &memo[&x].to_owned();
        let mut diff : BTreeSet<_> = nodes_set.difference(&x.0).collect();
        if !x.0.contains(&format!("{}{}", start, counter-1)) {
            diff.insert(&temp);
        }
        if !diff.is_empty() {
            for node in diff {
                let mut x_new = x.0.clone();
                if x_new.contains(node) {
                    let mut m = 1;
                    while x_new.contains(&format!("{}{}", node, m)) && m < counter {
                        m += 1;
                    }
                    if m != counter {
                        x_new.insert(format!("{}{}", node, m).to_owned());
                    } else {
                        continue;
                    }
                } else {
                    x_new.insert(node.to_owned());
                }
                match nodes[&x.1].adj.get(node) {
                    Some(t) => {
                        let new_dist = y.1 + t;
                        match memo.get(&(x_new.clone(), node.to_owned())) {
                            Some(old_memo) => {
                                if old_memo.1 > new_dist {
                                    memo.insert((x_new, node.to_owned()), (x.1.clone(), new_dist));
                                }
                            },
                            None => {
                                memo.insert((x_new.clone(), node.to_owned()), (x.1.clone(), new_dist));
                                queue.push_back((x_new, node.to_owned()));
                            }
                        }
                    },
                    None => {}
                }
            }
        } else {
            let node = start;
            let mut x_new = x.0.clone();
            x_new.insert(format!("{}{}", start, counter).to_owned());
            match nodes[&x.1].adj.get(node) {
                Some(t) => {
                    let new_dist = y.1 + t;
                    match memo.get(&(x_new.clone(), node.to_owned())) {
                        Some(old_memo) => {
                            if old_memo.1 > new_dist {
                                memo.insert((x_new, node.to_owned()), (x.1.clone(), new_dist));
                            }
                        },
                        None => {
                            memo.insert((x_new.clone(), node.to_owned()), (x.1.clone(), new_dist));
                        }
                    }
                },
                None => {}
            }
        }
    }
    
    for i in 1..counter+1 {
        nodes_set.insert(format!("{}{}", start, i).to_owned());
    }
    
    let mut path = Vec::new();
    let mut temp = start.to_owned();
    let last_entry = memo.get(&(nodes_set.clone(), temp.to_owned()));
    while !nodes_set.is_empty() {
        match memo.get(&(nodes_set.clone(), temp.to_owned())) {
            Some(t) => {
                if temp == start && counter >= 1 {
                    nodes_set.remove(&format!("{}{}", start, counter));
                    counter -= 1;
                } else {
                    nodes_set.remove(&temp);
                }
                path.push(temp);
                temp = t.0.clone();
            },
            None => { break; }
        };
    }
    if nodes_set.is_empty() {
        Some((path, last_entry.unwrap().1))
    } else {
        None
    }
}

fn main() {
    let mut nodes : HashMap<String, Node> = HashMap::new();
    let mut x = HashMap::new();
    x.insert("B".to_owned(), 10);
    x.insert("C".to_owned(), 7);
    nodes.insert("A".to_owned(), Node { adj: x });
    let mut x = HashMap::new();
    x.insert("C".to_owned(), 8);
    x.insert("A".to_owned(), 3);
    nodes.insert("B".to_owned(), Node { adj: x });
    let mut x = HashMap::new();
    x.insert("A".to_owned(), 4);
    x.insert("B".to_owned(), 8);
    nodes.insert("C".to_owned(), Node { adj: x });
    match dp_tsp(&nodes, "A", 2) {
        Some(t) => {
            println!("Found path {:?} with total cost {}.", t.0, t.1);
        },
        None => {
            println!("There is no mTSP path available.");
        }
    }
}

