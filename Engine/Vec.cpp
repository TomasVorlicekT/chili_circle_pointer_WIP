#include "Vec.h"
#include <cmath>

Vec::Vec(float x_in, float y_in)
	:
	x(x_in),
	y(y_in)
{
}

Vec Vec::operator+(const Vec& rhs) const
{
	return Vec(x + rhs.x, y + rhs.y);
}

Vec& Vec::operator+=(const Vec& rhs)
{
	return *this = *this + rhs;
}

Vec Vec::operator*(float rhs) const
{
	return Vec(x * rhs, y * rhs);
}

Vec& Vec::operator*=(float rhs)
{
	return *this = *this * rhs;
}

Vec Vec::operator-(const Vec& rhs) const
{
	return Vec(x - rhs.x, y - rhs.y);
}

Vec& Vec::operator-=(const Vec& rhs)
{
	return *this = *this - rhs;
}

float Vec::GetLength() const
{
	return std::sqrt(GetLengthSq());
}

float Vec::GetLengthSq() const
{
	return x * x + y * y;
}

Vec& Vec::Normalize()
{
	return *this = GetNormalized();
}

Vec Vec::GetNormalized() const
{
	const float len = GetLength();
	if (len != 0.0f)
	{
		return *this * (1.0f / len);
	}
	return *this;
}

void Vec::Update(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
}
