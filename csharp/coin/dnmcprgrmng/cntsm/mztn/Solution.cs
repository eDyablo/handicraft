using System.Collections.Generic;

namespace dnmcprgrmng.cntsm.mztn
{
    public class Solution
    {
        IDictionary<long, int> memo;

        public int CountSum(int target, int[] numbers)
        {
            memo = new Dictionary<long, int>();
            return CountSum(target, numbers, 0);
        }

        int CountSum(int target, int[] numbers, int selected)
        {
            var key = numbers.Length * target + selected;
            if (memo.ContainsKey(key)) return memo[key];
            if (target == 0) return 1;
            if (target < 0) return 0;
            if (selected >= numbers.Length) return 0;
            memo[key] = CountSum(target - numbers[selected], numbers, selected) +
                CountSum(target, numbers, selected + 1);
            return memo[key];
        }
    }
}
