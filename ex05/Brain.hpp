/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:48:50 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 17:30:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain(float initialSmoothness);
	Brain(void);
	~Brain();

	std::string	identify();

	float	Ponder();
	float	GetSmoothness();

private:
	float	smoothness;
};

#endif
