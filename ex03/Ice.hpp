/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:28:28 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 15:55:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice&);
	~Ice();
	Ice&	operator=(const Ice&);

	AMateria*	clone() const;
	void	use(ICharacter& target);
	void	status() const;

protected:
	const std::string&	type() const;
};

#endif
