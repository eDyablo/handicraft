pub struct Stats {
  pub min: i32,
  pub max: i32,
  pub count: u32,
  pub avarage: f64,
}

impl Stats {
  fn new() -> Stats {
    return Stats {
      min: 0,
      max: 0,
      count: 0,
      avarage: 0.0,
    }
  }
  
  pub fn calc(arr: &[i32]) -> Stats {
    let mut stats = Stats::new();
    if arr.len() > 0 {
      stats.count = 1;
      stats.min = arr[0];
      stats.max = arr[0];
      let mut sum = arr[0];
      for i in 1..arr.len() {
        if arr[i] < stats.min {
          stats.min = arr[i];
        }
        if arr[i] > stats.max {
          stats.max = arr[i];
        }
        sum += arr[i];
        stats.count += 1;
      }
      stats.avarage = f64::from(sum) / f64::from(stats.count);
    }
    return stats;
  }
}
