#ifndef VEC_H
#define VEC_H

class Vec
{
public:
	Vec() = default;
	Vec(float x_in, float y_in);
	Vec operator+(const Vec& rhs) const;
	Vec& operator+=(const Vec& rhs);
	Vec operator*(float rhs) const;
	Vec& operator*=(float rhs);
	Vec operator-(const Vec& rhs) const;
	Vec& operator-=(const Vec& rhs);
	float GetLength() const;
	float GetLengthSq() const;
	Vec& Normalize();
	Vec GetNormalized() const;
	void Update(float x_in, float y_in);
public:
	float x;
	float y;
};

#endif
