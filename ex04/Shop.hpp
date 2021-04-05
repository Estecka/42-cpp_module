/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:09:47 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 18:19:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOP_HPP
#define SHOP_HPP

#include "IMiningLaser.hpp"

#include <iostream>

namespace Shop {
	extern const unsigned int	productCount;
	extern const IMiningLaser*const	products[];

	int	Sell(IMiningLaser&);
	int	Sell(std::string ore);
}

#endif
