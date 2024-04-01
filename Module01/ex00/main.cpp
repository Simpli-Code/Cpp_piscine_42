/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:25:16 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 16:28:21 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
Use heap allocation when you need objects with a longer lifespan or
when you need to dynamically create objects whose lifetime is not
determined at compile time For example:
if you need to create a zombie object that persists beyond the scope
of a function or if you need to create multiple zombie objects
and manage their lifetimes dynamically

Use stack allocation when you need short-lived objects or objects
that are scoped within a function or a block For example:
if you only need a zombie object within a specific function
and don't need it to persist beyond that function's scope
*/
int	main(void)
{
	Zombie zombie("Stack");
	zombie.announce();

	Zombie	*zombiePtr = newZombie("Heap");
	if (zombiePtr == NULL)
	{
		std::cerr << RED << MLC_FAIL << RST << std::endl;
		return (1);
	}
	else
	{
		zombiePtr->announce();
	}
	randomChump("Stack");
	delete zombiePtr;
	return (0);
}
