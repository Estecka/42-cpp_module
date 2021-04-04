#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

#include "Cure.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	Ice ice;
	Cure cure;
	src->learnMateria(&ice);
	src->learnMateria(&cure);

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
