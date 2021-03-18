/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:07:43 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 21:14:29 by abaur            ###   ########.fr       */
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

	unsigned int	legsBroken;


	bool	Sleep();
	bool	WakeUp();
	bool	Jump();
	bool	Walk();
	bool	Run();
	void	Shine();
	void	Transcend();

private:
	void	BreakALeg();
};

#endif