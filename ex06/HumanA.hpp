/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:02:43 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 19:43:43 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(const char* name, Weapon& weapon);
	~HumanA();

	void	attack();

private:
	/*
	* Could be either a pointer or a reference, although a reference is more in-
	* line with the given constructor.
	* Unlike a pointer, a reference enforces a non-null weapon, and would make t
	* he human unable to "drop" their weapon to pick another.
	*/
	Weapon&	weapon;
	const char*	name;
};

#endif
