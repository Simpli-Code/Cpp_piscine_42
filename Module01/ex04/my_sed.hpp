/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:07:23 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/29 19:07:22 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MY_SED_HPP
# define MY_SED_HPP

# include <fstream>
# include <iostream>
# include <string>

# define RED	"\e[1;31m"
# define GRN	"\e[1;32m"
# define YEL	"\e[1;33m"
# define BLU	"\e[1;34m"
# define PIN	"\e[1;35m"
# define CYN	"\e[1;36m"
# define RST	"\e[0m"

# define ARG "Usage: \n \
Enter 3 Arguments: A filename to open, and 2 strings s1 and s2\n \
Every occurrence of s1 will be replaced with s2 and saved into a new file"

class My_Sed
{
private:
	std::string _filename;
	std::string _s1;
	std::string _s2;

public:
	explicit	My_Sed(const std::string &filename, const std::string &s1, const std::string &s2);
};

bool	report_error(std::string filename, std::string s1, std::string s2);
void	replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2);

#endif
