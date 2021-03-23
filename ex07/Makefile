HDRS = \
	StreamCrawler.hpp \

SRCS = main.cpp \
	StreamCrawler.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = replace

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

${NAME}: ${OBJS}
	${CXX} -o ${NAME} ${OBJS} ${CPPFLAGS}

${OBJS}: ${HDRS}

all: ${NAME}

clean:
	rm -f *.o
	rm -f *.sed
	rm -f *.replace

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean all
