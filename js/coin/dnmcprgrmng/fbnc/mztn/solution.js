module.exports = {
  fibonnaci: function (number, memo = {}) {
    if (number in memo) return memo[number]
    if (number == 0) return 0
    if (number < 3) return 1
    memo[number] = this.fibonnaci(number - 1, memo) + this.fibonnaci(number - 2, memo)
    return memo[number]
  }
}
