HDRS = \
	AWeapon.hpp \
	Character.hpp \
	Enemy.hpp \
	FatMan.hpp \
	NinjaTrap.hpp \
	PlasmaRifle.hpp \
	PowerFist.hpp \
	RadScorpion.hpp \
	SuperMutant.hpp \

SRCS = \
	AWeapon.cpp \
	Character.cpp \
	Enemy.cpp \
	FatMan.cpp \
	NinjaTrap.cpp \
	PlasmaRifle.cpp \
	PowerFist.cpp \
	RadScorpion.cpp \
	SuperMutant.cpp \

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: subject.out falloutAdventures.out

subject.out: ${OBJS} main.subject.o
	${CXX} -o subject.out main.subject.o ${OBJS} ${CPPFLAGS}

falloutAdventures.out: ${OBJS} main.adventure.o
	${CXX} -o falloutAdventures.out main.adventure.o ${OBJS} ${CPPFLAGS}

${OBJS} main.subject.o main.adventure.o: ${HDRS}

clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all
