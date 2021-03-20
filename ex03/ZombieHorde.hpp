/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:57:37 by abaur             #+#    #+#             */
/*   Updated: 2021/03/20 19:09:43 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(unsigned population);
	~ZombieHorde();
	void	Announce();

private:
	unsigned	population;
	Zombie* 	horde;
};

#endif
