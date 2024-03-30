/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:32:35 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/27 18:32:37 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    // Open input file
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file " << filename << std::endl;
        return;
    }

    // Create output file with .replace extension
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "Error: Unable to create output file " << outputFilename << std::endl;
        return;
    }

    // Read input file line by line and replace occurrences of s1 with s2
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.replace(pos, s1.length(), s2);
            pos += s2.length(); // Move past the replaced string
        }
        outputFile << line << std::endl; // Write the modified line to the output file
    }

    std::cout << "Replacement completed. Output written to " << outputFilename << std::endl;
}

int main(int argc, char *argv[]) {
    // Check if filename, s1, and s2 are provided as command-line arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceInFile(filename, s1, s2);

    return 0;
}
