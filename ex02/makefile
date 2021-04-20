HDRS = \
	mutantstack.hpp \

SRCS = \
	mutantstack.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = mutantstack.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAME} subject.out

${NAME}: ${HDRS} ${OBJS} main.o
	${CXX} -o ${NAME} main.o ${OBJS} ${CPPFLAGS}

subject.out: ${HDRS} ${OBJS} main.subject.o
	${CXX} -o subject.out main.subject.o ${OBJS} ${CPPFLAGS}


clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all \
