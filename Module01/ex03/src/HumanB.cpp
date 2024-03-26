/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:44:49 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 08:48:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weaponPtr(NULL) {}

void HumanB::setWeapon(const Weapon &weapon)
{
	_weaponPtr = new Weapon(weapon.getType());
}

void HumanB::attack() const
{
	if (_weaponPtr != NULL)
	{
		std::cout << BLU << _name << AWH << _weaponPtr->getType() << RST << std::endl;
	}
	else
	{
		std::cout << YEL << _name << AU << RST << std::endl;
	}
}

HumanB::~HumanB()
{
	delete (_weaponPtr);
}