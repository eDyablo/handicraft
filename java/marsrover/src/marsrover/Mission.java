package marsrover;

import java.util.ArrayList;
import java.util.List;

public class Mission {
  public int xRange;
  public int yRange;
  public List<String> result = new ArrayList<String>();
  private String[] rover;

	public void explore(String[] plan) {
    if (plan.length > 0) {
      determineRange(plan);
      if (plan.length > 1) {
        landRover(plan[1]);
        if (plan.length > 2) {
          for (Character command : plan[2].toCharArray()) {
            commandRover(command);
          }
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
  
  private void determineRange(String[] plan) {
    String[] range = plan[0].split(" ");
    xRange = Integer.parseInt(range[0]);
    yRange = Integer.parseInt(range[1]);
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
      rover[2] = "E";
    } else if (rover[2].equals("E")) {
      rover[2] = "S";
    } else if (rover[2].equals("S")) {
      rover[2] = "W";
    } else if (rover[2].equals("W")) {
      rover[2] = "N";
    }
  }

  private void spinRoverRight() {
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

  private void moveRover() {
    int x = Integer.parseInt(rover[0]);
    int y = Integer.parseInt(rover[1]);
    if (rover[2].equals("N")) {
      ++y;
    } else if (rover[2].equals("S")) {
      --y;
    } else if (rover[2].equals("W")) {
      ++x;
    } else if (rover[2].equals("E")) {
      --x;
    }
    rover[0] = String.valueOf(x);
    rover[1] = String.valueOf(y);
  }
}
