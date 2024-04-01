/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:41:05 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 17:43:11 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
USE A POINTER TO WEAPON:
If the Human class is not responsible for the lifetime of the Weapon object,
or if the Weapon object can be nullptr at some point, it's better to use a pointer.
Pointers allow for the possibility of representing an absent or null Weapon.
This is useful for cases where a Human might not always have a Weapon,
or if the Weapon can be replaced or removed.
If the Weapon object can be dynamically allocated and deallocated at runtime,
using a pointer allows for dynamic memory management. This can be useful when
the lifetime of the Weapon is not tied to the lifetime of the Human object.

USE A REFERENCE TO WEAPON:
If the Human class always has a Weapon and the Weapon object's lifetime is guaranteed
to be at least as long as the Human object's lifetime, a reference can be used.
References provide syntactic convenience and make the code more readable.
They are typically used when an object is expected to exist and is not nullable.
Using a reference also implies that the Human class is not responsible for the
lifetime management of the Weapon object. It simply refers to an existing Weapon.

IN SUMMARY:
Use a pointer to Weapon when the ownership semantics require
flexibility or when the Weapon object's lifetime is not tied to the Human
object's lifetime. Use a reference to Weapon when the Human class always has
a Weapon and the Weapon object's lifetime is guaranteed to be at least as
long as the Human object's lifetime, and when nullability is not a concern.
*/
int main(void)
{
	{
		Weapon club = Weapon(CSC);

		HumanA Bob("Bob", club);
		Bob.attack();
		club.setType(SOTOC);
		Bob.attack();
	}
	{
		Weapon club = Weapon(CSC);

		HumanB	Jim("Jim");
		Jim.setWeapon(club);
		Jim.attack();
		club.setType(SOTOC);
		Jim.attack();
	}
	return (0);
}
