/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FatMan.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:33:08 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 14:42:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FATMAN_HPP
#define FATMAN_HPP

#include "AWeapon.hpp"

class FatMan : public AWeapon
{
public:
	FatMan(void);
	FatMan(const FatMan&);
	~FatMan();
	FatMan&	operator =(const FatMan&);

	virtual void	attack();

private:
	bool	isLoaded;
};

#endif
