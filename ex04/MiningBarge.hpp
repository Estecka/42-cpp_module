/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:39:02 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 02:46:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MININGBARGE_HPP
#define MININGBARGE_HPP

#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"

#define LASERMAX	4

class MiningBarge
{
public:
	MiningBarge(void);
	~MiningBarge();

	unsigned	getLaserCount() const;
	const IMiningLaser*	getLaser(unsigned index) const;

	bool	equip(IMiningLaser* item);
	IMiningLaser*	unequip(unsigned index);

	int	mine(IAsteroid* target) const;

private:
	MiningBarge(const MiningBarge&);
	MiningBarge&	operator=(const MiningBarge&);

	IMiningLaser* equipment[LASERMAX];
	unsigned	laserCount;
};

#endif
