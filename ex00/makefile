HDRS = \
	Sorcerer.hpp \
	Victim.hpp \
	Peon.hpp \

SRCS = \
	Sorcerer.cpp \
	Victim.cpp \
	Peon.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = sorcerer.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: sorcerer.out sorcerer++.out

sorcerer.out: ${OBJS} main.o
	${CXX} -o sorcerer.out main.o ${OBJS} ${CPPFLAGS}
sorcerer++.out: ${OBJS} main++.o
	${CXX} -o sorcerer++.out main++.o ${OBJS} ${CPPFLAGS}

${OBJS}: ${HDRS}

all: ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all
