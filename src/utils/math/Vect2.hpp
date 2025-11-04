#pragma once

# include "types.hpp"

# include <ostream>

struct	Vect2
{
	Vect2() : x(0.0f), y(0.0f) {};
	Vect2(const f32 x, const f32 y) : x(x), y(y) {};

	// Additions
	Vect2	operator+(const Vect2 &other) const;
	Vect2	&operator+=(const Vect2 &other);

	// Subtractions
	Vect2	operator-(const Vect2 &other) const;
	Vect2	&operator-=(const Vect2 &other);

	// Multiplications
	Vect2	operator*(const Vect2 &other) const;
	Vect2	operator*(const f32 scalar) const;
	Vect2	&operator*=(const Vect2 &other);
	Vect2	&operator*=(const f32 scalar);

	// Divisons
	Vect2	operator/(const Vect2 &other) const;
	Vect2	operator/(const f32 scalar) const;
	Vect2	&operator/=(const Vect2 &other);
	Vect2	&operator/=(const f32 scalar);

	// Comparisons
	bool	operator==(const Vect2 &other) const;
	bool	operator!=(const Vect2 &other) const;

	// Methods
	/**
	 * Returns the dot product - a measure of how much two vectors point in the same direction.
	 * 
	 * Formula: (x₁ * x₂) + (y₁ * y₂)
	 * 
	 * `> 0` -> vectors point in the same direction
	 * `< 0` -> vectors point in the opposite direction
	 * `= 0` -> vectors are perpendicular
	 */
	f32		dot(const Vect2 &other) const;

	/**
	 * Returns the magnitude (length) of the vector from the origin.
	 * 
	 * Formula: √(x² + y²)
	 */
	f32		length() const;

	/**
	 * Returns a normalized (unit-length) copy of the vector with the same direction but a length of 1.
	 */
	Vect2	normalized() const;

	f32	x;
	f32	y;
};

std::ostream	&operator<<(std::ostream &out, const Vect2 &other);
