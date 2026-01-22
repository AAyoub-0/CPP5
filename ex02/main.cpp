/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 04:04:03 by aboumall          #+#    #+#             */
/*   Updated: 2026/01/22 20:37:35 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void print_space() {
	std::cout << "----------------------------------------" << std::endl;
}

int main() {
	try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat alice("Alice", 44);

		print_space();

		std::cout << bob << std::endl;
		std::cout << alice << std::endl;	
		
		print_space();

		// test exceptions
		
		// bob.incrementGrade();
		// alice.decrementGrade();

		print_space();

		std::cout << bob << std::endl;
		std::cout << alice << std::endl;

		print_space();

		AForm *form1 = new PresidentialPardonForm("Target1");
		AForm *form2 = new RobotomyRequestForm("Target2");
		AForm *form3 = new ShrubberyCreationForm("Target3");

		print_space();

		std::cout << *form1 << std::endl;

		print_space();

		std::cout << *form2 << std::endl;

		print_space();

		std::cout << *form3 << std::endl;

		print_space();

		bob.signForm(*form1);
		print_space();
		alice.signForm(*form2);
		print_space();
		bob.signForm(*form3);

		print_space();

		bob.executeForm(*form1);
		print_space();
		alice.executeForm(*form2);
		print_space();
		bob.executeForm(*form3);
		
		print_space();

		delete form1;
		delete form2;
		delete form3;

	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}