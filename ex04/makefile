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

headers_test: ${HDRS:.hpp=.hpp.o}
${HDRS:.hpp=.hpp.cpp}: ${HDRS}
	cp ${@F:.hpp.cpp=.hpp} ${@F}

# Why is this needed ? Only God knows.
# It's never called at all, it shouldn't have to be ever called,
# and yet `header_test` breaks completely without it.
${HDRS}:
	echo "Beep "${@F};

clean:
	rm -f *.o
	rm -f *.hpp.cpp

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all \
	header_test \
