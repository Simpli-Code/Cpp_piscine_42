/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:24:24 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/30 18:02:08 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::string	level = argv[1];
		// check_case(level);
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
				return (1);
		}
	}
	else
	{
		std::cerr << YEL << "Usage: Enter 2 Arguments \n" << argv[0] << ARG << RST;
		return (1);
	}
	return (0);
}
