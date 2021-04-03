/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:11:56 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 14:13:56 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "Enemy.hpp"

class NinjaTrap : public Enemy
{
public:
	NinjaTrap(void);
	NinjaTrap(const NinjaTrap&);
	~NinjaTrap();
	NinjaTrap&	operator =(const NinjaTrap&);

	virtual void	takeDamage(int amount);
};

#endif
