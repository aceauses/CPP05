#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern {

public:
	Intern();
	Intern(Intern const& src);
	~Intern();

	Intern& operator=(Intern const& rhs);
	AForm*  makeForm(std::string const& name,
					 std::string const& target);
	class FormNotFoundException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form not found";
		}
	};

private:
};

std::ostream& operator<<(std::ostream& o, Intern const& i);
