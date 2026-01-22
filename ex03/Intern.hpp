/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:44:10 by aboumall          #+#    #+#             */
/*   Updated: 2026/01/22 21:02:00 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#define nullptr 0

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
	private:
		typedef AForm* (*FormCreator)(const std::string &target);
		static AForm *createShrubberyCreationForm(const std::string &target);
		static AForm *createRobotomyRequestForm(const std::string &target);
		static AForm *createPresidentialPardonForm(const std::string &target);
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		
		Intern &operator=(const Intern &other);
		
		AForm *makeForm(const std::string &formName, const std::string &target) const;
};

std::ostream &operator<<(std::ostream &out, const Intern &intern);

#endif