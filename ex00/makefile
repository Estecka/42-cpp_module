HDRS = \
	conversions.hpp \

SRCS = \
	main.cpp \
	char.cpp \
	int.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = convert

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
