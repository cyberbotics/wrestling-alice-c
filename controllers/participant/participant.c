/*
 * Copyright 1996-2023 Cyberbotics Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
   Description: Minimalist controller example for the Robot Wrestling Tournament.
   Demonstrates how to play a simple motion file.
*/

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
