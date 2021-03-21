/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:04:41 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 19:30:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(const char* name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon& weapon);

private:
	/*
	* Must be a pointer. If it were a reference, the given constructor would ha
	* ve to leave it uninitialised.
	*/
	Weapon*	weapon;
	const char*	name;
};

#endif
