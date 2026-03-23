/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 04:04:03 by aboumall          #+#    #+#             */
/*   Updated: 2026/03/23 16:04:53 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void print_space() {
	std::cout << "----------------------------------------" << std::endl;
}

int main() {
	try {
		Bureaucrat bob("Bob", 33);
		Bureaucrat alice("Alice", 1);

		print_space();

		std::cout << bob << std::endl;
		std::cout << alice << std::endl;	
		
		print_space();

		// test exceptions
		bob.incrementGrade();
		alice.decrementGrade();

		print_space();

		std::cout << bob << std::endl;
		std::cout << alice << std::endl;

		print_space();

		ShrubberyCreationForm form1("Home");
		RobotomyRequestForm form2("Bender");
		PresidentialPardonForm form3("Fry");

		print_space();

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;

		print_space();

		bob.signForm(form1);
		bob.executeForm(form1);
		
		print_space();

		alice.signForm(form2);
		alice.executeForm(form2);

		print_space();

		alice.signForm(form3);
		alice.executeForm(form3);

		print_space();

		// Test Intern
		Intern someIntern;

		AForm* test;
		test = someIntern.makeForm("robotomy request", "Bender");

		print_space();

		alice.signForm(*test);
		alice.executeForm(*test);

		print_space();

		delete test;
		test = someIntern.makeForm("shrubbery creation", "Home");
		
		print_space();

		bob.signForm(*test);
		bob.executeForm(*test);

		print_space();

		delete test;
		test = someIntern.makeForm("presidential pardon", "Fry");
		
		print_space();

		alice.signForm(*test);
		alice.executeForm(*test);

		print_space();

		delete test;
		test = someIntern.makeForm("unknown form", "Target");

		print_space();
		
		delete test;

	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}