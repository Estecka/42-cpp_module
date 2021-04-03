/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:51:57 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 16:09:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator(void);
	AssaultTerminator(const AssaultTerminator&);
	~AssaultTerminator();

	AssaultTerminator& operator=(const AssaultTerminator&);

	ISpaceMarine*	clone() const;
	void	battleCry() const;
	void	rangedAttack() const;
	void	meleeAttack() const;

	void	report() const;

private:
	
};

#endif
