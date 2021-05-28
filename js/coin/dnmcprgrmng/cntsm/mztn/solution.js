module.exports = {
  countSum: function (target, numbers, selected = 0, memo = {}) {
    const key = target * numbers.length + selected
    if (key in memo) return memo[key]
    if (target === 0) return 1
    if (target < 0) return 0
    if (selected >= numbers.length) return 0
    memo[key] = this.countSum(target - numbers[selected], numbers, selected, memo) +
      this.countSum(target, numbers, selected + 1, memo)
    return memo[key]
  }
}
