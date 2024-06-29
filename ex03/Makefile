CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Interns
SRCS = Bureaucrat.cpp main.cpp Intern.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re