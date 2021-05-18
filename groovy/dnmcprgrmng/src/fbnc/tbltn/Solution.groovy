/* groovylint-disable NoDef, VariableTypeRequired */
package fbnc.tbltn

import groovy.transform.CompileDynamic

/**
 * Solution
 */
@CompileDynamic
class Solution {

  long fibo(int n) {
    final table = [0L] * (n + 2)
    table[1] = 1
    for (int i = 1; i < n; ++i) {
      table[i + 1] += table[i]
      table[i + 2] += table[i]
    }
    return table[n]
  }

}
