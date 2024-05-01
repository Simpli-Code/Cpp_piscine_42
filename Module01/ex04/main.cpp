/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:06:05 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/28 08:14:56 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		MySed ftsed(filename, s1, s2);
		if (!ftsed.check_input())
			return (1);
		ftsed.replaceInFile();
	}
	else
	{
		std::cerr << YEL << ARG << RST << std::endl;
		return (1);
	}
	return (0);
}

bool	MySed::check_input()
{
	if (_s1.empty() || _s1 == "")
	{
		std::cerr << RED << EMPTY << RST << std::endl;
		return (false);
	}
	if (_s1 == _s2)
	{
		std::cerr << RED << EQUAL << RST << std::endl;
		return (false);
	}
	if (_s2.empty() || _s2 == "")
	{
		std::cerr << RED << WARN << RST << std::endl;
	}
	return (true);
}
