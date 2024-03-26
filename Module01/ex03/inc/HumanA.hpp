/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:42:41 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 08:42:57 by codespace        ###   ########.fr       */
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
	std::string _name;
	Weapon _weapon;

public:

	HumanA(const std::string &name, const Weapon &weapon);

	void attack() const;
};

#endif
