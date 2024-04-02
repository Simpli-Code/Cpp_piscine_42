/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:28:57 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/02 17:21:32 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
	private:
		std::string	_name;
		Weapon	*_weapon;

	public:
		HumanA();
		HumanA(std::string name);
		HumanA(std::string name, Weapon &weapon);
		void attack();
		~HumanA();
		std::string getName() const;
};

#endif
