/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:07:43 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 20:49:04 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony {
public:

	std::string	name;
	std::string	robeColor;

	Pony(std::string name, std::string robeColor);
	Pony(void);
	~Pony();

	bool	isAlive;
	bool	isAwake;

	float	distanceWalked;
	unsigned int	legsBroken;


	bool	Sleep();
	bool	WakeUp();
	bool	Jump();
	float	Walk(float distance);
	float	Run(float distance);
	void	Shine();
	void	Transcend();

private:
	void	BreakALeg();
};

#endif