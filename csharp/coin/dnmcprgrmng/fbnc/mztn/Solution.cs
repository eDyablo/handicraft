using System.Collections.Generic;

namespace dnmcprgrmng.fbnc.mztn
{
    public class Solution
    {
        IDictionary<int, long> memo = new Dictionary<int, long>();

        public long fibo(int n)
        {
            if (memo.ContainsKey(n)) return memo[n];
            memo[n] = n < 3 ? 1 : fibo(n - 1) + fibo(n - 2);
            return memo[n];
        }
    }
}
