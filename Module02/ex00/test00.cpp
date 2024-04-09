/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test00.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:02:48 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/03 16:13:25 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Book
{
public:
	std::string Title;
	std::string Author;
	Book(std::string title, std::string author) {}
	Book(Book &original);
	~Book() {}
};

// Book::Book(Book )
// void	PrintBook(Book book)
// {
// 	std::cout << "Title: " << book.Title << std::endl;
// 	std::cout << "Author: " << book.Author << std::endl;
// }

int	main()
{
	// Book book1("C++ Lambda Story", "Bartek F.");
	// Book book3("bla bal", "hi");
	// Book book2(book3);
	// PrintBook(book1);
	// PrintBook(book2);

	long long	nbr;
	std::cout << "1. Enter a Number to convert to binary : ";
	std::cin >> nbr;
	std::vector<int> bit_vector;

	while (nbr > 0)
	{
		bit_vector.push_back(nbr % 2);
		nbr /= 2;
	}

	for (int i = bit_vector.size() - 1; i >= 0; --i)
	{
		std::cout << bit_vector.at(i);
	}
	std::cout << std::endl;

	long long	num;
	std::cout << "2. Enter a Number to convert to binary : ";
	std::cin >> num;
	std::string bits;

	while (num > 0)
	{
		bits.append(std::to_string(num % 2));
		num /= 2;
	}

	reverse(bits.begin(), bits.end());
	std::cout << bits << std::endl;

	return (0);
}

