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

NAMES = squad.out squad++.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAMES}

squad.out: ${OBJS} main.o
	${CXX} -o squad.out main.o ${OBJS} ${CPPFLAGS}
squad++.out: ${OBJS} main++.o
	${CXX} -o squad++.out main++.o ${OBJS} ${CPPFLAGS}

${OBJS} main.o main++.o: ${HDRS}

clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all
