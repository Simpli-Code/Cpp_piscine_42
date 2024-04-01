/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:54:21 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/26 18:24:44 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type) {}

const std::string Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(const std::string	newType)
{
	_type = newType;
}
