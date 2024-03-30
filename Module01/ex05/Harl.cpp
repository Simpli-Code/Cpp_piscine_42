/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:26:49 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/30 21:19:56 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::_debug()
{
	std::cout << CYN << "DEBUG: I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info()
{
	std::cout << PIN << "INFO: I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RST << std::endl;
}

void Harl::_warning()
{
	std::cout << GRN << "WARNING: I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month." << RST << std::endl;
}

void Harl::_error()
{
	std::cout << YEL << "ERROR: This is unacceptable! I want to speak to the manager now." << RST << std::endl;
}

void Harl::complain(int level)
{
	void (Harl::*complaintFunction)();
	complaintFunction = NULL;
	switch (level)
	{
		case DEBUG:
			complaintFunction = &Harl::_debug;
			break;
		case INFO:
			complaintFunction = &Harl::_info;
			break;
		case WARNING:
			complaintFunction = &Harl::_warning;
			break;
		case ERROR:
			complaintFunction = &Harl::_error;
			break;
		default:
			std::cerr << RED << "Invalid complaint level: " << level << RST << std::endl;
			break;
	}
	if (complaintFunction != NULL)
		(this->*complaintFunction) ();
}
