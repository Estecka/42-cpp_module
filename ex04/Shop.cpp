/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:42:10 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 18:30:02 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shop.hpp"

static const DeepCoreMiner	factoryDeepCore;
static const StripMiner	factoryStrip;

const unsigned int	Shop::productCount = 2;

const IMiningLaser*const	Shop::products[] = {
	&factoryDeepCore,
	&factoryStrip,
	NULL
};

int	Shop::Sell(IMiningLaser& item) {
	int	worth;
	
	worth = item.getFullPrice() * item.getDurability();
	worth /= 2 * item.getDurabilityMax();
	delete &item;
	return worth;
}

int Shop::Sell(std::string material) {
	if (material == "Flavium")   return 100;
	if (material == "Dragonite") return 300;
	if (material == "Tartarite") return 400;
	if (material == "Meium")     return 1000;
	return 0;
}
