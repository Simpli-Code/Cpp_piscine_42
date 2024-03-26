/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:43:16 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 08:43:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
private:
	std::string _name;
	Weapon *_weaponPtr;

public:

	HumanB(const std::string &name);

	void setWeapon(const Weapon &weapon);
	void attack() const;

	~HumanB();
};

#endif