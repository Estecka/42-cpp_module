/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:51:56 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 18:21:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
public:
	Human(void);
	~Human();

	std::string	identify();
	const Brain&	getBrain();

	void	Think();
	void	Eat();
	void	Sleep();

private:
	const Brain	brain;
	float	time_to_die;
	std::string	status;
};

#endif
