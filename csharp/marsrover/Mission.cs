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
        CommandRover(command);
      }
    }

    private void CommandRover(char command)
    {
      switch (command)
      {
        case 'R': SpinRoverRight(); break;
        case 'L': SpinRoverLeft(); break;
        case 'M': MoveRover(); break;
      }
    }

    private void MoveRover()
    {
      var x = int.Parse(rover[0]);
      if (rover[2] == "E")
      {
        rover[0] = (x + 1).ToString();
      }
      else if (rover[2] == "W")
      {
        rover[0] = (x - 1).ToString();
      }
    }

    private void SpinRoverRight()
    {
      switch (rover[2])
      {
        case "N": rover[2] = "E"; break;
        case "E": rover[2] = "S"; break;
        case "S": rover[2] = "W"; break;
        case "W": rover[2] = "N"; break;
      }
    }

    private void SpinRoverLeft()
    {
      switch (rover[2])
      {
        case "N": rover[2] = "W"; break;
        case "W": rover[2] = "S"; break;
        case "S": rover[2] = "E"; break;
        case "E": rover[2] = "N"; break;
      }
    }

    private void ReportRover()
    {
      result.Add(string.Join(" ", rover));
    }
  }
}
