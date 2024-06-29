#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
class Bureaucrat;

class AForm {
private:
	/* data */
	const std::string _formName;
	const int         _signGrade;
	const int         _executeGrade;
	bool              _isSigned;
	virtual void      executeAction() const = 0;

public:
	AForm();
	AForm(const std::string name, int signGrade,
		  int executeGrade);
	AForm(const AForm& obj);
	~AForm();
	void              beSigned(Bureaucrat& bureaucrat);
	const std::string getName() const;
	int               getSignGrade() const;
	int               getExecuteGrade() const;
	virtual bool      getIsSigned() const;
	void              execute(Bureaucrat const& executor) const;
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade to high";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade to low";
		}
	};
	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form not signed";
		}
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);