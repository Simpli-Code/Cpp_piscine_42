/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:43:01 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 15:59:35 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::Zombie() : _name("Unknown") {}

/*
This function is a member of Class Zombie and has access to the private
member _name.
Whenever this function is called it prints the value of _name the string
*/
void	Zombie::announce(void)
{
	std::cout << GRN << _name << RST << PIN << BRAIN << RST << std::endl;
}

/*

This function is a static function since it operates on the class but not
on any particular instance of it.
It allocates N Zombie objects in a single allocation using ( new )
checks if allocation failed and prints an error msg
inside the it initializes each zombie with the provided name
Returns a pointer to the first zombie
*/
Zombie	*Zombie::zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	if (horde == NULL)
	{
		std::cerr << RED << MLC_FAIL << RST << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; ++i)
	{
		horde[i]._name = name;
	}
	return horde;
}


/*
This function calls zombieHorde and checks if allocations failed
if so it prints an error msg malloc failure
else it enters a loop and calls announce function for each object
and at the end it frees the array of zombies to avoid memory leaks
*/
void testZombieHorde(int N, std::string name)
{
	Zombie	*horde = Zombie::zombieHorde(N, name);
	if (horde == NULL)
	{
		std::cerr << RED << MLC_FAIL << RST << std::endl;
		return ;
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			horde[i].announce();
		}
		delete[] horde;
	}
}

//The destructor will clean up everything at the end
Zombie::~Zombie(void)
{
	std::cout << RED << _name << RST << YEL << DESTR << RST << std::endl;
}
