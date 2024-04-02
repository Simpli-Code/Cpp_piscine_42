/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:46:41 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/02 11:12:27 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define RED		"\e[1;31m"
# define GRN		"\e[1;32m"
# define YEL		"\e[1;33m"
# define BLU		"\e[1;34m"
# define PIN		"\e[1;35m"
# define CYN		"\e[1;36m"
# define RST		"\e[0m"

# define MLC_FAIL	"Failed to allocate memory for the zombie"
# define BRAIN		":\e[1;33m BraiiiiiiinnnzzzZ...\e[0m"
# define DESTR		":\e[1;35m Destroyed\e[0m"

class Zombie
{
private:
	std::string _name;

public:
	Zombie();
	Zombie(std::string name);
	void	announce(void);
	~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
