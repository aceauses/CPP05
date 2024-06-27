#pragma once
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& src);
	~RobotomyRequestForm();

	RobotomyRequestForm&
	operator=(RobotomyRequestForm const& rhs);

private:
	std::string _target;
	void        executeAction() const;
};
