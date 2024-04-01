/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:29:37 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 12:37:08 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	public:
		HumanB();
		HumanB(const HumanB &copy);
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &weapon);
		~HumanB();
		std::string getName() const;

	private:
		std::string _name;
		Weapon	*_weapon;
};

#endif
