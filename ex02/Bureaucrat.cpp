#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _grade(150), _name("Default") {}

Bureaucrat::Bureaucrat(int grade)
	: _grade(grade), _name("Default") {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _grade(grade), _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj) {
		this->_grade = obj.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const& obj) {
	if (this != &obj) {
		this->_grade = obj.getGrade();
	}
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade() const { return this->_grade; }

const std::string Bureaucrat::getName() const {
	return this->_name;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream&     out,
						 const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade "
		<< obj.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signs "
				  << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cerr << this->getName() << " cannot sign "
				  << form.getName() << " because " << e.what()
				  << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
	} catch (AForm::GradeTooLowException& e) {
		std::cerr << this->getName() << " cannot execute "
				  << form.getName() << " because " << e.what()
				  << std::endl;
	} catch (AForm::FormNotSignedException& e) {
		std::cerr << this->getName() << " cannot execute "
				  << form.getName() << " because " << e.what()
				  << std::endl;
	}
}