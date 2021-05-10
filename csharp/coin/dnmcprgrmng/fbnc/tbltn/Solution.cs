namespace dnmcprgrmng.fbnc.tbltn
{
    public class Solution
    {
        public long fibo(int n)
        {
            var table = new long[n + 2];
            table[1] = 1;
            for (int i = 1; i < n; ++i)
            {
                table[i + 1] += table[i];
                table[i + 2] += table[i];
            }
            return table[n];
        }
    }
}
