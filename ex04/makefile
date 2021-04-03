HDRS = \
	IAsteroid.hpp \
	IMiningLaser.hpp \
	DeepCoreMiner.hpp \
	StripMiner.hpp \
	AsteroKreog.hpp \
	KoalaSteroid.hpp \
	MiningBarge.hpp \

SRCS = \
	main.cpp \
	DeepCoreMiner.hpp \
	StripMiner.hpp \
	AsteroKreog.hpp \
	KoalaSteroid.hpp \
	MiningBarge.hpp \

OBJS = ${SRCS:.cpp=.o}

NAME = spaceMinerAdventures.out

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

.PHONY: all clean fclean all
