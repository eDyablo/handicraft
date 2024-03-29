const assert = require('assert')
const solution = require('./solution.js')

assert.strictEqual(solution.canSum(0, [1, 2, 3]), true)
assert.strictEqual(solution.canSum(1, [1]), true)
assert.strictEqual(solution.canSum(1, [2]), false)
assert.strictEqual(solution.canSum(2, [3, 2]), true)
assert.strictEqual(solution.canSum(7, [2, 3]), true)
assert.strictEqual(solution.canSum(7, [5, 3, 4, 7]), true)
assert.strictEqual(solution.canSum(7, [2, 4]), false)
assert.strictEqual(solution.canSum(8, [2, 3, 5]), true)
