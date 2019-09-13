mod stats;

use stats::*;

#[test]
fn stats_calc_returns_empty_stats_for_empty_sequence() {
  let stats = Stats::calc(&[]);
  assert_eq!(0, stats.min);
  assert_eq!(0, stats.max);
  assert_eq!(0, stats.count);
  assert_eq!(0., stats.avarage);
}

#[test]
fn stats_calc_returns_stats_for_one_number() {
  let stats = Stats::calc(&[1]);
  assert_eq!(1, stats.min);
  assert_eq!(1, stats.max);
  assert_eq!(1, stats.count);
  assert_eq!(1., stats.avarage);
}

#[test]
fn stats_calc_returns_stats_for_two_numbers_in_order() {
  let stats = Stats::calc(&[1, 2]);
  assert_eq!(1, stats.min);
  assert_eq!(2, stats.max);
  assert_eq!(2, stats.count);
  assert_eq!(1.5, stats.avarage);
}

#[test]
fn stats_calc_returns_stats_for_two_numbers_in_reverse_order() {
  let stats = Stats::calc(&[2, 1]);
  assert_eq!(1, stats.min);
  assert_eq!(2, stats.max);
  assert_eq!(2, stats.count);
  assert_eq!(1.5, stats.avarage);
}

#[test]
fn stats_calc_returns_stats_for_three_numbers_in_order() {
  let stats = Stats::calc(&[1, 2, 3]);
  assert_eq!(1, stats.min);
  assert_eq!(3, stats.max);
  assert_eq!(3, stats.count);
  assert_eq!(2., stats.avarage);
}

#[test]
fn stats_calc_returns_stats_for_negative_numbers() {
  let stats = Stats::calc(&[1, -2, 3]);
  assert_eq!(-2, stats.min);
  assert_eq!(3, stats.max);
  assert_eq!(3, stats.count);
  assert_eq!((1. - 2. + 3.)/3., stats.avarage);
}

#[test]
fn stats_calc_returns_stats_for_kata_numbers() {
  let stats = Stats::calc(&[6, 9, 15, -2, 92, 11]);
  assert_eq!(-2, stats.min);
  assert_eq!(92, stats.max);
  assert_eq!(6, stats.count);
  assert_eq!((6. + 9. + 15. - 2. + 92. + 11.)/6., stats.avarage);
}
