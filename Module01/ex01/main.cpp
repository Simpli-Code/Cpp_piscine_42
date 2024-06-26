/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:41:05 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/06 17:13:12 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int	N = atoi(argv[1]);
		if (!N || N <= 0 || N > MAX_N)
		{
			std::cerr << RED << INVD << RST;
			return (1);
		}
		std::string str = argv[2];
		if (!testZombieHorde(N, str))
			return (1);
	}
	else
		std::cerr << YEL << "Usage: Enter 3 Arguments \n" << RST << PIN << argv[0] << RST << YEL << USAGE << RST;
	return (0);
}
