using System;

namespace dnmcprgrmng.cnsm.brtfrc
{
    public class Solution
    {
        internal bool CanSum(int target, int[] numbers, int selected = 0)
        {
            if (target == 0) return true;
            if (target < 0) return false;
            if (selected >= numbers.Length) return false;
            return CanSum(target - numbers[selected], numbers, selected) || CanSum(target, numbers, selected + 1);
        }
    }
}
