using NUnit.Framework;

namespace dnmcprgrmng.mztn.brtfrc
{
    public class SolutionTest
    {
        private Solution solution;

        [SetUp]
        public void BeforeEachTest()
        {
            solution = new Solution();
        }

        [TestCase(0, new int[] { 1, 2, 3 }, true)]
        [TestCase(1, new int[] { 1 }, true)]
        [TestCase(1, new int[] { 2 }, false)]
        [TestCase(2, new int[] { 3, 2 }, true)]
        [TestCase(7, new int[] { 2, 3 }, true)]
        [TestCase(7, new int[] { 5, 3, 4, 7 }, true)]
        [TestCase(7, new int[] { 2, 4 }, false)]
        [TestCase(8, new int[] { 2, 3, 5 }, true)]
        public void Correctness(int target, int[] numbers, bool expected)
        {
            Assert.That(solution.CanSum(target, numbers), Is.EqualTo(expected));
        }

        [TestCase(3000, new int[] { 7, 14 }, false)]
        public void Performance(int target, int[] numbers, bool expected)
        {
            Assert.That(solution.CanSum(target, numbers), Is.EqualTo(expected));
        }
    }
}
