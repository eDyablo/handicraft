package cntsm.tbltn;

public class Solution {
  public int countSum(int target, int[] numbers) {
    int[] table = new int[target + 1];
    table[0] = 1;
    for (int number : numbers) {
      for (int amount = number; amount <= target; ++amount) {
        table[amount] += table[amount - number];
      }
    }
    return table[target];
  }
}
