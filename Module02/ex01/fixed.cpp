/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:37:10 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/06 18:36:06 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &original) : _value(original._value)
{
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &original)
{
	if (this != &original)
	{
		std::cout << "Copy assignment operator called\n";
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
