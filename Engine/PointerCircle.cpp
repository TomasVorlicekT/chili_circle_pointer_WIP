#include "PointerCircle.h"

PointerCircle::PointerCircle(int radius_in, int thickness_in)
	:
	radius(radius_in),
	thickness(thickness_in)
{
}

void PointerCircle::DrawPointerCircle(Graphics& gfx, Vec& centre)
{
	gfx.DrawCircle(centre, radius, thickness, c);
}
