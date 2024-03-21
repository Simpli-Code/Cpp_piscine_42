/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:32:58 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/07 21:47:35 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
This function takes a string as input and converts it using toupper(); function
to upper case letters and return the converted string.
*/

char	*convert_string(char *str)
{
	int	i = -1;

	while (str[++i])
		str[i] = std::toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	std::string message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1)
		return (std::cout << message << std::endl, 0);
	else
	{
		while (++i < argc)
		{
			std::cout << convert_string(argv[i]) << ' ';
		}
	}
	std::cout << std::endl;
	return (0);
}
