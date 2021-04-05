using System;
using System.Collections.Generic;

namespace coin.prstg.cntsqrs
{
    struct Point
    {
        public float X;
        public float Y;
    }

    class Solution
    {
        static float Distance(Point first, Point second)
        {
            var deltaX = first.X - second.Y;
            var deltaY = first.X - second.Y;
            return (float)Math.Sqrt(deltaX * deltaX + deltaY * deltaY);
        }

        public bool IsSquare(Point[] points)
        {
            var distances = new HashSet<float>();
            var size = points.Length;
            for (var i = 0; i < size; ++i)
            {
                for (var j = i; j < size; ++j)
                {
                    if (i != j)
                    {
                        distances.Add(Distance(points[i], points[j]));
                    }
                }
            }
            return distances.Count == 2;
        }

        static Point[] Diagonal(Point first, Point second)
        {
            var mid = new Point { X = (first.X + second.X) / 2, Y = (first.Y + second.Y) / 2 };
            var delta = new Point { X = second.X - mid.X, Y = second.Y - mid.Y };
            return new[] { new Point { X = mid.X - delta.Y, Y = mid.Y + delta.X }, new Point { X = mid.X + delta.Y, Y = mid.Y - delta.X } };
        }

        public int CountSquares(Point[] points)
        {
            var lookup = new HashSet<Point>();
            foreach (var point in points)
            {
                lookup.Add(point);
            }
            int diagonalCount = 0;
            for (var i = 0; i < points.Length; ++i)
            {
                for (var j = i; j < points.Length; ++j)
                {
                    if (i != j)
                    {
                        var diag = Diagonal(points[i], points[j]);
                        if (lookup.Contains(diag[0]) && lookup.Contains(diag[1]))
                        {
                            ++diagonalCount;
                        }
                    }
                }
            }
            return diagonalCount / 2;
        }
    }
}
