/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:33:05 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 23:38:43 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <iostream>

#define INVMAX	4

class Character : public ICharacter
{
public:
	Character(void);
	Character(const Character&);
	Character(const std::string& name);
	~Character();
	Character&	operator=(const Character&);

	const std::string&	getName() const;

	void	status() const;

	bool	equip(AMateria* item);
	AMateria*	unequip(int index);
	bool	use(int index, ICharacter& target);

private:
	std::string	name;

	AMateria*	inventory[INVMAX];
	int	invCount;
};

#endif
