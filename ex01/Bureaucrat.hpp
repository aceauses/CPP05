#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"
class Form;

class Bureaucrat
{
private:
	int _grade;
	const std::string _name;

public:
	Bureaucrat();
	Bureaucrat(int _grade);
	Bureaucrat(const std::string _name, int _grade);
	Bureaucrat(Bureaucrat const &obj);
	Bureaucrat &operator=(const Bureaucrat &obj);
	// Stream insertion operator
	~Bureaucrat();
	int getGrade() const;
	const std::string getName() const;
	void signForm(Form &form);
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

	// member functions
	void incrementGrade();
	void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);