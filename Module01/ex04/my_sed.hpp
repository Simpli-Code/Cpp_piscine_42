/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:07:23 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 12:08:19 by chruhin          ###   ########.fr       */
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

# define COMPL	"Replacement completed. Output written to "
# define OPEN	"ERROR: Unable to open input File "
# define CREATE	"ERROR: Unable to create output File "
# define NOSTR	"WARNING: No such a string!  "
# define EQUAL	"ERROR: s1 and s2 is the same string "
# define WARN	"WARNING: The new string is Empty "
# define EMPTY	"ERROR: Empty string "
# define ARG	"Usage: \n \
Enter 3 Arguments: A filename to open, and 2 strings s1 and s2\n \
Every occurrence of s1 will be replaced with s2 and saved into a new file <.replace>"

class My_Sed
{
private:
	std::string _filename;
	std::string _s1;
	std::string _s2;
	std::string replaceString(const std::string &str) const;

public:
	explicit	My_Sed(const std::string &filename, const std::string &s1, const std::string &s2);
	bool	check_input();
	void	replaceInFile();
};


#endif
