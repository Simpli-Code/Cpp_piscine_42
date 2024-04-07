/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:30:34 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/07 11:55:59 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RED		"\e[1;31m"
# define GRN		"\e[1;32m"
# define YEL		"\e[1;33m"
# define BLU		"\e[1;34m"
# define PIN		"\e[1;35m"
# define CYN		"\e[1;36m"
# define RST		"\e[0m"

class Fixed
{
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	float toFloat() const;
	int toInt() const;

	// Comparison operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Increment/decrement operators
	Fixed &operator++();     // Pre-increment
	Fixed operator++(int);   // Post-increment
	Fixed &operator--();     // Pre-decrement
	Fixed operator--(int);   // Post-decrement

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	friend	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif
