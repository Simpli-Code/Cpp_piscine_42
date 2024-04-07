/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:30:34 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/06 18:34:19 by chruhin          ###   ########.fr       */
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
	Fixed(const Fixed &original);
	Fixed &operator=(const Fixed &original);
	float toFloat() const;
	int toInt() const;

	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
	~Fixed();
};

#endif

/*
1. Copy Constructor needs to be in the public section
2. Doesn't have a return type
3. It has the same name as the Class that it belongs to
4. It takes one parameter: the name of the Object
5. The Object must be passed by reference because:
	In order to copy the Object, the compiler needs to have a copy Constructor
	so that it can copy the Objects, but here we are
	creating the copy Constructor itself, which creates a logical error
	in order to pass the object to copy constructor we need to have a copy constructor
	but in order to create a copy constructor we need to pass the Object as a parameter
	and that is going to create a logical error, where you can not create a copy
	Constructor before you can copy the Object and you also can not copy the
	Object before you have a copy constructor, so in order to fix this problem
	we simply need to pass the Object by reference and not by value (a copy of it).
	Since we are passing by reference someone can change the value of original
	Object !!! in order to prevent this we should use ( const )
	Fixed(const Fixed &original) so now our original Object is a constant meaning
	should not be changed

	If we copy an Object that has a pointer to a dynamically allocated memory
	we need to copy all the elements from the original Object to a new allocated memory


In 3 cases a copy Constructor can be invoked:
1.	Creating a new Object based on an already existing Object
2.	When the Compiler is creating a temporary Object, for Example:
		When you are passing an Object as a parameter to a function but you are passing
		it by value not by reference, it this case the compiler is going to make
		a copy of that Object and for that it will invok copy Constructor, for Example:

		class Book
		{
			public:
				std::string Title;
				std::string Author;
		};

		void	PrintBook(Book book)
		{
			std::cout << "Title: " << book.Title << endl;
			std::cout << "Author: " << book.Author << endl;
		}

		int	main()
		{
			Book book1("C++ Lambda Story", "Bartek F."")
			PrintBook(book1);
		}

	SOURCE:
	https://www.youtube.com/watch?v=UYYoq784pQY

	https://developer.arm.com/documentation/ka003660/latest/#:~:text=ARMCC%3A%20C%2B%2B%20operator%20new%20returns%20NULL%20on%20failure
*/
