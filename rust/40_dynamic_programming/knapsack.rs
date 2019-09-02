fn knapsack(items: Vec<(i32, i32)>, capacity: i32) -> i32 {
    let mut states = vec![-1; (capacity + 1) as usize];
    let mut result = vec![];
    states[0] = 0;
    if items[0].0 <= capacity { states[items[0].0 as usize] = items[0].1; }
    for i in 1..items.len() {
        for j in 0..=(capacity - items[i].0) as usize {
            if states[j] >= 0 {
                let value = states[j] + items[i].1;
                if value > states[j+items[i].0 as usize] {
                    states[j+items[i].0 as usize] = value;
                    result.push(items[i].0);
                }
            }
        }
    }

    let mut max_value = -1;
    for i in (0..=capacity as usize).rev() {
        if states[i] >= max_value {
            max_value = states[i];
        }
    }
    max_value
}

fn main() {
    let items = vec![(2, 3), (2, 4), (4, 8), (6, 9), (3, 6)];
    let capacity = 9;
    let m = knapsack(items, capacity);
    println!("{}", m);
}
