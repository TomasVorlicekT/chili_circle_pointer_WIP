#ifndef POINTERCIRCLE_H
#define POINTERCIRCLE_H

#include "Colors.h"
#include "Graphics.h"

class PointerCircle
{
public:
	PointerCircle() = default;
	PointerCircle(int radius_in, int thickness_in);
	void DrawPointerCircle(Graphics& gfx, Vec& centre);

private:
	int radius{};
	int thickness{};
	const Color c{Colors::Green};

};

#endif