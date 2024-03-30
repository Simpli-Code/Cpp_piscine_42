/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:03:10 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/25 13:37:01 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

# define RED		"\e[1;31m"
# define GRN		"\e[1;32m"
# define YEL		"\e[1;33m"
# define BLU		"\e[1;34m"
# define PIN		"\e[1;35m"
# define CYN		"\e[1;36m"
# define RST		"\e[0m"

#define MLC_FAIL	"Failed to allocate memory for the zombie horde"
#define USAGE		"Usage: Enter a Number and a Name!"
#define NUM			"First argument must be a number! "
#define DESTR		":\e[1;35m Destroyed\e[0m"
#define BRAIN		":\e[1;36m BraiiiiiiinnnzzzZ...\e[0m"

class Zombie
{
private:
	std::string _name;

public:

	Zombie();

	explicit	Zombie(std::string name);
	static Zombie	*zombieHorde(int N, std::string name);
	void	announce();

	~Zombie();
};

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::Zombie() : _name("Unknown") {}

void	Zombie::announce(void)
{
	std::cout << _name << BRAIN << std::endl;
}


Zombie	*Zombie::zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);

	Zombie	*horde = new Zombie[N]; // Allocate N Zombie objects in a single allocation
	for (int i = 0; i < N; ++i)
	{
		horde[i]._name = name; // Initialize each zombie with the provided name
	}
	return horde; // Return a pointer to the first zombie
}



void testZombieHorde(int N, std::string name)
{
	Zombie* horde = Zombie::zombieHorde(N, name);
	if (horde == NULL)
	{
		std::cerr << RED << MLC_FAIL << RST << std::endl;
		return;
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			horde[i].announce(); // Call announce() for each zombie
		}
		delete[] horde; // Delete the array of zombies to avoid memory leaks
	}
}


Zombie::~Zombie(void)
{
	std::cout << _name << DESTR << std::endl;
}

int main(int argc, char *argv[])
{
	std::string message = USAGE;

	if (argc == 3)
	{
		int	N = atoi(argv[1]);
		if (!N)
		{
			std::cerr << RED << NUM << RST << std::endl;
			return (1);
		}
		testZombieHorde(N, argv[2]);
	}
	else
		std::cerr << RED << message << RST << std::endl;
	return 0;
}
