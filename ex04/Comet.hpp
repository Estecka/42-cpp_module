/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Comet.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:30:59 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 23:31:48 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMET_HPP
#define COMET_HPP

#include "IAsteroid.hpp"

class Comet : public IAsteroid 
{
public:
	Comet(void);
	Comet(const Comet&);
	~Comet();
	Comet&	operator=(const Comet&);

	std::string getName() const;

	std::string beMined(const StripMiner*) const;
	std::string beMined(const DeepCoreMiner*) const;
};

#endif
