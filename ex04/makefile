HDRS = \
	IAsteroid.hpp \
	IMiningLaser.hpp \
	Asteroid.hpp \
	Comet.hpp \
	DeepCoreMiner.hpp \
	MiningBarge.hpp \
	StripMiner.hpp \

SRCS = \
	main.cpp \
	Asteroid.cpp \
	Comet.cpp \
	DeepCoreMiner.cpp \
	MiningBarge.cpp \
	StripMiner.cpp \

OBJS = ${SRCS:.cpp=.o}

NAME = spaceMinerAdventures.out

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} -o ${NAME} ${OBJS} ${CPPFLAGS}

${OBJS}: ${HDRS}

# For some reason, the `.test` pre-extension is absolutely needed.
# The rule breaks completely if the files are named `.hpp.cpp` and `.hpp.o`.
headers_test: ${HDRS:.hpp=.hpp.test.o}
${HDRS:.hpp=.hpp.test.cpp}: ${HDRS}
	cp ${@F:.hpp.test.cpp=.hpp} ${@F} ;

clean:
	rm -f *.o
	rm -f *.hpp.cpp
	rm -f *.hpp.test.cpp

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all \
	header_test \
