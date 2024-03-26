/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:43:32 by codespace         #+#    #+#             */
/*   Updated: 2024/03/26 08:48:33 by codespace        ###   ########.fr       */
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

# define AWH	" attacks with his "
# define AU		" attacks unarmed"
# define CSC	"crude spiked club"
# define SOTOC	"some other type of club"

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