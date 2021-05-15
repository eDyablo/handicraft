using NUnit.Framework;

namespace dnmcprgrmng.cntsm.brtfrc
{
    public class Test
    {
        private Solution solution;

        [SetUp]
        public void ForEachTest()
        {
            solution = new Solution();
        }

        [TestCase(0, new int[] { 1, 2, 3 }, 1)]
        [TestCase(1, new int[] { 2 }, 0)]
        [TestCase(1, new int[] { 1 }, 1)]
        [TestCase(2, new int[] { 1, 2 }, 2)]
        [TestCase(3, new int[] { 1, 2, 3 }, 3)]
        [TestCase(10, new int[] { 1, 5, 10, 25 }, 4)]
        [TestCase(25, new int[] { 1, 5, 10, 25 }, 13)]
        [TestCase(7, new int[] { 7, 4, 3, 2 }, 3)]
        public void Correctness(int target, int[] numbers, int expected)
        {
            Assert.That(solution.CountSum(target, numbers), Is.EqualTo(expected));
        }
    }
}
