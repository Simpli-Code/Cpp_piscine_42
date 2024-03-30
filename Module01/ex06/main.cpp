/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:24:24 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/30 21:08:16 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc == 2)
	{
		std::string level(argv[1]);

		if (level == "DEBUG")
			harl.complain(DEBUG);
		else if (level == "INFO")
			harl.complain(INFO);
		else if (level == "WARNING")
			harl.complain(WARNING);
		else if (level == "ERROR")
			harl.complain(ERROR);
		else
			harl.complain(INVALID);
	}
	else
	{
		std::cerr << YEL << "Usage: Enter 2 Arguments \n" << argv[0] << ARG << RST;
		return (1);
	}
	return (0);
}
