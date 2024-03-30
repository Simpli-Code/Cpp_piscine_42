/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:25:09 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/30 18:01:46 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

# define RED	"\e[1;31m"
# define GRN	"\e[1;32m"
# define YEL	"\e[1;33m"
# define BLU	"\e[1;34m"
# define PIN	"\e[1;35m"
# define CYN	"\e[1;36m"
# define RST	"\e[0m"

# define ARG " and a string. a string can be \n<DEBUG>, <INFO>, <WARNING>, <ERROR>\n or any string\n"

class Harl
{
public:
	static void complain(const std::string &level);
};

#endif
