/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:54:09 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/13 21:40:02 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	int	flag = 0;
	int	count = 0;
	std::string	input;
	PhoneBook	phonebook;
	while (42)
	{
		input = welcome_page(input);
		flag = check_input(input, phonebook, count);
		if (flag == 1)
			break ;
	}
	return (0);
}

std::string	welcome_page(std::string input)
{
	std::cout << std::endl;
	std::cout << GRN << std::setw(47) << std::setfill('*') <<  RST;
	std::cout << std::endl;
	std::cout << PIN << "*     Welcome to 42Vienna's PhoneBook     *" << RST;
	std::cout << std::endl;
	std::cout << GRN << std::setw(47) << std::setfill('*') << RST;
	std::cout << std::endl;
	std::cout << YEL << "\nCHOOSE AN OPTION\n\n" << RST;
	std::cout << BLU << "[1] \tADD a new Student\n" << RST;
	std::cout << BLU << "[2] \tSEARCH for a Student\n" << RST;
	std::cout << BLU << "[3] \tEXIT the PhoneBook\n" << RST;
	std::cout << YEL << "\nENTER YOUR OPTION: " << RST;
	getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << RED << FATAL << RST;
		exit (1);
	}
	std::cout << std::endl;
	return (input);
}

int check_input(std::string input, PhoneBook &phonebook, int &count)
{
	int	flag = 0;

	if (input == "1" || input == "add" || input == "ADD")
	{
		Contact new_student = add_new_student(phonebook, flag);
		if (flag == 1)
			return (0);
		else
		{
			phonebook.addStudent(new_student);
			if (count < 8)
				count++;
		}
		return (0);
	}
	else if (input == "2" || input == "search" || input == "SEARCH")
	{
		if (count > 0)
		{
			search_student(phonebook, count);
			return (0);
		}
		else
		{
			std::cout << RED << EMPTY << RST;
			return (0);
		}
	}
	else if (input == "3" || input == "exit" || input == "EXIT")
	{
		std::cout << RED << CLOSE << RST;
		return 1;
	}
	else
	{
		std::cout << RED << NO_MATCH << RST;
		return (0);
	}
}
