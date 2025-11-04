#pragma once

# include "types.hpp"

# include <ostream>

struct	Vect3
{
	Vect3() : x(0.0f), y(0.0f), z(0.0f) {};
	Vect3(const f32 x, const f32 y, const f32 z) : x(x), y(y), z(z) {};

	// Additions
	Vect3	operator+(const Vect3 &other) const;
	Vect3	&operator+=(const Vect3 &other);

	// Subtractions
	Vect3	operator-(const Vect3 &other) const;
	Vect3	&operator-=(const Vect3 &other);

	// Multiplications
	Vect3	operator*(const Vect3 &other) const;
	Vect3	operator*(const f32 scalar) const;
	Vect3	&operator*=(const Vect3 &other);
	Vect3	&operator*=(const f32 scalar);

	// Divisons
	Vect3	operator/(const Vect3 &other) const;
	Vect3	operator/(const f32 scalar) const;
	Vect3	&operator/=(const Vect3 &other);
	Vect3	&operator/=(const f32 scalar);

	// Comparisons
	bool	operator==(const Vect3 &other) const;
	bool	operator!=(const Vect3 &other) const;

	// Methods
	/**
	 * Returns the dot product - a measure of how much two vectors point in the same direction.
	 * 
	 * Formula: (x₁ * x₂) + (y₁ * y₂) + (z₁ * z₂)
	 * 
	 * `> 0` -> vectors point in the same direction
	 * `< 0` -> vectors point in the opposite direction
	 * `= 0` -> vectors are perpendicular
	 */
	f32		dot(const Vect3 &other) const;

	/**
	 * Returns the magnitude (length) of the vector from the origin.
	 * 
	 * Formula: √(x² + y² + z²)
	 */
	f32		length() const;

	/**
	 * Returns a normalized (unit-length) copy of the vector with the same direction but a length of 1.
	 */
	Vect3	normalized() const;

	/**
	 * Returns the cross product of the vector with another.
	 * 
	 * Formula:
	 *	x = y₁ * z₂ - z₁ * y₂
	 *	y = z₁ * x₂ - x₁ * z₂
	 *	z = x₁ * y₂ - y₁ * x₂
	 */
	Vect3	cross(const Vect3 &other) const;

	f32	x;
	f32	y;
	f32	z;
};

std::ostream	&operator<<(std::ostream &out, const Vect3 &other);
