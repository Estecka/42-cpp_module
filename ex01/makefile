CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CXX=clang++

all: subject.out rendu.out


subject.out: main.cpp memoryLeak.subject.cpp
	${CXX} -o subject.out main.cpp memoryLeak.subject.cpp ${CPPFLAGS}

rendu.out: main.cpp memoryLeak.rendu.cpp
	${CXX} -o rendu.out main.cpp memoryLeak.rendu.cpp ${CPPFLAGS}


clean:
	rm -f *.o

fclean: clean
	rm -f *.out

re: fclean all

.PHONY: all clean fclean all
