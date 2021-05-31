module.exports = {
  canSum: function (target, numbers, memo = {}) {
    const table = Array(target + 1).fill(false)
    table[0] = true
    for (let subTarget = 0; subTarget <= target; ++subTarget) {
      if (table[subTarget]) {
        numbers.forEach(number => {
          const sum = subTarget + number
          if (sum <= target) table[sum] = true
        });
      }
    }
    return table[target]
  }
}
