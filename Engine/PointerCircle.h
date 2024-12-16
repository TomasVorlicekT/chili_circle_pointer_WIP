#ifndef POINTERCIRCLE_H
#define POINTERCIRCLE_H

#include "Colors.h"
#include "Graphics.h"
#include "Vec.h"

class PointerCircle
{
public:
	PointerCircle() = default;
	PointerCircle(int radius_in, int thickness_in, Vec centre_in);
	void DrawPointerCircle(Graphics& gfx);
	void UpdateTopology(int radius_in, int thickness_in, const Vec& centre_in);

private:
	Vec centre{};
	int radius{};
	int thickness{};
	const Color c{Colors::Green};
};

#endif