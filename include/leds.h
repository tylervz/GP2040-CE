/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: Copyright (c) 2021 Jason Skuby (mytechtoybox.com)
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "AnimationStation.hpp"
#include "gamepad.hpp"
#include <vector>

#ifndef LEDS_BRIGHTNESS
#define LEDS_BRIGHTNESS 75
#endif

#ifndef LEDS_RAINBOW_CYCLE_TIME
#define LEDS_RAINBOW_CYCLE_TIME 40
#endif

#ifndef LEDS_CHASE_CYCLE_TIME
#define LEDS_CHASE_CYCLE_TIME 85
#endif

#ifndef LEDS_STATIC_COLOR_COLOR
#define LEDS_STATIC_COLOR_COLOR ColorRed
#endif

extern const std::vector<Pixel> pixels;

void configureAnimations();
AnimationHotkey animationHotkeys(Gamepad *gamepad);

class GPModule {
public:
  virtual void setup();
  virtual void loop();
  virtual void process(Gamepad *gamepad);
  absolute_time_t nextRunTime;
 	const uint32_t intervalMS = 10;
};
class LEDs : public GPModule {
public:
  void setup();
  void loop();
  void trySave();
  void process(Gamepad *gamepad);
	uint32_t frame[100];
};

#endif
