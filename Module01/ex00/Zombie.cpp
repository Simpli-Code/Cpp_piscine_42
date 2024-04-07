/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:18:23 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/06 17:05:46 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
defining the constructor for the Zombie class.
The constructor takes a std::string parameter named name
initializing the member variable _name with the value of the name parameter
passed to the constructor. To initialize class member variables before the
body of the constructor executes.
{}: Since the body of constructor is empty, there are no additional operations
performed inside the constructor beyond initializing _name
*/
Zombie::Zombie(std::string name) : _name(name) {}

/*
This function is a member of Class Zombie and has access to the private
member _name.
Whenever this function is called it prints the value of _name the string
*/
void	Zombie::announce(void)
{
	std::cout << _name << BRAIN << std::endl;
}

/*
This function takes a string as parameter and allocates dynamically memory
for an object and returns a pointer to that allocated memory
*/
Zombie	*newZombie(std::string name)
{
	return new Zombie(name);
}


// Allocates statically memory for an object and call the function announce
void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}


// The destructor will clean up everything at the end
Zombie::~Zombie()
{
	std::cout << _name << DESTR << std::endl;
}
