#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
private:
	/* data */
	const std::string _formName;
	const int _signGrade;
	const int _executeGrade;
	bool _isSigned;

public:
	AForm();
	AForm(const std::string name, int signGrade, int executeGrade);
	AForm(const AForm &obj);
	~AForm();
	void beSigned(Bureaucrat &bureaucrat);
	const std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	virtual bool getIsSigned() const = 0;
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

std::ostream &operator<<(std::ostream &out, const AForm &obj);