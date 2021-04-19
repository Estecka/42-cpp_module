HDRS = \
	span.hpp \

SRCS = \
	main.cpp \
	span.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = span.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} -o ${NAME} ${OBJS} ${CPPFLAGS}

${OBJS}: ${HDRS}

clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all \
