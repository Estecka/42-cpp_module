HDRS = \
	ISquad.hpp \
	ISpaceMarine.hpp \
	ASpaceMarine.hpp \
	AssaultTerminator.hpp \
	Squad.hpp \
	TacticalMarine.hpp \

SRCS = \
	ASpaceMarine.cpp \
	AssaultTerminator.cpp \
	Squad.cpp \
	TacticalMarine.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = squad.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAME}

${NAME}: ${OBJS} main.o
	${CXX} -o ${NAME} main.o ${OBJS} ${CPPFLAGS}

${OBJS} main.o: ${HDRS}

clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all
