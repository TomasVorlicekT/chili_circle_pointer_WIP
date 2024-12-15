#ifndef VEC_H
#define VEC_H

class Vec
{
public:
	Vec() = default;
	Vec(int x_in, int y_in);
	int GetX() const;
	int GetY() const;
	void Update(const Vec& newCentre);
	void Update( int xUpdate, int yUpdate);

private:
	int x{};
	int y{};
};

#endif
