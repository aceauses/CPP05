#include "Form.hpp"
Form::Form() : _formName("default"), _signGrade(150), _executeGrade(150), _isSigned(false)
{
}

Form::Form(const std::string _name, int singGrade, int executeGrade) : _formName(_name), _signGrade(singGrade), _executeGrade(executeGrade), _isSigned(false)
{
	if (singGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (singGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form &obj) : _formName(obj._formName), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade), _isSigned(obj._isSigned)
{
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	out << "Form name: " << obj.getName() << std::endl;
	out << "Sign grade: " << obj.getSignGrade() << std::endl;
	out << "Execute grade: " << obj.getExecuteGrade() << std::endl;
	out << "Is signed: " << obj.getIsSigned() << std::endl;
	return out;
}

const std::string Form::getName() const
{
	return _formName;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	_isSigned = true;
}