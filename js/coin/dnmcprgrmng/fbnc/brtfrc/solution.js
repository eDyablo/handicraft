module.exports = {
  fibonnaci: function (number) {
    if (number == 0) return 0
    if (number < 3) return 1
    return this.fibonnaci(number - 1) + this.fibonnaci(number - 2)
  }
}
