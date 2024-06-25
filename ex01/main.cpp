#include "Bureaucrat.hpp"
#define GRADE_MIN 150
#define GRADE_MAX 1

int main()
{
	try
	{
		Form f1("Form1", GRADE_MIN, GRADE_MIN);
		Form f2("Form2", 150, 130);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		Bureaucrat b1("Bureaucrat1", GRADE_MIN);
		Bureaucrat b2("Bureaucrat2", 100);
		b1.signForm(f1);
		b2.signForm(f2);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "---------------------" << std::endl;
		Form f1("Form1", GRADE_MIN, GRADE_MIN);
		Form f2("Form2", 140, 130);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		Bureaucrat b1("Bureaucrat1", GRADE_MIN);
		Bureaucrat b2("Bureaucrat2", 150);
		b1.signForm(f1);
		b2.signForm(f2);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}