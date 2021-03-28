HDRS = \
	ClapTrap.hpp \
	FragTrap.hpp \
	ScavTrap.hpp \

SRCS = main.cpp \
	ClapTrap.cpp \
	FragTrap.cpp \
	ScavTrap.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = claptrap.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

${NAME}: ${OBJS}
	${CXX} -o ${NAME} ${OBJS} ${CPPFLAGS}

${OBJS}: ${HDRS}

all: ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean all
