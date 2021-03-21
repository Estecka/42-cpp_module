/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:58:08 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 19:28:13 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon
{
public:
	Weapon(const char* type);
	~Weapon();

	void	setType(const char* type);
	const char*	GetType() const;

private:
	const char*	type;
};

#endif