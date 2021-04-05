/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:09:47 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 17:41:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMiningLaser.hpp"

#include <iostream>

namespace Shop {
	static const DeepCoreMiner	factoryDeeCore;
	static const DeepCoreMiner	factoryStrip;

	const IMiningLaser*const	products[] = {
		&factoryDeeCore,
		&factoryStrip,
		NULL
	};

	int	Sell(IMiningLaser*);
	int	Sell(std::string ore);
}
