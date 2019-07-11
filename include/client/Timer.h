#pragma once

#include <functional>

struct Timer {
  char filler[48];
  std::function<int()> fn; // 48

  Timer(float, std::function<int()>);
  void advanceTime(float);
  void advanceTimeQuickly();
  float getAlpha() const;
  float getLastTimestep();
  unsigned getTicks() const;
  float getTime() const;
  float getTimeScale() const;
  int resetTimePassed();
  void setTimeScale(float);
  void skipTime();
  int stepTick(int);
  bool stepping() const;
  ~Timer();
};