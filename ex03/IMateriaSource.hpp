/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:45:47 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 18:46:09 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

#include <iostream>

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}

	virtual void learnMateria(const AMateria*) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif
