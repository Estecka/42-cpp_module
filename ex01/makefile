HDRS = \
	span.hpp \

SRCS = \
	span.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = span.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAME} subject.out

${NAME}: ${OBJS} ${HDRS} main.o
	${CXX} -o ${NAME} main.o ${OBJS} ${CPPFLAGS}

subject.out: ${OBJS} ${HDRS} main.subject.o
	${CXX} -o subject.out main.subject.o ${OBJS} ${CPPFLAGS}

${OBJS}: ${HDRS}

clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all \
