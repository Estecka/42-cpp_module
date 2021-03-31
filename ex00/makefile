HDRS = \
	Sorcerer.hpp \
	Victim.hpp \
	Peon.hpp \

SRCS = main.cpp \
	Sorcerer.cpp \
	Victim.cpp \
	Peon.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = sorcerer.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} -o ${NAME} ${OBJS} ${CPPFLAGS}

${OBJS}: ${HDRS}

all: ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all
