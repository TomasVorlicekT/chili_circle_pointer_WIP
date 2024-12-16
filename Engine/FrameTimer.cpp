#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	last = std::chrono::steady_clock::now();
}

float FrameTimer::Mark()
{
	const auto oldTimePoint = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - oldTimePoint;
	return frameTime.count();
}
