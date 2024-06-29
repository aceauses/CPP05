#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45)
	, _target("Default_target") {}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& src)
	: AForm(src), _target(src._target) {}

RobotomyRequestForm::RobotomyRequestForm(
	std::string const& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return *this;
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "*drilling noises* ";
	if (rand() % 2)
		std::cout << _target
				  << " has been robotomized successfully"
				  << std::endl;
	else
		std::cout << _target << " robotomization failed"
				  << std::endl;
}