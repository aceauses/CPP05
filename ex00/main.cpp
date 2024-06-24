#include "Bureaucrat.hpp"
#define GRADE_MIN 150
#define GRADE_MAX 1
int main()
{
	// try catching a lower grade exception on construction
	try
	{
		std::cout << "Trying to create a bureaucrat with a grade lower than the minimum" << std::endl;
		Bureaucrat invalid_low = Bureaucrat(GRADE_MIN + 1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// try catching a higher grade exception on construction
	try
	{
		std::cout << "Trying to create a bureaucrat with a grade higher than the maximum" << std::endl;
		Bureaucrat invalid_high = Bureaucrat(GRADE_MAX - 1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// try catching a lower grade exception on increment
	try
	{
		std::cout << "Trying to decrement a bureaucrat with a grade lower than the minimum" << std::endl;
		Bureaucrat valid = Bureaucrat(GRADE_MIN);
		valid.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// try catching a higher grade exception on increment
	try
	{
		std::cout << "Trying to increment a bureaucrat with a grade higher than the maximum" << std::endl;
		Bureaucrat valid = Bureaucrat(GRADE_MAX);
		valid.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Trying to copy a bureaucrat with a low grade and decrement" << std::endl;
		Bureaucrat valid = Bureaucrat(GRADE_MIN);
		Bureaucrat copy = Bureaucrat(valid);
		std::cout << "Original: " << valid.getGrade() << std::endl;
		std::cout << "Copy: " << copy.getGrade() << std::endl;
		copy.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "The subject example" << std::endl;
		Bureaucrat valid = Bureaucrat(3);
		std::cout << valid << std::endl;
		valid.incrementGrade();
		std::cout << valid << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}