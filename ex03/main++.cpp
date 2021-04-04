#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

#include "Cure.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

static const Ice	defaultIce;
static const Cure	defaultCure;


int main()
{
	MateriaSource	src;
	MateriaSource	fullIce;
	MateriaSource	fullCure;

	AMateria* item;

	Character* salty = new Character("salty");
	Character* jpeg = NULL;

	src.learnMateria(&defaultCure);
	src.learnMateria(&defaultIce);
	src.learnMateria(&defaultIce);
	src.learnMateria(&defaultCure);

	fullIce.learnMateria(&defaultIce);
	fullIce.learnMateria(&defaultIce);
	fullIce.learnMateria(&defaultIce);
	fullIce.learnMateria(&defaultIce);
	fullIce.learnMateria(&defaultCure);

	fullCure.learnMateria(&defaultCure);
	fullCure.learnMateria(&defaultCure);
	fullCure.learnMateria(&defaultCure);
	fullCure.learnMateria(&defaultCure);
	fullCure.learnMateria(&defaultIce);

	std::cout << std::endl << "Salty has joined the game." << std::endl;
	salty->status();

	std::cout << std::endl << "Salty gets materia from the wrong shop." << std::endl;
	salty->equip(fullIce.createMateria("cure"));
	salty->equip(fullCure.createMateria("ice"));
	salty->status();

	std::cout << std::endl << "Salty gets materia from the right shop." << std::endl;
	salty->equip(src.createMateria("cure"));
	salty->equip(src.createMateria("ice"));
	salty->equip(src.createMateria("cure"));
	salty->status();

	std::cout << std::endl << "Jpeg has joined the game." << std::endl;
	jpeg = new Character(*salty);
	*((std::string*)&jpeg->getName()) = "jpeg";
	jpeg->status();

	std::cout << std::endl << "Salty bullies jpeg." << std::endl;
	salty->use(0, *jpeg);
	salty->use(1, *jpeg);
	salty->use(2, *jpeg);
	salty->use(3, *jpeg);
	salty->status();

	std::cout << std::endl \
		<< "Salty offers one of his Materia to Jpeg." << std::endl \
		<< "Jpeg throws away an old materia." << std::endl\
		;
	delete jpeg->unequip(2);
	jpeg->equip(salty->unequip(0));
	jpeg->status();
	salty->status();

	std::cout << std::endl << "Jpeg tries to dupe Materias." << std::endl;
	item = jpeg->unequip(1);
	jpeg->equip(item);
	jpeg->equip(item);
	item = NULL;
	jpeg->status();

	std::cout << std::endl << "Salty tries to flood his inventory." << std::endl;
	for (int i=0; i<10; i++) {
		item = src.createMateria("cure");
		if (!salty->equip(item))
			delete item;
	}
	item = NULL;
	salty->status();

	std::cout << std::endl << "Jpeg tries to crash the game." << std::endl;
	jpeg->equip(NULL);
	jpeg->equip(src.createMateria("instadeath"));
	jpeg->status();

	delete jpeg;
	delete salty;
	return 0;
}
