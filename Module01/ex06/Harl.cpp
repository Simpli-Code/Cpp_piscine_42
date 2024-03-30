/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:26:49 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/30 18:01:18 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(const std::string& level)
{
	if (level == "DEBUG")
	{
		std::cout << RED << "[ DEBUG ]\n" << RST
		<< CYN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << RST;
	}
	else if (level == "INFO")
	{
		std::cout << GRN << "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RST;
	}
	else if (level == "WARNING")
	{
		std::cout << RED << "[ WARNING ]\n" << RST
		<< YEL << "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month.\n" << RST;
	}
	else if (level == "ERROR")
	{
		std::cout << RED << "\n[ ERROR ]\n" << RST
		<< PIN << "This is unacceptable! I want to speak to the manager now.\n\n" << RST;
	}
	else
	{
		std::cout << BLU << "[ Probably complaining about insignificant problems ]\n\n" << RST;
	}
}

void	check_case(std::string level)
{
	switch (level[0])
	{
		std::cout << std::endl << std::endl;
		case 'D':
			Harl::complain("DEBUG");
			// Fall through
		case 'I':
			Harl::complain("INFO");
			// Fall through
		case 'W':
			Harl::complain("WARNING");
			// Fall through
		case 'E':
			Harl::complain("ERROR");
			break ;
		default:
			std::cerr << BLU << "[ Probably complaining about insignificant problems ]\n\n" << RST;
			break ;
	}
}
