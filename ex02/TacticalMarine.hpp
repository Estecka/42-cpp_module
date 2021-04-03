/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:20:43 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 15:52:28 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

#include <iostream>

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine(void);
	TacticalMarine(const TacticalMarine& other);
	~TacticalMarine();
	
	TacticalMarine&	operator=(const TacticalMarine& other);

	ISpaceMarine*	clone() const;
	void	battleCry() const;
	void	rangedAttack() const;
	void	meleeAttack() const;

	void	report() const;

private:
	std::string	codeName;
	unsigned	uid;
};

#endif
