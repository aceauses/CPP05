#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
	/* data */
	const std::string _formName;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;

public:
	Form();
	Form(const std::string name, int signGrade, int executeGrade);
	Form(const Form &obj);
	~Form();
	void beSigned(Bureaucrat &bureaucrat);
	const std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool getIsSigned() const;
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade to high";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade to low";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &obj);