/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:26:49 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/02 11:34:10 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(int num)
{
	switch (num)
	{
		case DEBUG:
		{
			std::cout << RED << "[ DEBUG ]\n" << RST
			<< CYN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << RST;
		}
		case INFO:
		{
			std::cout << RED << "[ INFO ]\n" << RST
			<< GRN << "I cannot believe adding extra bacon costs more money.\n"
			<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RST;
		}
		case WARNING:
		{
			std::cout << RED << "[ WARNING ]\n" << RST
			<< YEL << "I think I deserve to have some extra bacon for free.\n"
			<< "I’ve been coming for years whereas you started working here since last month.\n" << RST;
		}
		case ERROR:
		{
			std::cout << RED << "\n[ ERROR ]\n" << RST
			<< PIN << "This is unacceptable! I want to speak to the manager now.\n\n" << RST;
			break ;
		}
		default:
			std::cerr << BLU << "[ Probably complaining about insignificant problems ]\n\n" << RST;
			break ;
	}
}
