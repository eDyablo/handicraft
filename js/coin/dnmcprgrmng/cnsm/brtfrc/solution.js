module.exports = {
  canSum: function (target, numbers) {
    if (target === 0) return true
    if (target < 0) return false
    for (let i = 0; i < numbers.length; ++i) {
      if (this.canSum(target - numbers[i], numbers)) return true
    }
    return false
  }
}
