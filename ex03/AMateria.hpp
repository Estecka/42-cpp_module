/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:23:04 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 18:35:11 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <iostream>

class AMateria
{
public:
	AMateria(void);
	AMateria(const AMateria&);
	AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria&	operator=(const AMateria&);

	const std::string&	getType() const;
	unsigned int	getXP() const;

	virtual AMateria*	clone() const = 0;
	virtual void	use(ICharacter& target) = 0;

protected:
	std::string	type;
	unsigned int	_xp;
};

#endif
