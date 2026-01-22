/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:59:27 by aboumall          #+#    #+#             */
/*   Updated: 2026/01/22 19:58:18 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm parameterized constructor called for target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called for target: " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called for target: " << _target << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!isSigned())
		throw std::runtime_error("AForm is not signed");
	if (executor.getGrade() > getExecuteGrade())
		throw std::runtime_error("Bureaucrat grade too low to execute the form");

	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile) {
		throw std::runtime_error("Failed to create file: " + _target + "_shrubbery");
	}

	outfile << "       _-_\n"
			   "    /~~   ~~\\\n"
			   " /~~         ~~\\\n"
			   "{               }\n"
			   " \\  _-     -_  /\n"
			   "   ~  \\\\ //  ~\n"
			   "_- -   | | _- _\n"
			   "  _ -  | |   -_\n"
			   "      // \\\\\n";
	outfile.close();
	std::cout << "Shrubbery created at " << _target + "_shrubbery" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form) {
	os << "ShrubberyCreationForm targeting " << form.getName()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getSignGrade()
	   << ", execute grade: " << form.getExecuteGrade();
	return os;
}