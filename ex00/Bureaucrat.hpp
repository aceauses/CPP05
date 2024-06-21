#pragma once

# include <iostream>
# include <string>

class GradeTooHighException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "Grade to high";
	}
};

class GradeTooLowException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "Grade to low";
	}
};

class Bureaucrat
{
private:
	int _grade;
	const std::string _name;
public:
	Bureaucrat(const std::string _name, int _grade)
	{

	}
	~Bureaucrat();
	void getGrade();
	void getName();
};