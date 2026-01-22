/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 04:04:03 by aboumall          #+#    #+#             */
/*   Updated: 2026/01/22 20:37:27 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

		Form form1("Form1", 25, 5);

		print_space();

		std::cout << form1 << std::endl;

		print_space();

		bob.signForm(form1);
		
		print_space();

		alice.signForm(form1);

		print_space();

	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}