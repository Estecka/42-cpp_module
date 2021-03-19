/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:07:43 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 17:03:24 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony {
public:
	Pony(std::string name, std::string robeColour);
	~Pony();

	bool	Sleep();
	bool	WakeUp();
	bool	Jump();
	bool	Walk();
	bool	Run();
	void	Shine();
	void	Transcend();

	std::string	GetName();
	std::string	GetRobeColour();
	int        	GetHealth();
	bool       	IsAlive();
	bool       	IsAwake();

private:
	std::string	name;
	std::string	robeColour;
	bool       	isAwake;
	unsigned   	legsBroken;

	void	BreakALeg();
};

#endif