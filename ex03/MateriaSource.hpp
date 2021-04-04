/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:43:44 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 18:49:43 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#include <iostream>

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource&);
	~MateriaSource();
	MateriaSource&	operator=(const MateriaSource&);

	void	learnMateria(const AMateria*);
	AMateria*	createMateria(const std::string& type);

private:
	AMateria*	inventory[4];
	int	invCount;
};

#endif
