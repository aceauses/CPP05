#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {}

Intern::Intern(const Intern& src) { (void)src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern& Intern::operator=(Intern const& rhs) {
	if (this != &rhs) {
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, Intern const& i) {
	(void)i;
	return o;
}

AForm* createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string const& name,
						std::string const& target) {
	const std::string formNames[3]
		= {"presidential pardon", "robotomy request",
		   "shrubbery creation"};
	AForm* (*formCreators[3])(const std::string&)
		= {&createPresidentialPardonForm,
		   &createRobotomyRequestForm,
		   &createShrubberyCreationForm};
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << " form"
					  << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "Intern couldn't create " << name << " form"
			  << std::endl;
	throw FormNotFoundException();
}