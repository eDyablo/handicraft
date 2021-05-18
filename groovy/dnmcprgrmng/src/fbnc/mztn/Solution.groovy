/* groovylint-disable FieldTypeRequired, NoDef */
package fbnc.mztn

import groovy.transform.CompileDynamic

/**
 * Solution
 */
@CompileDynamic
class Solution {

  final memo = [:]

  long fibo(int n) {
    if (memo.containsKey(n)) { return memo[n] }
    if (n < 1) { return 0 }
    if (n < 3) { return 1 }
    memo[n] = fibo(n - 1) + fibo(n - 2)
    return memo[n]
  }

}
