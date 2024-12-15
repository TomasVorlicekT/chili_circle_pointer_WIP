#include "Vec.h"

Vec::Vec(int x_in, int y_in)
	:
	x(x_in),
	y(y_in)
{
}

int Vec::GetX() const
{
	return x;
}

int Vec::GetY() const
{
	return y;
}

void Vec::Update(const Vec& newCentre)
{
	x = newCentre.GetX();
	y = newCentre.GetY();
}

void Vec::Update(int xUpdate, int yUpdate)
{
	x = xUpdate;
	y = yUpdate;
}
