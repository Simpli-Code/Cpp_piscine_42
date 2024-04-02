/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:01:29 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/02 19:26:00 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	_name = "No Name";
	_weapon = NULL;
	std::cout << RED << "No Name provided for HumanB!" << RST << std::endl;
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
		std::cout << GRN << _name << AWH << _weapon->getType() << RST << std::endl;
		return ;
	}
	else
	{
		std::cout << BLU << _name << AWH << UA << RST << std::endl;
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
