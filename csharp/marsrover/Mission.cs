using System.Collections.Generic;

namespace Marsrover
{
  public class Mission
  {
    private List<string> result = new List<string>();

    public string[] Plan { private get; set; }

    public RangeType Range { get; private set; }

    public IEnumerable<string> Result { get => result; }

    public struct RangeType
    {
      public int X { get; set; }
      public int Y { get; set; }
    }

    public string[] rover;

    public void Explore()
    {
      if (Plan != null && Plan.Length > 0)
      {
        ReadRange();
        if (Plan.Length > 1)
        {
          LandRover();
          if (Plan.Length > 2)
          {
            CommandRover();
          }
          ReportRover();
        }
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

    private void LandRover()
    {
      rover = Plan[1].Split(" ", 3);
    }

    private void CommandRover()
    {
      foreach (var command in Plan[2])
      {
        switch (command)
        {
          case 'R': rover[2] = "E"; break;
          case 'L': rover[2] = "W"; break;
          case 'M': MoveRover(); break;
        }
      }
    }

    private void MoveRover()
    {
      var x = int.Parse(rover[0]);
      rover[0] = (x + 1).ToString();
    }

    private void ReportRover()
    {
      result.Add(string.Join(" ", rover));
    }
  }
}
