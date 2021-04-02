/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:14:31 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 17:59:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy
{
public:
	Enemy(const Enemy&);
	Enemy(int hp, const std::string& type);
	virtual ~Enemy();
	Enemy&	operator =(const Enemy&);

	std::string	getType() const;
	int	getHP() const;
	int	getHPMax() const;

	virtual void	takeDamage(int amount);

protected:
	std::string	type;
	int	healthPoints;
	int	healthPointsMax;

	std::string	deathCry;

private:
	Enemy(void);
};

#endif
