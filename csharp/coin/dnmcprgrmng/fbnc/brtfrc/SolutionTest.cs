using NUnit.Framework;

namespace dnmcprgrmng.fbnc.brtfrc
{
    public class Tests
    {
        Solution solution;

        [SetUp]
        public void Setup()
        {
            solution = new Solution();
        }

        [TestCase(1, 1)]
        [TestCase(2, 1)]
        [TestCase(3, 2)]
        [TestCase(4, 3)]
        [TestCase(5, 5)]
        [TestCase(6, 8)]
        [TestCase(7, 13)]
        [TestCase(8, 21)]
        [TestCase(9, 34)]
        public void Correctness(int n, int expected)
        {
            Assert.That(solution.fibo(n), Is.EqualTo(expected));
        }
    }
}