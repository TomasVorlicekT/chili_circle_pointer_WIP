#include "PointerRect.h"

PointerRect::PointerRect(int width_in, int height_in, const Vec& pos_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in)
{
	orientationAngle = 0; // orientation is by default in the horizontal direction
}

void PointerRect::DrawPointerRect(Graphics& gfx)
{
	if (pos.x - thickness > 0 &&
		pos.x + width + thickness < gfx.ScreenWidth &&
		pos.y - thickness > 0 &&
		pos.y + height + thickness < gfx.ScreenHeight
		)
	{
		;
	}
}

void PointerRect::UpdateTopology(int width_in, int height_in, int thickness_in, const Vec& pos_in)
{
}

void PointerRect::UpdateOrientation(int angle)
{
}

