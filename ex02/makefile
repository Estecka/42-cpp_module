HDRS = \
	Base.hpp \
	A.hpp \
	B.hpp \
	C.hpp \

SRCS = \
	main.cpp \
	Base.cpp \
	A.cpp \
	B.cpp \
	C.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = identification.out

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
