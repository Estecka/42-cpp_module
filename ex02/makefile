HDRS = \
	Bureaucrat.hpp \
	GradeException.hpp \
	Form.hpp \
	PresidentialPardonForm.hpp \
	RobotomyRequestForm.hpp \
	ShrubberyCreationForm.hpp \

SRCS = \
	main.cpp \
	Bureaucrat.cpp \
	GradeException.cpp \
	Form.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = execution.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} -o ${NAME} ${OBJS} ${CPPFLAGS}

${OBJS}: ${HDRS}

headers_test: ${HDRS:.hpp=.hpp.test.o}
${HDRS:.hpp=.hpp.test.cpp}: ${HDRS}
	cp ${@F:.hpp.test.cpp=.hpp} ${@F} ;

clean:
	rm -f *.o
	rm -f *.hpp.cpp
	rm -f *.hpp.test.cpp

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all \
	header_test \
