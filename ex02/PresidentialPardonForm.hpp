#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);
