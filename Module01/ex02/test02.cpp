/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:49:13 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/25 15:03:15 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define RED		"\e[1;31m"
#define GRN		"\e[1;32m"
#define YEL		"\e[1;33m"
#define BLU		"\e[1;34m"
#define PIN		"\e[1;35m"
#define CYN		"\e[1;36m"
#define RST		"\e[0m"

#define HI		"\e[1;35mHI THIS IS BRAIN\e[0m"
#define MEM_VAR	"Memory address of the string variable:\t"
#define MEM_PTR	"Memory address held by stringPTR:\t"
#define MEM_REF	"Memory address held by stringREF:\t"
#define VAR		"Value of the string variable:\t\t"
#define PTR		"Value pointed to by stringPTR:\t\t"
#define REF		"Value pointed to by stringREF:\t\t"

int main()
{
	std::string str = HI;
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	// Print memory addresses
	std::cout << YEL << MEM_VAR << RST << CYN <<&str << RST << std::endl;
	std::cout << YEL << MEM_PTR << RST << CYN << stringPTR << RST << std::endl;
	std::cout << YEL << MEM_REF << RST << CYN << &stringREF << RST << std::endl;

	// Print values
	std::cout << BLU << VAR << RST << str << std::endl;
	std::cout << BLU << PTR << RST << *stringPTR << std::endl;
	std::cout << BLU << REF << RST << stringREF << std::endl;

	return 0;
}
