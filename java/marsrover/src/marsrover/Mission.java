package marsrover;

import java.util.ArrayList;
import java.util.List;

public class Mission {
  public int xRange;
  public int yRange;
  public String[] plan;
  public List<String> result = new ArrayList<String>();
  private String[] rover;

	public void explore() {
    if (plan.length > 0) {
      determineRange();
      for (int i = 1; i < plan.length; ++i) {
        landRover(plan[i]);
        ++i;
        if (i < plan.length) {
          commandRover(plan[i]);
        }
        reportRover();
      }
    }
  }

  private void landRover(String position) {
    rover = position.split(" ");
  }

  private void reportRover() {
    result.add(String.join(" ", rover));
  }
  
  private void determineRange() {
    String[] range = plan[0].split(" ");
    xRange = Integer.parseInt(range[0]);
    yRange = Integer.parseInt(range[1]);
  }

  private void commandRover(String instructions) {
    for (Character command : instructions.toCharArray()) {
      commandRover(command);
    }
  }

  private void commandRover(Character command) {
    if (command == 'L') {
      spinRoverLeft();
    }
    if (command == 'R') {
      spinRoverRight();
    }
    if (command == 'M') {
      moveRover();
    }
  }

  private void spinRoverLeft() {
    if (rover[2].equals("N")) {
      rover[2] = "W";
    } else if (rover[2].equals("W")) {
      rover[2] = "S";
    } else if (rover[2].equals("S")) {
      rover[2] = "E";
    } else if (rover[2].equals("E")) {
      rover[2] = "N";
    }
  }

  private void spinRoverRight() {
    if (rover[2].equals("N")) {
      rover[2] = "E";
    } else if (rover[2].equals("E")) {
      rover[2] = "S";
    } else if (rover[2].equals("S")) {
      rover[2] = "W";
    } else if (rover[2].equals("W")) {
      rover[2] = "N";
    }
  }

  private void moveRover() {
    int x = Integer.parseInt(rover[0]);
    int y = Integer.parseInt(rover[1]);
    if (rover[2].equals("N")) {
      ++y;
    } else if (rover[2].equals("S")) {
      --y;
    } else if (rover[2].equals("E")) {
      ++x;
    } else if (rover[2].equals("W")) {
      --x;
    }
    rover[0] = String.valueOf(x);
    rover[1] = String.valueOf(y);
  }
}
