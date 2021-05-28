module.exports = {
  canSum: function (target, numbers, memo = {}) {
    if (target in memo) return memo[target]
    if (target === 0) return true
    if (target < 0) return false
    for (let i = 0; i < numbers.length; ++i) {
      if (this.canSum(target - numbers[i], numbers, memo)) {
        memo[target] = true
        return memo[target]
      }
    }
    memo[target] = false
    return memo[target]
  }
}
