#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	~PresidentialPardonForm();

	PresidentialPardonForm&
	operator=(PresidentialPardonForm const& rhs);

private:
	std::string _target;
	void        executeAction() const;
};
