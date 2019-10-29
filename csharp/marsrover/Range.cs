using System.Collections.Generic;

namespace Marsrover
{
  public struct Range
  {
    public int X { get; set; }
    public int Y { get; set; }
  }

  public static class RangeConvertion
  {
    public static Range ToRange(this string text)
    {
      return ToRange(text.Split(" ", 2));
    }

    public static Range ToRange(this IList<string> fields)
    {
      return new Range
      {
        X = int.Parse(fields[0]),
        Y = int.Parse(fields[1]),
      };
    }
  }
}
