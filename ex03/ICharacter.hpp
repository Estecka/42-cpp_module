/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:37:16 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 18:38:11 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

#include <iostream>

class ICharacter
{
public:
	virtual ~ICharacter() {}

	virtual const std::string&	getName() const = 0;

	virtual bool	equip(AMateria* m) = 0;
	virtual AMateria*	unequip(int idx) = 0;
	virtual bool	use(int idx, ICharacter& target) = 0;
};

#endif
