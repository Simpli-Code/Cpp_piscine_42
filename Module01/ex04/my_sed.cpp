/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:09:41 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/29 19:11:53 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sed.hpp"

My_Sed::My_Sed(const std::string &filename, const std::string &s1, const std::string &s2) : \
	_filename(filename), _s1(s1), _s2(s2) {}

void	replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << RED << "ERROR: Unable to open input File "
			<< RST << PIN << filename << RST << std::endl;
		return ;
	}

	//Create output file with .replace extension
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile)
	{
		std::cerr << RED << "ERROR: Unable to create output File "
			<< RST << PIN << outputFilename << RST << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();//Move past the replaced string
		}
		outputFile << line << std::endl;//Write the modified line to the output file
	}
	std::cout << YEL << "Replacement completed. Output written to "
		<< RST << PIN << outputFilename << RST << std::endl;
}
