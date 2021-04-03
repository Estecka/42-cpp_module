/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:07:23 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 17:17:12 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ASPACEMARINE_HPP
#define	ASPACEMARINE_HPP

#include "ISpaceMarine.hpp"

#include <iostream>

class ASpaceMarine : public ISpaceMarine
{
public:
	ASpaceMarine(void);
	ASpaceMarine(const ASpaceMarine&);
	virtual ~ASpaceMarine();
	ASpaceMarine&	operator=(const ASpaceMarine&);

	virtual ISpaceMarine*	clone() const;

	virtual void	battleCry() const = 0;
	virtual void	rangedAttack() const = 0;
	virtual void	meleeAttack() const = 0;
	virtual void	report() const = 0;

protected:
	std::string	codeName;
	unsigned	uid;
};


#endif
