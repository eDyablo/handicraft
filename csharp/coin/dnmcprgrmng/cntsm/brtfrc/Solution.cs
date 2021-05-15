namespace dnmcprgrmng.cntsm.brtfrc
{
    public class Solution
    {
        public int CountSum(int target, int[] numbers)
        {
            return CountSum(target, numbers, 0);
        }

        int CountSum(int target, int[] numbers, int selected)
        {
            if (target == 0) return 1;
            if (target < 0) return 0;
            if (selected >= numbers.Length) return 0;
            return CountSum(target - numbers[selected], numbers, selected) +
                CountSum(target, numbers, selected + 1);
        }
    }
}
