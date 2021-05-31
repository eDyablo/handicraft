const assert = require('assert')
const solution = require('./solution.js')

assert.strictEqual(solution.countSum(0, [1, 2, 3]), 1)
assert.strictEqual(solution.countSum(1, [1]), 1)
assert.strictEqual(solution.countSum(1, [2]), 0)
assert.strictEqual(solution.countSum(2, [1, 2]), 2)
assert.strictEqual(solution.countSum(3, [1, 2, 3]), 3)
assert.strictEqual(solution.countSum(6, [1, 5]), 2)
assert.strictEqual(solution.countSum(9, [5]), 0)
assert.strictEqual(solution.countSum(10, [1, 5, 10, 25]), 4)
assert.strictEqual(solution.countSum(25, [1, 5, 10, 25]), 13)
assert.strictEqual(solution.countSum(7, [7, 4, 3, 2]), 3)

assert.strictEqual(solution.countSum(1000, Array(10).fill(3)), 0)