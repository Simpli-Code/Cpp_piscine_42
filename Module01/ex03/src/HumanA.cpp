/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:26:49 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 17:55:03 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
{
	_name = "Default Name";
	_weapon->setType("Default Weapon");
}

HumanA::HumanA(std::string &name)
{
	_name = name;
	_weapon->setType("Default Weapon");
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	_name = name;
	_weapon = &weapon;
}

void HumanA::attack()
{
	std::cout << YEL << _name << AWH << RST << RED << _weapon->getType() << RST << std::endl;
}

HumanA::~HumanA()
{
}

std::string HumanA::getName() const
{
	return (_name);
}
