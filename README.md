# Humanoid Robot Wrestling Controller Example

[![webots.cloud - Competition](https://img.shields.io/badge/webots.cloud-Competition-007ACC)][1]

## Alice C controller

Minimalist C controller example for the [Humanoid Robot Wrestling Competition](https://github.com/cyberbotics/wrestling).
Demonstrates how to play a simple motion file. We use the [motion.h library](https://cyberbotics.com/doc/reference/motion?tab-language=c) from Webots.

Here is the [participant.c](./controllers/participant/participant.c) file:

``` C
#include <webots/robot.h>
#include <webots/utils/motion.h>

int main() {
  // Robot initialization
  wb_robot_init();

  // Motion files are text files containing pre-recorded positions of the robot's joints
  const WbMotionRef hand_wave = wbu_motion_new("../motions/HandWave.motion");
  // We play the hand-waving motion on loop
  wbu_motion_set_loop(hand_wave, true);
  wbu_motion_play(hand_wave);

  const int time_step = wb_robot_get_basic_time_step();
  // Mandatory function to make the simulation run
  while(wb_robot_step(time_step) != -1);

  // Robot cleanup
  wb_robot_cleanup();
  return 0;
}
```

[Bob](https://github.com/cyberbotics/wrestling-bob) is a more advanced robot controller able to win against Alice.

[1]: https://webots.cloud/run?version=R2022b&url=https%3A%2F%2Fgithub.com%2Fcyberbotics%2Fwrestling%2Fblob%2Fmain%2Fworlds%2Fwrestling.wbt&type=competition "Leaderboard"
