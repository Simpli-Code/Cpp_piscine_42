/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:37:10 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/07 12:02:06 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
	// std::cout << "Smaller constructor called\n";
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits)))
{
	// std::cout << "Multiplication constructor called\n";
}


Fixed::Fixed(const Fixed &original) : _value(original._value)
{
	// std::cout << "copy constructor called\n";
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &original)
{
	// std::cout << "Copy Assignment operator called\n";
	if (this != &original)
	{
		_value = original._value;
	}
	return *this;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// gettes & setters
void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}
