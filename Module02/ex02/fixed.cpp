/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:37:10 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/08 15:11:05 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

// Constructors
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {}

// Copy Constructor
Fixed::Fixed(const Fixed &original) : _value(original._value) {}

// copy Assignment operator
Fixed &Fixed::operator=(const Fixed &original)
{
	if (this != &original)
	{
		_value = original._value;
	}
	return *this;
}

Fixed::~Fixed() {}



// Comparison functions
bool Fixed::operator>(const Fixed &original) const
{
	return _value > original._value;
}

bool Fixed::operator<(const Fixed &original) const
{
	return _value < original._value;
}

bool Fixed::operator>=(const Fixed &original) const
{
	return _value >= original._value;
}

bool Fixed::operator<=(const Fixed &original) const
{
	return _value <= original._value;
}

bool Fixed::operator==(const Fixed &original) const
{
	return _value == original._value;
}

bool Fixed::operator!=(const Fixed &original) const
{
	return _value != original._value;
}


// Arithmetic functions
Fixed Fixed::operator+(const Fixed &original) const
{
	return Fixed(toFloat() + original.toFloat());
}

Fixed Fixed::operator-(const Fixed &original) const
{
	return Fixed(toFloat() - original.toFloat());
}

Fixed Fixed::operator*(const Fixed &original) const
{
	return Fixed(toFloat() * original.toFloat());
}

Fixed Fixed::operator/(const Fixed &original) const
{
	return Fixed(toFloat() / original.toFloat());
}


// Derement and Increments functions
Fixed &Fixed::operator++() // Pre-increment
{
	_value += 1 << _fractionalBits;
	return *this;
}

Fixed Fixed::operator++(int) // Post-increment
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--() // Pre-decrement
{
	_value -= 1 << _fractionalBits;
	return *this;
}

Fixed Fixed::operator--(int) // Post-decrement
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}



// Overload functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}




// Helper functions
float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

