#include "Vect3.hpp"

#include <cmath>

// ========================================================================== //
//                                  Additions                                 //
// ========================================================================== //

Vect3	Vect3::operator+(const Vect3 &other) const
{
	Vect3	tmp(*this);

	tmp.x += other.x;
	tmp.y += other.y;

	return (tmp);
}

Vect3	&Vect3::operator+=(const Vect3 &other)
{
	x += other.x;
	y += other.y;

	return (*this);
}

// ========================================================================== //
//                                Subtractions                                //
// ========================================================================== //

Vect3	Vect3::operator-(const Vect3 &other) const
{
	Vect3	tmp(*this);

	tmp.x -= other.x;
	tmp.y -= other.y;

	return (tmp);
}

Vect3	&Vect3::operator-=(const Vect3 &other)
{
	x -= other.x;
	y -= other.y;

	return (*this);
}

// ========================================================================== //
//                               Multiplications                              //
// ========================================================================== //

Vect3	Vect3::operator*(const Vect3 &other) const
{
	Vect3	tmp(*this);

	tmp.x *= other.x;
	tmp.y *= other.y;

	return (tmp);
}

Vect3	Vect3::operator*(const f32 scalar) const
{
	Vect3	tmp(*this);

	tmp.x *= scalar;
	tmp.y *= scalar;

	return (tmp);
}

Vect3	&Vect3::operator*=(const Vect3 &other)
{
	x *= other.x;
	y *= other.y;

	return (*this);
}

Vect3	&Vect3::operator*=(const f32 scalar)
{
	x *= scalar;
	y *= scalar;

	return (*this);
}

// ========================================================================== //
//                                  Divisons                                  //
// ========================================================================== //

Vect3	Vect3::operator/(const Vect3 &other) const
{
	Vect3	tmp(*this);

	tmp.x /= other.x;
	tmp.y /= other.y;

	return (tmp);
}

Vect3	Vect3::operator/(const f32 scalar) const
{
	Vect3	tmp(*this);

	tmp.x /= scalar;
	tmp.y /= scalar;

	return (tmp);
}

Vect3	&Vect3::operator/=(const Vect3 &other)
{
	x /= other.x;
	y /= other.y;

	return (*this);
}

Vect3	&Vect3::operator/=(const f32 scalar)
{
	x /= scalar;
	y /= scalar;

	return (*this);
}

// ========================================================================== //
//                                 Comparisons                                //
// ========================================================================== //

bool	Vect3::operator==(const Vect3 &other) const
{
	return (x == other.x && y == other.y);
}

bool	Vect3::operator!=(const Vect3 &other) const
{
	return (x != other.x || y != other.y);
}

// ========================================================================== //
//                                   Methods                                  //
// ========================================================================== //

f32		Vect3::dot(const Vect3 &other) const
{
	return (x * other.x + y * other.y + z * other.z);
}

f32		Vect3::length() const
{
	return (std::sqrt(x * x + y * y + z * z));
}

Vect3	Vect3::normalized() const
{
	const f32	len = length();

	return (len != 0 ? *this / len : *this);
}

Vect3	Vect3::cross(const Vect3 &other) const
{
	return (Vect3(y * other.z - z * other.y,
				  z * other.x - x * other.z,
				  x * other.y - y * other.x));
}

// ========================================================================== //
//                                    Misc                                    //
// ========================================================================== //

std::ostream	&operator<<(std::ostream &out, const Vect3 &other)
{
	out << "[" << other.x << ',' << other.y << ',' << other.z << ']';
	return (out);
}
