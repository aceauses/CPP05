#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&
	operator=(ShrubberyCreationForm const& rhs);

private:
	std::string _target;
	void        executeAction() const;
};
