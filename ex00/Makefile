SRCS = megaphone.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = megaphone

CFLAGS = -Wall -Wextra -Werror
CC = clang++

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} ${CFLAGS}

all: ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean all
