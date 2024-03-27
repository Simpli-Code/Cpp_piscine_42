/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:50:12 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/25 11:26:28 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;

public:

	Zombie();

	explicit	Zombie(std::string name);
	void		announce();

	~Zombie();
};

Zombie::Zombie(std::string name) : _name(name) {}


void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie	*newZombie(std::string name)
{
	return new Zombie(name);
}

void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}

Zombie::~Zombie()
{
	std::cout << "Destroyed " << _name << std::endl;
}


/*
calling explicit constructor to create a zombie and announcing it
Create a zombie using newZombie and announce it
Create a zombie using randomChump and let it announce itself
Don't forget to delete dynamically allocated memory

*/

int	main()
{
	Zombie zombie("Stack");
	zombie.announce();

	Zombie	*zombiePtr = newZombie("Heap");
	zombiePtr->announce();

	randomChump("Stack");

	delete zombiePtr;

	return 0;
}
