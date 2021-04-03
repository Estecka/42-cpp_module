/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:05:50 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 23:27:28 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEPCOREMINER_HPP
#define DEEPCOREMINER_HPP

#include "IMiningLaser.hpp"


class DeepCoreMiner : public IMiningLaser
{
public:
	DeepCoreMiner(void);
	DeepCoreMiner(const DeepCoreMiner&);
	~DeepCoreMiner();
	DeepCoreMiner& operator=(const DeepCoreMiner&);

	std::string	getName();

	std::string	mine(IAsteroid* target);
};

#endif
