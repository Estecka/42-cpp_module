/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:43:44 by abaur             #+#    #+#             */
/*   Updated: 2021/03/30 15:26:27 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

#pragma clang diagnostic ignored "-Wunused-function"

static void	TestClapTrap();
static void	TestScavTrap();
static void	TestFragTrap();
static void	TestNinjaTrap();
static void	TestSuperTrap();

extern int	main(){
	#if defined(alltrap) || defined(claptrap)
	TestClapTrap();
	#endif
	#if defined(alltrap) || defined(fragtrap)
	TestFragTrap();
	#endif
	#if defined(alltrap) || defined(scavtrap)
	TestScavTrap();
	#endif
	#if defined(alltrap) || defined(ninjatrap)
	TestNinjaTrap();
	#endif
	#if defined(alltrap) || defined(supertrap)
	TestSuperTrap();
	#endif
}

static void	TestClapTrap(){
	std::cout << std::endl << "======== CL4P-TP ========" << std::endl;

	ClapTrap clap("TR4P-CP");

	clap.showStats();

	std::cout << std::endl << "==Healing==" << std::endl;
	clap.takeDamage(0);
	clap.beRepaired(100);
	clap.takeDamage(5);
	clap.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	clap.meleeAttack("that guy over there");
	clap.rangedAttack("their neighbourg");

	std::cout << std::endl << "==death==" << std::endl;
	clap.takeDamage(9999);
	clap.takeDamage(9999);
	clap.meleeAttack("the Mayor");
	clap.rangedAttack("the President");

	std::cout << std::endl;
}

static void	TestFragTrap(){
	std::cout << std::endl << "======== FR4G-TP ========" << std::endl;

	FragTrap frag("F1LE-TP");
	ClapTrap& clap = frag;

	frag.showStats();

	std::cout << std::endl << "==Healing==" << std::endl;
	clap.takeDamage(4);
	clap.beRepaired(100);
	clap.takeDamage(25);
	clap.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	clap.meleeAttack("that guy over there");
	clap.rangedAttack("their neighbourg");

	std::cout << std::endl << "==vault_hunter.exe==" << std::endl;
	frag.vaulthunter_dot_exe("Willis");
	frag.vaulthunter_dot_exe("the whole city");
	frag.vaulthunter_dot_exe("PewDiePie");
	frag.vaulthunter_dot_exe("a passerby");
	frag.vaulthunter_dot_exe("the final boss");

	std::cout << std::endl << "==death==" << std::endl;
	frag.takeDamage(9999);
	frag.takeDamage(9999);
	frag.meleeAttack("the Mayor");
	frag.rangedAttack("the President");
	frag.vaulthunter_dot_exe("the President");

	std::cout << std::endl;
}

static void	TestScavTrap(){
	std::cout << std::endl << "======== SC4V-TP ========" << std::endl;

	ScavTrap scav("H0T-TP");
	ClapTrap& clap = scav;

	scav.showStats();

	std::cout << std::endl << "==Healing==" << std::endl;
	clap.takeDamage(3);
	clap.beRepaired(100);
	clap.takeDamage(25);
	clap.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	clap.meleeAttack("that guy over there");
	clap.rangedAttack("their neighbourg");

	std::cout << std::endl << "==challenger==" << std::endl;
	scav.challengeNewcomer();
	scav.challengeNewcomer();
	scav.challengeNewcomer();

	std::cout << std::endl << "==death==" << std::endl;
	scav.takeDamage(9999);
	scav.takeDamage(9999);
	scav.meleeAttack("the Mayor");
	scav.rangedAttack("the President");
	scav.challengeNewcomer();

	std::cout << std::endl;
}

static void	TestNinjaTrap(){
	std::cout << std::endl << "======== N1NJ4-TP ========" << std::endl;

	NinjaTrap ninja("N4RU-TP");
	ClapTrap& clap = ninja;

	ninja.showStats();

	std::cout << std::endl << "==Healing==" << std::endl;
	clap.takeDamage(0);
	clap.takeDamage(5);
	clap.beRepaired(100);
	clap.takeDamage(25);
	clap.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	clap.meleeAttack("that guy over there");
	clap.rangedAttack("their neighbourg");

	std::cout << std::endl << "==Ninja Shoe-box==" << std::endl;
	ClapTrap* oclap = new ClapTrap();
	FragTrap* ofrag = new FragTrap();
	ScavTrap* oscav = new ScavTrap();
	NinjaTrap* onin = new NinjaTrap();
	std::cout << std::endl;
	ninja.ninjaShoebox(*oclap);
	ninja.ninjaShoebox(*ofrag);
	ninja.ninjaShoebox(*oscav);
	ninja.ninjaShoebox(*onin);
	ninja.ninjaShoebox(ninja);
	std::cout << std::endl;
	delete oclap;
	delete ofrag;
	delete oscav;
	delete onin;

	std::cout << std::endl << "==death==" << std::endl;
	ninja.takeDamage(9999);
	ninja.takeDamage(9999);
	ninja.meleeAttack("the Mayor");
	ninja.rangedAttack("the President");
	ninja.ninjaShoebox(ninja);

	std::cout << std::endl;
}

static void	TestSuperTrap(){
	std::cout << std::endl << "======== 2UP3R-TP ========" << std::endl;

	SuperTrap super("SoupErr0r");
	ClapTrap& clap = super;
	FragTrap& frag = super;
	NinjaTrap& ninja = super;

	super.showStats();

	std::cout << std::endl << "==Healing==" << std::endl;
	clap.takeDamage(0);
	frag.takeDamage(5);
	ninja.beRepaired(100);
	super.takeDamage(25);
	super.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	clap.meleeAttack("that guy over there");
	frag.meleeAttack("that guy over there");
	ninja.meleeAttack("that guy over there");
	super.meleeAttack("that guy over there");

	clap.rangedAttack("their neighbourg");
	frag.rangedAttack("their neighbourg");
	ninja.rangedAttack("their neighbourg");
	super.rangedAttack("their neighbourg");

	std::cout << std::endl << "==vault_hunter.exe==" << std::endl;
	frag.vaulthunter_dot_exe("Willis");
	frag.vaulthunter_dot_exe("the whole city");
	super.vaulthunter_dot_exe("PewDiePie");
	super.vaulthunter_dot_exe("a passerby");
	super.vaulthunter_dot_exe("the final boss");

	std::cout << std::endl << "==Ninja Shoe-box==" << std::endl;
	ClapTrap* oclap = new ClapTrap();
	FragTrap* ofrag = new FragTrap();
	ScavTrap* oscav = new ScavTrap();
	NinjaTrap* onin = new NinjaTrap();
	std::cout << std::endl;
	ninja.ninjaShoebox(*oclap);
	ninja.ninjaShoebox(*ofrag);
	super.ninjaShoebox(*oscav);
	super.ninjaShoebox(*onin);
	super.ninjaShoebox(ninja);
	std::cout << std::endl;
	delete oclap;
	delete ofrag;
	delete oscav;
	delete onin;

	std::cout << std::endl << "==death==" << std::endl;
	super.takeDamage(9999);
	ninja.takeDamage(9999);
	frag.meleeAttack("the Mayor");
	clap.rangedAttack("the President");
	super.ninjaShoebox(ninja);

	std::cout << std::endl;
}
