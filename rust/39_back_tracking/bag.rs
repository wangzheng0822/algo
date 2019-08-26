use std::collections::HashMap;

fn solve_bag(items: Vec<i32>, capacity: i32) -> HashMap<i32, Vec<i32>> {
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
       items:          &Vec<i32>,
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
   if current_weight + items[pick_idx as usize] <= capacity {
       picks[pick_idx as usize] = 1;
       bag(pick_idx + 1,
           current_weight + items[pick_idx as usize],
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

fn get_value(items: &Vec<i32>, picks: &Vec<i32>) -> i32 {
    let mut result = 0;
    for i in 0..picks.len() {
        if picks[i] == 1 { result += items[i]; }
    }
    result
}

fn main() {
    let items = vec![2, 2, 4, 6, 3];
    let m = solve_bag(items, 10);
    println!("{:?}", m); // {10: [1, 1, 0, 1, 0], 8: [1, 1, 1, 0, 0]}
}
