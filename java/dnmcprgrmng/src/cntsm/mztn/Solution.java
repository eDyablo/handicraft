package cntsm.mztn;

import java.util.HashMap;
import java.util.Map;

public class Solution {
  Map<Long, Integer> memo;

  public int countSum(int target, int[] numbers) {
    memo = new HashMap<Long, Integer>();
    return countSum(target, numbers, 0);
  }

  int countSum(int target, int[] numbers, int selected) {
    long key = target * numbers.length + selected;
    if (memo.containsKey(key))
      return memo.get(key);
    if (target == 0)
      return 1;
    if (target < 0)
      return 0;
    if (selected >= numbers.length)
      return 0;
    memo.put(key, countSum(target - numbers[selected], numbers, selected) + countSum(target, numbers, selected + 1));
    return memo.get(key);
  }
}
