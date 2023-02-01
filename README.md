# Humanoid Robot Wrestling Controller Example

[![webots.cloud - Competition](https://img.shields.io/badge/webots.cloud-Competition-007ACC)][1]

## Alice C controller

Minimalist C controller example for the [Humanoid Robot Wrestling Competition](https://github.com/cyberbotics/wrestling).
Demonstrates how to play a simple motion file. We use the [motion.h library](https://cyberbotics.com/doc/reference/motion?tab-language=c) from Webots.
It could also be programmed in [Python](https://github.com/cyberbotics/wrestling-alice), [C++](https://github.com/cyberbotics/wrestling-alice-cpp) or [Java](https://github.com/cyberbotics/wrestling-alice-java).

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

To compile the C code, the [Dockerfile](./controllers/Dockerfile) must be updated; the environment variables needed for python can be removed and a call to `make` is needed to compile the source code:

``` Dockerfile
FROM cyberbotics/webots.cloud:R2023a-ubuntu20.04

# Environment variables needed for Webots
# https://cyberbotics.com/doc/guide/running-extern-robot-controllers#remote-extern-controllers
ENV LD_LIBRARY_PATH=${WEBOTS_HOME}/lib/controller:${LD_LIBRARY_PATH}
ARG WEBOTS_CONTROLLER_URL
ENV WEBOTS_CONTROLLER_URL=${WEBOTS_CONTROLLER_URL}

# Copies all the files of the controllers folder into the docker container
RUN mkdir -p /usr/local/webots-project/controllers
COPY . /usr/local/webots-project/controllers

WORKDIR /usr/local/webots-project/controllers/participant

# Compile controller
RUN make
    
ENTRYPOINT ["./participant"]
```

[Bob](https://github.com/cyberbotics/wrestling-bob) is a more advanced robot controller able to win against Alice.

[1]: https://webots.cloud/run?version=R2022b&url=https%3A%2F%2Fgithub.com%2Fcyberbotics%2Fwrestling%2Fblob%2Fmain%2Fworlds%2Fwrestling.wbt&type=competition "Leaderboard"
