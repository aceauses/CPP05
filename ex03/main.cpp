#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp"
#define GRADE_MIN 150
#define GRADE_MAX 1

int main() {
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("presidential pardon",
									"Bender");

	Bureaucrat b1("Bureaucrat1", GRADE_MAX);

	std::cout << b1 << std::endl;

	try {
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}