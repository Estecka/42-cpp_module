/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:28:01 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 23:30:42 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "IAsteroid.hpp"

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

#endif
