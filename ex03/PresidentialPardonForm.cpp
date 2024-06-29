#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5)
	, _target("Default_target") {}

PresidentialPardonForm::PresidentialPardonForm(
	std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& src)
	: AForm(src), _target(src._target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm& PresidentialPardonForm::operator=(
	PresidentialPardonForm const& rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return *this;
}

void PresidentialPardonForm::executeAction() const {
	std::cout << _target
			  << " has been pardoned by Zafod Beeblebrox"
			  << std::endl;
}