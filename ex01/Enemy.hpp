/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:14:31 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 18:33:00 by abaur            ###   ########.fr       */
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
	~Enemy();
	Enemy&	operator =(const Enemy&);

	std::string	getType() const;
	int	getHP() const;

	virtual void	takeDamage(int amount);

protected:
	std::string	type;
	int	healthPoints;

	std::string	deathCry;

private:
	Enemy(void);
};

#endif