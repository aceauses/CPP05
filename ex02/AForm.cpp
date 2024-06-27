#include "AForm.hpp"
AForm::AForm()
	: _formName("default")
	, _signGrade(150)
	, _executeGrade(150)
	, _isSigned(false) {}

AForm::AForm(const std::string _name, int singGrade,
			 int executeGrade)
	: _formName(_name)
	, _signGrade(singGrade)
	, _executeGrade(executeGrade)
	, _isSigned(false) {
	if (singGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (singGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& obj)
	: _formName(obj._formName)
	, _signGrade(obj._signGrade)
	, _executeGrade(obj._executeGrade)
	, _isSigned(obj._isSigned) {}

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
	out << "AForm name: " << obj.getName() << std::endl;
	out << "Sign grade: " << obj.getSignGrade() << std::endl;
	out << "Execute grade: " << obj.getExecuteGrade()
		<< std::endl;
	out << "Is signed: " << obj.getIsSigned() << std::endl;
	return out;
}

const std::string AForm::getName() const { return _formName; }

int AForm::getSignGrade() const { return _signGrade; }

int AForm::getExecuteGrade() const { return _executeGrade; }

bool AForm::getIsSigned() const { return _isSigned; }

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	std::cout << executor.getName() << " executes "
			  << this->getName() << std::endl;
	this->executeAction();
}