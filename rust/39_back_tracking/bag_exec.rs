use std::collections::HashMap;

fn solve_bag(items: Vec<(i32, i32)>, capacity: i32) -> HashMap<i32, Vec<i32>> {
    let pick_idx       = 0;
    let current_weight = 0;
    let mut picks      = vec![-1; items.len()];
    let mut max_values = vec![-1; items.len()];
    let mut result     = HashMap::new();

    bag(pick_idx,
        current_weight,
        &items,
        capacity,
        &mut picks,
        &mut max_values,
        &mut result,);

    result
}

fn bag(pick_idx:       i32,
       current_weight: i32,
       items:          &Vec<(i32, i32)>,
       capacity:       i32,
       picks:          &mut Vec<i32>,
       max_values:     &mut Vec<i32>,
       result:         &mut HashMap<i32, Vec<i32>>) {
   if current_weight == capacity || pick_idx == items.len() as i32 {
       if get_value(items, &picks) > get_value(items, max_values) {
           for i in 0..picks.len() {
            max_values[i] = picks[i];
           }
           result.insert(get_value(items, max_values), picks.to_vec());
       }
       return;
   }

   // 选
   let item_weight = items[pick_idx as usize].0;
   if current_weight + item_weight <= capacity {
       picks[pick_idx as usize] = 1;
       bag(pick_idx + 1,
           current_weight + item_weight,
           items,
           capacity,
           picks,
           max_values,
           result);
   }

   // 不选
   picks[pick_idx as usize] = 0;
   bag(pick_idx + 1,
       current_weight,
       items,
       capacity,
       picks,
       max_values,
       result);

}

fn get_value(items: &Vec<(i32, i32)>, picks: &Vec<i32>) -> i32 {
    let mut result = 0;
    for i in 0..picks.len() {
        if picks[i] == 1 { result += items[i].1; }
    }
    result
}

fn main() {
    // [(weight, value)...]
    let items = vec![(3, 5), (2, 2), (1, 4), (1, 2), (4, 10)];
    let m = solve_bag(items, 10);
    println!("{:?}", m); // {13: [1, 1, 1, 1, 0], 21: [1, 1, 1, 0, 1]}
}
