using NUnit.Framework;

namespace mcrsft.cplfrgs
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
            Assert.That(solution.FindLongestDistance(new[] { 2, 6, 8, 5 }), Is.EqualTo(3));
            Assert.That(solution.FindLongestDistance(new[] { 1, 5, 5, 2, 6 }), Is.EqualTo(4));
            Assert.That(solution.FindLongestDistance(new[] { 1, 1 }), Is.EqualTo(2));
        }
    }
}
