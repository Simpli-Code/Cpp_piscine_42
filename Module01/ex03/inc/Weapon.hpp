/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:27:38 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/02 11:12:00 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

# define RED	"\e[1;31m"
# define GRN	"\e[1;32m"
# define YEL	"\e[1;33m"
# define BLU	"\e[1;34m"
# define PIN	"\e[1;35m"
# define CYN	"\e[1;36m"
# define RST	"\e[0m"

# define AWH	" attacks with his"
# define UA		" bare fists"
# define CSC	" crude spiked club"
# define SOTOC	" AK-47"

class Weapon
{
private:
	std::string _type;

public:
	Weapon(const std::string &type);
	const std::string &getType() const;
	void setType(const std::string &newType);
};

#endif
