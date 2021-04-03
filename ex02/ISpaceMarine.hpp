/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:05:55 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 17:06:52 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
#define ISPACEMARINE_HPP

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine() {}

	virtual ISpaceMarine*	clone() const = 0;

	virtual void	battleCry() const = 0;
	virtual void	rangedAttack() const = 0;
	virtual void	meleeAttack() const = 0;

	virtual void	report() const = 0;
};

#endif
