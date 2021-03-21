HDRS = \
	Brain.hpp \
	Human.hpp \

SRCS = main.cpp \
	Brain.cpp \
	Human.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = HUMAN.out

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
