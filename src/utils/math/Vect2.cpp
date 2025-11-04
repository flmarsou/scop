#include "Vect2.hpp"

#include <cmath>

// ========================================================================== //
//                                  Additions                                 //
// ========================================================================== //

Vect2	Vect2::operator+(const Vect2 &other) const
{
	Vect2	tmp(*this);

	tmp.x += other.x;
	tmp.y += other.y;

	return (tmp);
}

Vect2	&Vect2::operator+=(const Vect2 &other)
{
	x += other.x;
	y += other.y;

	return (*this);
}

// ========================================================================== //
//                                Subtractions                                //
// ========================================================================== //

Vect2	Vect2::operator-(const Vect2 &other) const
{
	Vect2	tmp(*this);

	tmp.x -= other.x;
	tmp.y -= other.y;

	return (tmp);
}

Vect2	&Vect2::operator-=(const Vect2 &other)
{
	x -= other.x;
	y -= other.y;

	return (*this);
}

// ========================================================================== //
//                               Multiplications                              //
// ========================================================================== //

Vect2	Vect2::operator*(const Vect2 &other) const
{
	Vect2	tmp(*this);

	tmp.x *= other.x;
	tmp.y *= other.y;

	return (tmp);
}

Vect2	Vect2::operator*(const f32 scalar) const
{
	Vect2	tmp(*this);

	tmp.x *= scalar;
	tmp.y *= scalar;

	return (tmp);
}

Vect2	&Vect2::operator*=(const Vect2 &other)
{
	x *= other.x;
	y *= other.y;

	return (*this);
}

Vect2	&Vect2::operator*=(const f32 scalar)
{
	x *= scalar;
	y *= scalar;

	return (*this);
}

// ========================================================================== //
//                                  Divisons                                  //
// ========================================================================== //

Vect2	Vect2::operator/(const Vect2 &other) const
{
	Vect2	tmp(*this);

	tmp.x /= other.x;
	tmp.y /= other.y;

	return (tmp);
}

Vect2	Vect2::operator/(const f32 scalar) const
{
	Vect2	tmp(*this);

	tmp.x /= scalar;
	tmp.y /= scalar;

	return (tmp);
}

Vect2	&Vect2::operator/=(const Vect2 &other)
{
	x /= other.x;
	y /= other.y;

	return (*this);
}

Vect2	&Vect2::operator/=(const f32 scalar)
{
	x /= scalar;
	y /= scalar;

	return (*this);
}

// ========================================================================== //
//                                 Comparisons                                //
// ========================================================================== //

bool	Vect2::operator==(const Vect2 &other) const
{
	return (x == other.x && y == other.y);
}

bool	Vect2::operator!=(const Vect2 &other) const
{
	return (x != other.x || y != other.y);
}

// ========================================================================== //
//                                   Methods                                  //
// ========================================================================== //

f32		Vect2::dot(const Vect2 &other) const
{
	return (x * other.x + y * other.y);
}

f32		Vect2::length() const
{
	return (std::sqrt(x * x + y * y));
}

Vect2	Vect2::normalized() const
{
	const f32	len = length();

	return (len != 0 ? *this / len : *this);
}

// ========================================================================== //
//                                    Misc                                    //
// ========================================================================== //

std::ostream	&operator<<(std::ostream &out, const Vect2 &other)
{
	out << "[" << other.x << ',' << other.y << ']';
	return (out);
}
