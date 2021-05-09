using System;

namespace dnmcprgrmng.fbnc.brtfrc
{
    public class Solution
    {
        public int fibo(int n)
        {
            return n < 3 ? 1 : fibo(n - 1) + fibo(n - 2);
        }
    }
}
