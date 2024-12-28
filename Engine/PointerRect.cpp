#define _USE_MATH_DEFINES 

#include "PointerRect.h"
#include <cmath>
#include <algorithm>
#include <vector>

PointerRect::PointerRect(int width_in, int height_in, int thickness_in, const Vec& pos_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in),
	thickness(thickness_in)
{
	orientationAngle = 0; // orientation is by default in the horizontal direction
}

// Constructor for the full object initialization within std::vector
PointerRect::PointerRect(int width_in, int height_in, int thickness_in, int orientationAngle_in, const Vec& pos_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in),
	thickness(thickness_in),
	orientationAngle(orientationAngle_in)
{
}

bool PointerRect::IsWithinBoundaries() const
{
	// How about this: let's get the outermost points of the rectangles (in Vec object) and get the max/min values
	// if none of these values are outside the boundary we return true

	// using trigonometry to get the outer points of the rectangle
	Vec vecA (pos.x - std::sin((45 - orientationAngle)*M_PI / 180) * sqrt(2) * thickness, pos.y + std::cos((45 - orientationAngle) * M_PI / 180) * sqrt(2) * thickness);

	Vec vecB(float(vecA.x + (width + 2 * thickness) * std::cos((orientationAngle)*M_PI / 180)), float(vecA.y - (width + 2 * thickness) * std::sin((orientationAngle)*M_PI / 180)));

	Vec vecC(float(vecB.x - (height + 2 * thickness) * std::sin((orientationAngle)*M_PI / 180)), float(vecB.y - (height + 2 * thickness) * std::cos((orientationAngle)*M_PI / 180)));

	Vec vecD(float(vecC.x - (width + 2 * thickness) * std::cos((orientationAngle)*M_PI / 180)), float(vecC.y + (width + 2 * thickness) * std::sin((orientationAngle)*M_PI / 180)));

	const std::vector<float> xValues = { vecA.x, vecB.x, vecC.x, vecD.x };
	const std::vector<float> yValues = { vecA.y, vecB.y, vecC.y, vecD.y };

	// the minmax_element return a std::pair of iterators, which are basically pointers, so we have to dereference them when it comes to value comparisons
	const auto [min_X, max_X] = std::minmax_element(std::begin(xValues), std::end(xValues));
	const auto [min_Y, max_Y] = std::minmax_element(std::begin(yValues), std::end(yValues));

	if (
		*min_X > 0 &&
		*max_X < (Graphics::ScreenWidth - 1) &&
		*min_Y > 0 &&
		*max_Y < (Graphics::ScreenHeight - 1)
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PointerRect::DrawPointerRect(Graphics& gfx)
{
	if (IsWithinBoundaries())
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


