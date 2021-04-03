/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main++.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:16:21 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 19:44:08 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

#include <iostream>

extern int	main(){
	std::cout << std::endl << "== Squad 1 Init ==" << std::endl;
	Squad	squad1 = Squad();
	squad1.push(new TacticalMarine());
	squad1.push(new TacticalMarine());
	squad1.push(new AssaultTerminator());
	squad1.push(new AssaultTerminator());
	squad1.push(new AssaultTerminator());
	squad1.push(NULL);
	squad1.push(squad1.getUnit(0));
	squad1.push(squad1.getUnit(1));

	std::cout << squad1.getCount() << std::endl;
	squad1.report();

	std::cout << squad1.getUnit(-1) << " " << squad1.getUnit(999) << std::endl;

	std::cout << std::endl << "== Squad 2 copy ==" << std::endl;
	Squad	squad2 = Squad(squad1);
	squad2.report();

	std::cout << std::endl << "== Squad 1 overwrite ==" << std::endl;
	squad1 = squad2;
	squad1.report();

	std::cout << std::endl << "== End of Main ==" << std::endl;
}
