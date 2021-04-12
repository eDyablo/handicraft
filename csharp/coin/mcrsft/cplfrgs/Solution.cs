using System;

namespace mcrsft.cplfrgs
{
    public class Solution
    {
        public int FindLongestDistance(int[] blocks)
        {
            int distance = 0;
            int left = 0, right = 1;
            for (; right < blocks.Length; ++right)
            {
                if (blocks[right] < blocks[right - 1])
                {
                    distance = Math.Max(distance, right - left);
                    while (left != right && blocks[left] < blocks[left + 1])
                    {
                        ++left;
                    }
                }
            }
            return Math.Max(distance, right - left);
        }
    }
}
