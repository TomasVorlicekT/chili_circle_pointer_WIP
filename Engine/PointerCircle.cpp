#include "PointerCircle.h"

PointerCircle::PointerCircle(int radius_in, int thickness_in, Vec centre_in)
	:
	radius(radius_in),
	thickness(thickness_in),
	centre(centre_in)
{
}


void PointerCircle::DrawPointerCircle(Graphics& gfx)
{
	if (centre.x - radius - thickness > 0 &&
		centre.x + radius + thickness < gfx.ScreenWidth &&
		centre.y - radius - thickness > 0 &&
		centre.y + radius + thickness < gfx.ScreenHeight
		)
	{
		gfx.DrawCircle(centre, radius, thickness, c);
	}
}

void PointerCircle::UpdateTopology(int radius_in, int thickness_in, const Vec& centre_in)
{
	radius = radius_in > 0 ? radius_in : 1;
	thickness = thickness_in > 0 ? thickness_in : 1;
	centre = centre_in;
}
