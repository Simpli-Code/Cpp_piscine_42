/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:26:49 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/02 15:49:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
{
	_name = "";
	_weapon = NULL;
	std::cerr << RED << "HumanA must have a Name and a Weapon!" << RST << std::endl;
}

HumanA::HumanA(std::string name)
{
	_name = name;
	_weapon = NULL;
	std::cerr << RED << "HumanA must have a Weapon!" << RST << std::endl;
	
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon) {}

void HumanA::attack()
{
	if (_weapon != NULL)
		std::cout << YEL << _name << AWH << RST << RED << _weapon->getType() << RST << std::endl;
}

HumanA::~HumanA()
{
}

std::string HumanA::getName() const
{
	return (_name);
}
