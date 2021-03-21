/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:48:50 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 18:25:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain(float smoothness);
	Brain(void);
	~Brain();

	std::string	identify() const;

	void	Ponder() const;
	float	GetSmoothness() const;

private:
	float	smoothness;
};

#endif
