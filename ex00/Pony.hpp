/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:07:43 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 01:23:45 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony {
public:
	std::string	name;
	std::string	robeColour;

	Pony(std::string name, std::string robeColour);
	~Pony();

	bool	Sleep();
	bool	WakeUp();
	bool	Jump();
	bool	Walk();
	bool	Run();
	void	Shine();
	void	Transcend();

private:
	bool	isAlive;
	bool	isAwake;
	unsigned int	legsBroken;
	void	BreakALeg();
};

#endif