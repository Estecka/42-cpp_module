/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:43:44 by abaur             #+#    #+#             */
/*   Updated: 2021/03/27 15:37:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

extern int	main(){
	FragTrap ftp("F1LE-TP");

	std::cout << std::endl << "==Healing==" << std::endl;
	ftp.takeDamage(4);
	ftp.beRepaired(100);
	ftp.takeDamage(25);
	ftp.beRepaired(50);


	std::cout << std::endl << "==Basic attacks==" << std::endl;
	ftp.meleeAttack("that guy over there");
	ftp.rangedAttack("their neighbourg");

	std::cout << std::endl << "==vault_hunter.exe==" << std::endl;
	ftp.vaulthunter_dot_exe("Willis");
	ftp.vaulthunter_dot_exe("the whole city");
	ftp.vaulthunter_dot_exe("PewDiePie");
	ftp.vaulthunter_dot_exe("a passerby");
	ftp.vaulthunter_dot_exe("the final boss");

	std::cout << std::endl << "==death==" << std::endl;
	ftp.takeDamage(9999);
	ftp.takeDamage(9999);
	ftp.meleeAttack("the Mayor");
	ftp.rangedAttack("the President");
	ftp.vaulthunter_dot_exe("the President");

	std::cout << std::endl;
}