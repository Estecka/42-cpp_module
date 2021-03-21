#include "Brain.hpp"
#include "Human.hpp"

extern int	main(){
	Human	bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}
