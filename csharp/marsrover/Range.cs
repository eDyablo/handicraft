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
      var fields = text.Split(" ", 2);
      return new Range
      {
        X = int.Parse(fields[0]),
        Y = int.Parse(fields[1]),
      };
    }
  }
}
