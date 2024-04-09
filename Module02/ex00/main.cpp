/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:30:28 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/07 13:31:03 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

/*
Orthodox Canonical class:
refers to a class that follows a set of conventions and guidelines for its design,

including:
Default Constructor: A constructor with no parameters that initializes the object
to a default state.

Copy Constructor:
A constructor that initializes a new object as a copy of an existing object of
the same type.

Copy Assignment Operator:
An overloaded assignment operator (operator=) that assigns the state of one
object to another object of the same type.

Destructor:
A destructor that cleans up resources allocated by the object when it goes
out of scope or is explicitly deleted.

Getter and Setter Functions:
Functions that allow accessing and modifying private member variables
of the class, respectively.

Operator Overloading:
Overloading operators to provide custom behavior for the class,
such as arithmetic operations, comparison operators,
stream insertion (<<) and extraction (>>) operators, etc.

Encapsulation:
Proper encapsulation of data members by making them private and
providing public interfaces to interact with them.

Initialization Methods:
Providing initialization methods for objects,
which may be constructor overloads or separate member functions.

Const-Correctness:
Ensuring that member functions that do not modify the
object's state are declared as const.

Rule of Three (or Rule of Five):
Implementing or disabling copy constructors, copy assignment operators,
and destructors as needed to properly manage resources and prevent memory leaks.

Static Member Functions:
Functions that operate on class-level data or do not require an instance of the class.

By adhering to these conventions, Orthodox Canonical classes are designed in a
consistent and predictable manner, making them easier to understand,
maintain, and integrate into larger codebases.
*/

int	main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << GRN << a.getRawBits() << RST << std::endl;
	std::cout << YEL << b.getRawBits() << RST << std::endl;
	std::cout << PIN << c.getRawBits() << RST << std::endl;
	return (0);
}

/*
There are two widely-used memory allocation techniques: automatic allocation and dynamic
allocation. Commonly, there is a corresponding region of memory for each: the stack and the heap.

Stack
The stack always allocates memory in a sequential fashion. It can do so because
it requires you to release the memory in the reverse order (First-In, Last-Out: FILO).
This is the memory allocation technique for local variables in many programming languages.
It is very, very fast because it requires minimal bookkeeping and the next address to allocate is implicit.

In C++, this is called automatic storage because the storage is claimed automatically
at the end of scope. As soon as execution of current code block (delimited using {}) is completed,
memory for all variables in that block is automatically collected. This is also the
moment where destructors are invoked to clean up resources.

Heap
The heap allows for a more flexible memory allocation mode. Bookkeeping is
more complex and allocation is slower. Because there is no implicit release point,
you must release the memory manually, using delete or delete[] (free in C). However,
the absence of an implicit release point is the key to the heap's flexibility.

Reasons to use dynamic allocation
Even if using the heap is slower and potentially leads to memory leaks or memory fragmentation,
there are perfectly good use cases for dynamic allocation, as it's less limited.

Two key reasons to use dynamic allocation:

You don't know how much memory you need at compile time. For instance,
when reading a text file into a string, you usually don't know what size the file has,
so you can't decide how much memory to allocate until you run the program.

You want to allocate memory which will persist after leaving the current block.
For instance, you may want to write a function string readfile(string path)
that returns the contents of a file. In this case, even if the stack could hold
the entire file contents, you could not return from a function and keep the allocated memory block.

Why dynamic allocation is often unnecessary
In C++ there's a neat construct called a destructor.
This mechanism allows you to manage resources by aligning the lifetime of
the resource with the lifetime of a variable. This technique is called RAII and is
the distinguishing point of C++. It "wraps" resources into objects. std::string is a perfect example. This snippet:

int main ( int argc, char* argv[] )
{
    std::string program(argv[0]);
}
actually allocates a variable amount of memory. The std::string object allocates
memory using the heap and releases it in its destructor. In this case,
you did not need to manually manage any resources and still got the benefits of dynamic memory allocation.

In particular, it implies that in this snippet:

int main ( int argc, char* argv[] )
{
    std::string * program = new std::string(argv[0]);  // Bad!
    delete program;
}
there is unneeded dynamic memory allocation. The program requires more typing (!) and
introduces the risk of forgetting to deallocate the memory. It does this with no apparent benefit.

Why you should use automatic storage as often as possible
Basically, the last paragraph sums it up. Using automatic storage as often as possible makes your programs:

faster to type;
faster when run;
less prone to memory/resource leaks.
Bonus points
In the referenced question, there are additional concerns. In particular, the following class:

class Line {
public:
    Line();
    ~Line();
    std::string* mString;
};

Line::Line() {
    mString = new std::string("foo_bar");
}

Line::~Line() {
    delete mString;
}
Is actually a lot more risky to use than the following one:

class Line {
public:
    Line();
    std::string mString;
};

Line::Line() {
    mString = "foo_bar";
    // note: there is a cleaner way to write this.
}
The reason is that std::string properly defines a copy constructor. Consider the following program:

int main ()
{
    Line l1;
    Line l2 = l1;
}
Using the original version, this program will likely crash, as it uses delete on the same string twice.
Using the modified version, each Line instance will own its own string instance, each with
its own memory and both will be released at the end of the program.

Other notes
Extensive use of RAII is considered a best practice in C++ because of all the reasons above. However,
there is an additional benefit which is not immediately obvious. Basically,
it's better than the sum of its parts. The whole mechanism composes. It scales.

If you use the Line class as a building block:

 class Table
 {
      Line borders[4];
 };
Then

 int main ()
 {
     Table table;
 }
allocates four std::string instances, four Line instances,
one Table instance and all the string's contents and everything is freed automagically.
*/
