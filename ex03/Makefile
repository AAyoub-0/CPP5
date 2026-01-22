# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 15:52:18 by aboumall          #+#    #+#              #
#    Updated: 2026/01/22 20:43:22 by aboumall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS = Bureaucrat.hpp AForm.hpp \
		  PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp \
		  Intern.hpp

TARGET = intern

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ) $(HEADERS)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
