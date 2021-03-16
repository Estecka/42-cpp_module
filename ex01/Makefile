HDRS = contact.hpp \

SRCS = main.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = phonebook

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

${NAME}: ${OBJS}
	${CXX} -o ${NAME} ${OBJS} ${CPPFLAGS}

all: ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean all
