/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:11:00 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 18:00:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>

class AWeapon
{
public:
	AWeapon(const std::string& name, int apcost, int damage);
	AWeapon(const AWeapon&);
	virtual ~AWeapon();
	AWeapon&	operator =(const AWeapon&);

	std::string	getName() const;
	int	getAPCost() const;
	int	getDamage() const;

	virtual void	attack() const = 0;

protected:
	std::string	name;
	int	apCost;
	int	damages;

private:
	AWeapon(void);
};

#endif
