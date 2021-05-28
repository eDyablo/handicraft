module.exports = {
  countSum: function (target, numbers, selected = 0) {
    if (target === 0) return 1
    if (target < 0) return 0
    if (selected >= numbers.length) return 0
    return this.countSum(target - numbers[selected], numbers, selected) +
      this.countSum(target, numbers, selected + 1)
  }
}
