package cntsm.brtfrc

class Solution {

  int countSum(int target, numbers, int selected=0) {
    if (target == 0) { return 1 }
    if (target < 0) { return 0 }
    if (selected >= numbers.size) { return 0 }
    return countSum(target - numbers[selected], numbers, selected) +
        countSum(target, numbers, selected + 1)
  }

}
