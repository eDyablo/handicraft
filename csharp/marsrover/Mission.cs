using System.Collections.Generic;

namespace Marsrover
{
  public class Mission
  {
    public string[] Plan { private get; set; }

    public RangeType Range { get; private set; }

    public struct RangeType
    {
      public int X { get; set; }
      public int Y { get; set; }
    }

    public void Explore()
    {
      if (Plan != null && Plan.Length > 0)
      {
        ReadRange();
      }
    }

    public IEnumerable<string> Result
    {
      get
      {
        return new string[] {};
      }
    }

    private void ReadRange()
    {
      var fields = Plan[0].Split(" ", 2);
      Range = new RangeType
      {
        X = int.Parse(fields[0]),
        Y = int.Parse(fields[1]),
      };
    }
  }
}
