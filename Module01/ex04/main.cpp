/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:06:05 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/29 19:09:53 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sed.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << YEL << ARG << RST << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (!report_error(filename, s1, s2))
		return (1);
	replaceInFile(filename, s1, s2);
	return (0);
}

bool	report_error(std::string filename, std::string s1, std::string s2)
{
	if (s1.empty() || s1 == "")
	{
		std::cerr << RED << "ERROR: Empty string " << RST << std::endl;
		return (false);
	}
	if (!s1.find(s1))
	{
		std::cerr << RED << "ERROR: "<< s1 << " doesn't exist in "
			<< filename << " Therefore can not be replaced" << RST << std::endl;
		return (false);
	}
	if (s1 == s2)
	{
		std::cerr << RED << "ERROR: s1 and s2 is the same string " << RST << std::endl;
		return (false);
	}
	if (s2.empty() || s2 == "")
	{
		std::cerr << RED << "ERROR: Empty string " << RST << std::endl;
		return (false);
	}
	return (true);
}
