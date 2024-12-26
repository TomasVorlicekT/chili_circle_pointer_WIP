#ifndef POINTERRECT_H
#define POINTERRECT_H

#include "Vec.h"
#include "Graphics.h"
#include "Colors.h"

class PointerRect
{
public:
	PointerRect() = default;
	PointerRect(int width_in, int height_in, const Vec& pos_in);
	void DrawPointerRect(Graphics& gfx);
	void UpdateTopology(int width_in, int height_in, int thickness_in, const Vec& pos_in);
	void UpdateOrientation(int orientation_in);

private:
	Vec pos;
	int orientationAngle;
	int width;
	int height;
	int thickness{ 1 };
	const Color c{ Colors::Blue };
};

#endif