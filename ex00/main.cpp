/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 04:04:03 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/10 04:22:59 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Alice", 50);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << b1 << std::endl;

		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;

		// Throw GradeTooLowException
		// b2.decrementGrade();
		b2.incrementGrade();
		std::cout << b2 << std::endl;

		// Uncommenting the following lines will throw exceptions
		Bureaucrat b3("Charlie", 0); // GradeTooHighException
		// Bureaucrat b4("Dave", 151); // GradeTooLowException

	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}