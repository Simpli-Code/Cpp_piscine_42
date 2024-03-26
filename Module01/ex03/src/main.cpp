/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:45:07 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 08:45:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
Use a Pointer to Weapon:

If the Human class is not responsible for the lifetime of the Weapon object,
or if the Weapon object can be nullptr at some point, it's better to use a pointer.
Pointers allow for the possibility of representing an absent or null Weapon.
This is useful for cases where a Human might not always have a Weapon,
or if the Weapon can be replaced or removed.
If the Weapon object can be dynamically allocated and deallocated at runtime,
using a pointer allows for dynamic memory management. This can be useful when
the lifetime of the Weapon is not tied to the lifetime of the Human object.

Use a Reference to Weapon:

If the Human class always has a Weapon and the Weapon object's lifetime is guaranteed
to be at least as long as the Human object's lifetime, a reference can be used.
References provide syntactic convenience and make the code more readable.
They are typically used when an object is expected to exist and is not nullable.
Using a reference also implies that the Human class is not responsible for the
lifetime management of the Weapon object. It simply refers to an existing Weapon.

In summary, use a pointer to Weapon when the ownership semantics require
flexibility or when the Weapon object's lifetime is not tied to the Human
object's lifetime. Use a reference to Weapon when the Human class always has
a Weapon and the Weapon object's lifetime is guaranteed to be at least as
long as the Human object's lifetime, and when nullability is not a concern.
*/
int main(void)
{
	{
		Weapon club = Weapon(CSC);

		HumanA bob("Bob", club);
		bob.attack();
		club.setType(SOTOC);
		bob.attack();
	}
	{
		Weapon club = Weapon(CSC);

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType(SOTOC);
		jim.attack();
	}
	return (0);
}