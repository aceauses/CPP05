#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
	, _target("Default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(
	std::string const& target)
	: AForm("ShrubberyCreationForm", 145, 137)
	, _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& src)
	: AForm(src), _target(src._target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const& rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream outFile((_target + "_shrubbery").c_str(),
						  std::ios::trunc | std::ios::out);

	if (outFile.is_open()) {
		outFile << "    *    " << std::endl;
		outFile << "   ***   " << std::endl;
		outFile << "  *****  " << std::endl;
		outFile << " ******* " << std::endl;
		outFile << "*********" << std::endl;
		outFile << "    |    " << std::endl;
		outFile << std::endl;
		outFile << "  *****  " << std::endl;
		outFile << " ******* " << std::endl;
		outFile << "*********" << std::endl;
		outFile << " ******* " << std::endl;
		outFile << "  *****  " << std::endl;
		outFile << "    |    " << std::endl;
	} else {
		std::cerr << "[ERROR] Couldn't open the file"
				  << _target + "_shrubbery" << std::endl;
	}
}
