/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:44:34 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 08:48:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon& weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack(void) const
{
	std::cout << PIN << _name << AWH << _weapon.getType() << RST << std::endl;
}