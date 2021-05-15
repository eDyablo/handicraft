namespace dnmcprgrmng.cntsm.tbltn
{
    public class Solution
    {
        public int CountSum(int target, int[] numbers)
        {
            var table = new int[target + 1];
            table[0] = 1;
            foreach (var number in numbers)
            {
                for (var subTarget = number; subTarget <= target; ++subTarget)
                {
                    table[subTarget] += table[subTarget - number];
                }
            }
            return table[target];
        }
    }
}
