/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:41:14 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/25 14:30:42 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

# define MAX_N		1000000
# define RED		"\e[1;31m"
# define GRN		"\e[1;32m"
# define YEL		"\e[1;33m"
# define BLU		"\e[1;34m"
# define PIN		"\e[1;35m"
# define CYN		"\e[1;36m"
# define RST		"\e[0m"

# define MLC_FAIL	"Failed to allocate memory for the zombie horde"
# define USAGE		"Usage: Enter a Number and a Name!"
# define INVD		"Invalid input! First argument must a positive integer number"
# define DESTR		":\e[1;35m Destroyed\e[0m"
# define BRAIN		":\e[1;36m BraiiiiiiinnnzzzZ...\e[0m"

class Zombie
{
private:
	std::string _name;

public:

	Zombie();

	explicit	Zombie(std::string name);
	static Zombie	*zombieHorde(int N, std::string name);
	void	announce();

	~Zombie();
};

void testZombieHorde(int N, std::string name);

#endif
