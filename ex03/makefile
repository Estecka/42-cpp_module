HDRS = \
	ICharacter.hpp \
	IMateriaSource.hpp \
	AMateria.hpp \
	Character.hpp \
	Cure.hpp \
	Ice.hpp \
	MateriaSource.hpp \

SRCS = \
	AMateria.cpp \
	Character.cpp \
	Cure.cpp \
	Ice.cpp \
	MateriaSource.cpp \

OBJS = ${SRCS:.cpp=.o}

NAMES = bocalFantasy.out bocalFantasy++.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAMES}

bocalFantasy.out: ${OBJS} main.o
	${CXX} -o bocalFantasy.out main.o ${OBJS} ${CPPFLAGS}
bocalFantasy++.out: ${OBJS} main++.o
	${CXX} -o bocalFantasy++.out main++.o ${OBJS} ${CPPFLAGS}

${OBJS} main.o main++.o: ${HDRS}

# For some reason, the `.test` pre-extension is absolutely needed.
# The rule breaks completely if the files are named `.hpp.cpp` and `.hpp.o`.
headers_test: ${HDRS:.hpp=.hpp.test.o}
${HDRS:.hpp=.hpp.test.cpp}: ${HDRS}
	cp ${@F:.hpp.test.cpp=.hpp} ${@F} ;

clean:
	rm -f *.o
	rm -f *.hpp.test.cpp

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all
