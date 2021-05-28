module.exports = {
  countSum: function (target, numbers) {
    let table = Array(target + 1).fill(0)
    table[0] = 1
    numbers.forEach(number => {
      for (let amount = number; amount <= target; ++amount) {
        table[amount] += table[amount - number]
      }
    })
    return table[target]
  }
}
