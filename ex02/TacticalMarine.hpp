/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:20:43 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 17:18:04 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ASpaceMarine.hpp"

#include <iostream>

class TacticalMarine : public ASpaceMarine
{
public:
	TacticalMarine(void);
	TacticalMarine(const TacticalMarine&);
	~TacticalMarine();
	
	TacticalMarine&	operator=(const TacticalMarine&);

	ISpaceMarine*	clone() const;
	void	battleCry() const;
	void	rangedAttack() const;
	void	meleeAttack() const;

	void	report() const;
};

#endif
