package fbnc.tbltn;

public class Solution {
  public long fibo(int n) {
    long[] table = new long[n + 2];
    table[1] = 1;
    for (int i = 0; i < n; ++i) {
      table[i + 1] += table[i];
      table[i + 2] += table[i];
    }
    return table[n];
  }
}
