#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#define GRADE_MIN 150
#define GRADE_MAX 1

int main() {
	// A basic test for the ShrubberyCreationForm
	try {
		Bureaucrat            b("Bureaucrat", 137);
		ShrubberyCreationForm s("John");
		b.signForm(s);
		b.executeForm(s);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------"
			  << std::endl;
	// A basic test for PresidentialPardonForm
	try {
		Bureaucrat             b("Bureaucrat", 5);
		PresidentialPardonForm p("Alex");
		b.signForm(p);
		b.executeForm(p);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------"
			  << std::endl;
	// A basic test for RobotomyRequestForm
	try {
		Bureaucrat          b("Bureaucrat", 45);
		RobotomyRequestForm r("George");
		b.signForm(r);
		b.executeForm(r);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------"
			  << std::endl;
	return 0;
}