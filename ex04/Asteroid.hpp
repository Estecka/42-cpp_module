/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:28:01 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 01:24:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "IAsteroid.hpp"

class StripMiner;
class DeepCoreMiner;

class Asteroid : public IAsteroid 
{
public:
	Asteroid(void);
	Asteroid(const Asteroid&);
	~Asteroid();
	Asteroid&	operator=(const Asteroid&);

	std::string getName() const;

	std::string beMined(const StripMiner*) const;
	std::string beMined(const DeepCoreMiner*) const;
};

#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"

#endif
