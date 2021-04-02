/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:03:56 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 14:05:10 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant(void);
	SuperMutant(const SuperMutant&);
	~SuperMutant();
	SuperMutant&	operator =(const SuperMutant&);

	virtual void	takeDamage(int amount);
};

#endif
