using NUnit.Framework;

namespace coin.prstg.cntsqrs
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
        public void IsSquareCorrect()
        {
            Assert.That(solution.IsSquare(new[] { new Point { X = 0, Y = 0 }, new Point { X = 0, Y = 2 }, new Point { X = 2, Y = 0 }, new Point { X = 2, Y = 2 } }));
        }

        [Test]
        public void CountSquaresCorrect()
        {
            Assert.That(solution.CountSquares(new[] { new Point { X = 0, Y = 0 }, new Point { X = 0, Y = 2 }, new Point { X = 2, Y = 0 }, new Point { X = 2, Y = 2 } }) == 1);
            Assert.That(solution.CountSquares(new[] { new Point { X = 0, Y = 0 }, new Point { X = 0, Y = 2 }, new Point { X = 0, Y = 3 }, new Point { X = 2, Y = 0 }, new Point { X = 3, Y = 0 }, new Point { X = 2, Y = 2 }, new Point { X = 3, Y = 3 } }) == 2);
        }
    }
}