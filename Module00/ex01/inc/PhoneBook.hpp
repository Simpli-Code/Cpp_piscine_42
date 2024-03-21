/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:55:39 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/14 17:52:09 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include			<iostream>
# include			<iomanip>
# include			<string>
# include			<cstdlib>
# include			"Contact.hpp"

# define RED		"\e[1;31m"
# define GRN		"\e[1;32m"
# define YEL		"\e[1;33m"
# define BLU		"\e[1;34m"
# define PIN		"\e[1;35m"
# define CYN		"\e[1;36m"
# define RST		"\e[0m"
# define FATAL		"\nFATAL ERROR: TERMINATED ABRUPTLY!\n"
# define INVALID	"Invalid ID, Please Try Again: "
# define ID			"\n\nENTER ID NUMBER: "
# define SEARCH		"Searching for a Student\n\n"
# define ADD		"Add a new Student\n\n"
# define ADDED		"\n\nSuccessfully Added a new Student\n\n"
# define FNAME		"Please Enter Your First Name:\t\t"
# define LNAME		"Please Enter Your Last Name:\t\t"
# define NNAME		"Please Enter Your Nick Name:\t\t"
# define SYEAR		"Please Enter Your Start Year:\t\t"
# define PHNUM		"Please Enter Your Phone Number:\t\t"
# define DSEC		"Please Enter Your Darkest Secret:\t"
# define ONLY_NUM	"Invalid input! Please enter only Digits 0 to 9\n"
# define ONLY_CHAR	"Invalid input! Please enter only alphabetic characters\n"
# define NO_MATCH	"No Matches Found! Please Try Again!\n\n"
# define CLOSE		"Closing The PhoneBook...\n\n"
# define EMPTY		"The PhoneBook is Empty!\n\n"
# define F_NAME		"First Name:\t\t"
# define L_NAME		"Last Name:\t\t"
# define N_NAME		"Nickname:\t\t"
# define S_YEAR		"Start Year:\t\t"
# define PH_NUM		"Phone Number:\t\t"
# define D_SEC		"Darkest Secret:\t\t"
# define FULL		"\nPhonebook is full! Overwriting the Contacts\n"
# define EXIST		"\nStudent already exists"

class PhoneBook
{

public:

	PhoneBook(void) : numStudents(0) {}
	~PhoneBook(void);

	Contact	students[8];
	int numStudents;

	// Add a new student to the phonebook
	void addStudent(const Contact &new_student)
	{
		if (numStudents > 7)
			numStudents = 0;
		if (numStudents < 8)
		{
			if (numStudents == 7)
				std::cout << RED << FULL << std::endl << RST;
			students[numStudents++] = new_student;
		}
	}

	// Check if a student already exists in the phonebook
	bool studentExists(const Contact &student) const
	{
		for (int i = 0; i < numStudents; i++)
		{
			if (students[i].get_first_name() == student.get_first_name() && \
				students[i].get_last_name() == student.get_last_name())
			{
				return true;
			}
		}
		return false;
	}
};

std::string	welcome_page(std::string);
std::string	trim(std::string);
int			is_digit(std::string);
int			is_alpha(std::string);
int			check_input(std::string, PhoneBook &, int &);
void		search_student(PhoneBook &, int &);
void		helper_select(Contact students[8], int &, int &);
void		display_phonebook(Contact students[8], int &);
void		select_a_student(Contact students[8], int &);
void		display_phonebook(Contact students[8], int &);
void		display_table(int, std::string, std::string);

Contact		add_new_student(PhoneBook &, int &);
Contact		check_first_name(Contact);
Contact		check_last_name(Contact);
Contact		check_nickname(Contact);
Contact		check_start_year(Contact);
Contact		check_phone_number(Contact);
Contact		check_darkest_secret(Contact);

#endif
