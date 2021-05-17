package fbnc.mztn;

import java.util.HashMap;
import java.util.Map;

public class Solution {
  Map<Integer, Long> memo = new HashMap<Integer, Long>();

  public long fibo(int n) {
    if (memo.containsKey(n))
      return memo.get(n);
    if (n < 1)
      return 0;
    if (n < 3)
      return 1;
    memo.put(n, fibo(n - 1) + fibo(n - 2));
    return memo.get(n);
  }
}
