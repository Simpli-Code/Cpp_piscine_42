/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:32:58 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/24 17:42:53 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
This function takes a string as input and converts it using toupper();
function to upper case letters and return the converted string.
*/

std::string convert_string(char *str)
{
	int	i = 0;
	std::string new_str = str;

	while (new_str[i])
	{
		new_str[i] = std::toupper(new_str[i]);
		i++;
	}
	return (new_str);
}

int	main(int argc, char **argv)
{
	int	i = 1;
	std::string message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1)
		return (std::cout << message << std::endl, 0);
	else
	{
		while (i < argc)
		{
			std::cout << convert_string(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
