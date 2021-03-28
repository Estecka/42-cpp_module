HDRS = \
	ClapTrap.hpp \
	FragTrap.hpp \
	ScavTrap.hpp \
	NinjaTrap.hpp \

SRCS = \
	ClapTrap.cpp \
	FragTrap.cpp \
	ScavTrap.cpp \
	NinjaTrap.cpp \

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: alltrap.out claptrap.out fragtrap.out scavtrap.out ninjatrap.out

alltrap.out claptrap.out fragtrap.out scavtrap.out ninjatrap.out: ${OBJS} main.cpp
	${CXX} -o ${@F} ${OBJS} main.cpp ${CPPFLAGS} -D ${@F:.out=}

${OBJS}: ${HDRS}

all: ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all
