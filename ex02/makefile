HDRS = \
	Account.class.hpp \

SRCS = \
	test.cpp \
	Account.class.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = globalbankster.out

CPPFLAGS = -Wall -Wextra -std=c++98
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
