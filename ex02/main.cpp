/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:43:44 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 16:57:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
// #include "ScavTrap.hpp"

#pragma clang diagnostic ignored "-Wunused-function"

static void	TestClapTrap();
static void	TestScavTrap();
static void	TestFragTrap();

extern int	main(){
	TestClapTrap();
	TestScavTrap();
	TestFragTrap();
}

static void	TestClapTrap(){
	std::cout << std::endl << "======== CL4P-TP ========" << std::endl;

	ClapTrap claptrap("TR4P-CP");

	std::cout << std::endl << "==Healing==" << std::endl;
	claptrap.takeDamage(0);
	claptrap.beRepaired(100);
	claptrap.takeDamage(5);
	claptrap.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	claptrap.meleeAttack("that guy over there");
	claptrap.rangedAttack("their neighbourg");

	std::cout << std::endl << "==death==" << std::endl;
	claptrap.takeDamage(9999);
	claptrap.takeDamage(9999);
	claptrap.meleeAttack("the Mayor");
	claptrap.rangedAttack("the President");

	std::cout << std::endl;
}

static void	TestFragTrap(){
	std::cout << std::endl << "======== FR4G-TP ========" << std::endl;

	FragTrap fragtrap("F1LE-TP");
	ClapTrap& claptrap = fragtrap;

	std::cout << std::endl << "==Healing==" << std::endl;
	claptrap.takeDamage(4);
	claptrap.beRepaired(100);
	claptrap.takeDamage(25);
	claptrap.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	claptrap.meleeAttack("that guy over there");
	claptrap.rangedAttack("their neighbourg");

	std::cout << std::endl << "==vault_hunter.exe==" << std::endl;
	fragtrap.vaulthunter_dot_exe("Willis");
	fragtrap.vaulthunter_dot_exe("the whole city");
	fragtrap.vaulthunter_dot_exe("PewDiePie");
	fragtrap.vaulthunter_dot_exe("a passerby");
	fragtrap.vaulthunter_dot_exe("the final boss");

	std::cout << std::endl << "==death==" << std::endl;
	fragtrap.takeDamage(9999);
	fragtrap.takeDamage(9999);
	fragtrap.meleeAttack("the Mayor");
	fragtrap.rangedAttack("the President");
	fragtrap.vaulthunter_dot_exe("the President");

	std::cout << std::endl;
}

static void	TestScavTrap(){
	/*
	ScavTrap http("H0T-TP");

	std::cout << std::endl << "==Healing==" << std::endl;
	http.takeDamage(3);
	http.beRepaired(100);
	http.takeDamage(25);
	http.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	http.meleeAttack("that guy over there");
	http.rangedAttack("their neighbourg");

	std::cout << std::endl << "==challenger==" << std::endl;
	http.challengeNewcomer();
	http.challengeNewcomer();
	http.challengeNewcomer();

	std::cout << std::endl << "==death==" << std::endl;
	http.takeDamage(9999);
	http.takeDamage(9999);
	http.meleeAttack("the Mayor");
	http.rangedAttack("the President");
	http.challengeNewcomer();

	std::cout << std::endl;
	*/
}
