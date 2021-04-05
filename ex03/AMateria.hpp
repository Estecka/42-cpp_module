/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:23:04 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 16:08:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <iostream>

class	ICharacter;

class AMateria
{
public:
	AMateria(const AMateria&);
	AMateria(std::string const & type);
	virtual ~AMateria();

	const std::string&	getType() const;
	unsigned int	getXP() const;

	virtual AMateria*	clone() const = 0;
	virtual void	use(ICharacter& target);
	virtual void	status() const;

protected:
	AMateria(void);
	AMateria&	operator=(const AMateria&);

	unsigned int	_xp;

	virtual const std::string& type() const = 0;

private:
};

#endif
