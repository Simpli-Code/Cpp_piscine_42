/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:01:29 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 12:44:25 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	_name = "";
	_weapon = NULL;
}

HumanB::HumanB(const HumanB &copy)
{
	_name = copy.getName();
	_weapon = copy._weapon;
}

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

void HumanB::attack()
{
	if (_weapon != NULL)
	{
		std::cout << PIN << _name << AWH << RST << RED << _weapon->getType() << RST << std::endl;
		return ;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

HumanB::~HumanB()
{
}

std::string HumanB::getName() const
{
	return (_name);
}
