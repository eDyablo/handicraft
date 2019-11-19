package marsrover;

import java.util.ArrayList;
import java.util.List;

public class Mission {
  public int xRange;
  public int yRange;
  public String[] plan;
  public List<String> result = new ArrayList<String>();
  private String[] rover;
  private int step;

	public void explore() {
    startMission();
    if (missionContinues()) {
      determineRange();
    }
    while (missionContinues()) {
      landRover();
      if (missionContinues()) {
        commandRover();
      }
      reportRover();
    }
  }

  private void startMission() {
    step = 0;
  }

  private boolean missionContinues() {
    return step < plan.length;
  }

  private void landRover() {
    rover = plan[step].split(" ");
    step++;
  }

  private void reportRover() {
    result.add(String.join(" ", rover));
  }
  
  private void determineRange() {
    String[] range = plan[step].split(" ");
    xRange = Integer.parseInt(range[0]);
    yRange = Integer.parseInt(range[1]);
    step++;
  }

  private void commandRover() {
    for (Character command : plan[step].toCharArray()) {
      commandRover(command);
    }
    step++;
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
