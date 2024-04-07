/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:37:10 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/03 14:44:32 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

	Fixed::Fixed()
	{
		_value = 0;
		std::cout << RED << "Default constructor called" << RST << std::endl;
	}

	Fixed::Fixed(const Fixed &original)
	{
		_value = original._value;
		std::cout << BLU << "Copy constructor called" << RST << std::endl;
	}

	Fixed &Fixed::operator=(const Fixed &original)
	{
		std::cout << BLU << "Copy assignment operator called" << RST << std::endl;
		if (this != &original)
		{
			_value = original._value;
		}
		return (*this);
	}

	Fixed::~Fixed()
	{
		std::cout << RED << "Destructor called" << RST << std::endl;
	}

	int Fixed::getRawBits(void) const
	{
		std::cout << "getRawBits member function called" << std::endl;
		return (_value);
	}

	void Fixed::setRawBits(const int raw)
	{
		_value = raw;
	}
