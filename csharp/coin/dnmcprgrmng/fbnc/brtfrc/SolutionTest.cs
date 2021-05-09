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

        [Test]
        public void Correctness()
        {
            Assert.That(solution.fibo(1), Is.EqualTo(1));
            Assert.That(solution.fibo(2), Is.EqualTo(1));
            Assert.That(solution.fibo(3), Is.EqualTo(2));
            Assert.That(solution.fibo(4), Is.EqualTo(3));
            Assert.That(solution.fibo(5), Is.EqualTo(5));
            Assert.That(solution.fibo(6), Is.EqualTo(8));
            Assert.That(solution.fibo(7), Is.EqualTo(13));
            Assert.That(solution.fibo(8), Is.EqualTo(21));
            Assert.That(solution.fibo(9), Is.EqualTo(34));
        }
    }
}