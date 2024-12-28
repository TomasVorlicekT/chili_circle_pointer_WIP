#include "PointerRect.h"

PointerRect::PointerRect(int width_in, int height_in, int thickness_in, const Vec& pos_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in),
	thickness(thickness_in)
{
	orientationAngle = 0; // orientation is by default in the horizontal direction
}

PointerRect::PointerRect(int width_in, int height_in, int thickness_in, int orientationAngle_in, const Vec& pos_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in),
	thickness(thickness_in),
	orientationAngle(orientationAngle_in)
{
}

void PointerRect::DrawPointerRect(Graphics& gfx)
{
	if (pos.x - thickness > 0 &&
		pos.x + width + thickness < gfx.ScreenWidth &&
		pos.y - thickness > 0 &&
		pos.y + height + thickness < gfx.ScreenHeight
		)
	{
		gfx.DrawRect(pos, orientationAngle, width, height, thickness, c);
	}
}

void PointerRect::UpdateTopology(int width_in, int height_in, int thickness_in, const Vec& pos_in)
{
	pos = pos_in;
	width = (width_in > 0) ? width_in : 1;
	height = (height_in > 0) ? height_in : 1;
	thickness = thickness_in > 0 ? thickness_in : 1;
}

void PointerRect::UpdateOrientation(int angle)
{
	orientationAngle = angle;
}
