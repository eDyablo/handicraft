using System.Collections.Generic;

namespace dnmcprgrmng.mztn.brtfrc
{
    public class Solution
    {
        class Memo : Dictionary<int, bool> { }

        public bool CanSum(int target, int[] numbers)
        {
            return CanSum(target, numbers, 0, new Memo());
        }

        bool CanSum(int target, int[] numbers, int selected, Memo memo)
        {
            if (memo.ContainsKey(target)) return memo[target];
            if (target == 0) return true;
            if (target < 0) return false;
            if (selected >= numbers.Length) return false;
            foreach (var number in numbers)
            {
                if (CanSum(target - number, numbers, 0, memo))
                {
                    memo[target] = true;
                    return true;
                }
            }
            memo[target] = false;
            return false;
        }
    }
}
