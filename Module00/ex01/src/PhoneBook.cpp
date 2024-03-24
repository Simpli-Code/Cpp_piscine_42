/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:32:24 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/22 16:42:53 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook(void)
{
	return ;
}

Contact add_new_student(PhoneBook &phonebook, int &flag)
{
	Contact	new_student;

	std::cout << GRN << ADD << RST;
	new_student = check_first_name(new_student);
	new_student = check_last_name(new_student);
	if (phonebook.studentExists(new_student))
	{
		std::cout << RED << EXIST << std::endl << RST;
		flag = 1;
		return (new_student);
	}
	new_student = check_nickname(new_student);
	new_student = check_start_year(new_student);
	new_student = check_phone_number(new_student);
	new_student = check_darkest_secret(new_student);
	std::cout << GRN << ADDED << RST;
	return (new_student);
}

void	search_student(PhoneBook &phonebook, int &count)
{
	std::cout << GRN << SEARCH << RST;

	display_phonebook(phonebook.students, count);
	select_a_student(phonebook.students, count);
}

Contact	check_first_name(Contact new_student)
{
	std::string	f_name;
	bool		valid_input = false;

	while (!valid_input)
	{
		std::cout << BLU << FNAME << RST;
		getline(std::cin, f_name);
		if (std::cin.eof())
		{
			std::cout << RED << FATAL << RST;
			exit (1);
		}
		if (!is_alpha(f_name))
		{
			std::cout << RED << ONLY_CHAR << RST;
		}
		else
		{
			new_student.set_first_name(f_name);
			valid_input = true;
		}
	}
	return (new_student);
}

Contact	check_last_name(Contact new_student)
{
	std::string	l_name;
	bool		valid_input = false;

	while (!valid_input)
	{
		std::cout << BLU << LNAME << RST;
		getline(std::cin, l_name);
		if (std::cin.eof())
		{
			std::cout << RED << FATAL << RST;
			exit (1);
		}
		if (!is_alpha(l_name))
		{
			std::cout << RED << ONLY_CHAR << RST;
		}
		else
		{
			new_student.set_last_name(l_name);
			valid_input = true;
		}
	}
	return (new_student);
}

Contact	check_nickname(Contact new_student)
{
	std::string	n_name;

	std::cout << BLU << NNAME << RST;
	getline(std::cin, n_name);
	if (std::cin.eof())
	{
		std::cout << RED << FATAL << RST;
		exit (1);
	}
	new_student.set_nickname(n_name);
	return (new_student);
}

Contact	check_start_year(Contact new_student)
{
	std::string	s_year;
	bool		valid_input = false;

	while (!valid_input)
	{
		std::cout << BLU << SYEAR << RST;
		getline(std::cin, s_year);
		if (std::cin.eof())
		{
			std::cout << RED << FATAL << RST;
			exit (1);
		}
		if (!is_digit(s_year))
		{
			std::cout << RED << ONLY_NUM << RST;
		}
		else
		{
			new_student.set_start_year(s_year);
			valid_input = true;
		}
	}
	return (new_student);
}

Contact	check_phone_number(Contact new_student)
{
	std::string	ph_num;
	bool		valid_input = false;

	while (!valid_input)
	{
		std::cout << BLU << PHNUM << RST;
		getline(std::cin, ph_num);
		if (std::cin.eof())
		{
			std::cout << RED << FATAL << RST;
			exit (1);
		}
		if (!is_digit(ph_num))
		{
			std::cout << RED << ONLY_NUM << RST;
		}
		else
		{
			new_student.set_phone_number(ph_num);
			valid_input = true;
		}
	}
	return (new_student);
}

Contact	check_darkest_secret(Contact new_student)
{
	std::string	d_sec;

	std::cout << BLU << DSEC << RST;
	getline(std::cin, d_sec);
	if (std::cin.eof())
	{
		std::cout << RED << FATAL << RST;
		exit (1);
	}
	new_student.set_darkest_secret(d_sec);
	return (new_student);
}

void	display_table(int id, std::string first_name, std::string last_name)
{
	std::cout << GRN << "*   " << RST;
	std::cout << PIN << std::setfill('-') << std::setw(38) <<  RST;
	std::cout << GRN << "    *\n" << RST;
	std::cout << GRN << "*   " << RST;
	std::cout << PIN << "| " << id << "  | "
		<< std::setfill(' ') << std::setw(10) << trim(first_name) << "  | "
		<< std::setfill(' ') << std::setw(10) << trim(last_name) << "  |" RST;
	std::cout << GRN << "    *\n" << RST;
}

void	display_phonebook(Contact students[8], int &count)
{
	int	i = 0;

	std::cout << std::endl;
	std::cout << GRN << std::setw(47) << std::setfill('*') << RST;
	std::cout << std::endl;
	std::cout << GRN << "*   " << RST;
	std::cout << PIN << std::setfill('-') << std::setw(38) <<  RST;
	std::cout << GRN << "    *\n" << RST;
	std::cout << GRN << "*   " << RST;
	std::cout << PIN << "| " << "ID" << " | "
		<< std::setfill(' ') << std::setw(10) << "First Name" << "  | "
		<< std::setfill(' ') << std::setw(10) << "Last Name" << "  |" RST;
	std::cout << GRN << "    *\n" << RST;
	while (i < count)
	{
		display_table(i + 1, students[i].get_first_name(), students[i].get_last_name());
		i++;
	}
	std::cout << GRN << "*   " << RST;
	std::cout << PIN << std::setfill('-') << std::setw(38) <<  RST;
	std::cout << GRN << "    *\n" << RST;
	std::cout << GRN << std::setw(47) << std::setfill('*') << RST;
	std::cout << std::endl;
}

void	select_a_student(Contact students[8], int &count)
{
	int	id;

	std::cout << YEL << ID << RST;
	while (!(std::cin >> id) || id < 1 || id > count)
	{
		std::cout << std::endl;
		if (std::cin.eof())
		{
			std::cout << RED << FATAL << RST;
			exit (1);
		}
		std::cout << RED << INVALID << RST;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	id--;
	helper_select(students, count, id);
}

void	helper_select(Contact students[8], int &count, int &id)
{

	if (id < count)
	{
		std::cout << std::endl << CYN << F_NAME << RST
			<< students[id].get_first_name()
			<< std::endl;
		std::cout << CYN << L_NAME << RST
			<< students[id].get_last_name()
			<< std::endl;
		std::cout << CYN << N_NAME << RST
			<< students[id].get_nickname()
			<< std::endl;
		std::cout << CYN << S_YEAR << RST
			<< students[id].get_start_year()
			<< std::endl;
		std::cout << CYN << PH_NUM << RST
			<< students[id].get_phone_number()
			<< std::endl;
		std::cout << CYN << D_SEC << RST
			<< students[id].get_darkest_secret()
			<< std::endl << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

// check if the string contains only digits 0 to 9 and space
int	is_digit(std::string str)
{
	int	i = 0;

	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

// check if the string contains only alphabetical characters, space and tabs
int	is_alpha(std::string str)
{
	int	i = 0;

	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') \
			|| str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

// trim the string data to 10 characters and a dot (.) at the end
std::string	trim(std::string data)
{
	if (data.length() >= 10)
		data = data.substr(0, 9).append(".");
	return (data);
}

// Add a new student to the phonebook
void	PhoneBook::addStudent(const Contact &new_student)
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
bool	PhoneBook::studentExists(const Contact &student) const
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
