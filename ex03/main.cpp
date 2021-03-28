/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:43:44 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 19:15:10 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

#pragma clang diagnostic ignored "-Wunused-function"

static void	TestClapTrap();
static void	TestScavTrap();
static void	TestFragTrap();
static void	TestNinjaTrap();

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
}

static void	TestClapTrap(){
	std::cout << std::endl << "======== CL4P-TP ========" << std::endl;

	ClapTrap clap("TR4P-CP");

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


	std::cout << std::endl << "==Healing==" << std::endl;
	clap.takeDamage(5);
	clap.beRepaired(100);
	clap.takeDamage(25);
	clap.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	clap.meleeAttack("that guy over there");
	clap.rangedAttack("their neighbourg");

	std::cout << std::endl << "==challenger==" << std::endl;

	ClapTrap* oclap = new ClapTrap();
	ninja.ninjaShoebox(*oclap);
	delete oclap;
	FragTrap* ofrag = new FragTrap();
	ninja.ninjaShoebox(*ofrag);
	delete ofrag;
	ScavTrap* oscav = new ScavTrap();
	ninja.ninjaShoebox(*oscav);
	delete oscav;
	NinjaTrap* onin = new NinjaTrap();
	ninja.ninjaShoebox(*onin);
	delete onin;
	ninja.ninjaShoebox(ninja);

	std::cout << std::endl << "==death==" << std::endl;
	ninja.takeDamage(9999);
	ninja.takeDamage(9999);
	ninja.meleeAttack("the Mayor");
	ninja.rangedAttack("the President");
	ninja.ninjaShoebox(ninja);

	std::cout << std::endl;
}
