/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:31:56 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 15:55:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure&);
	~Cure();
	Cure&	operator=(const Cure&);

	AMateria*	clone() const;
	void	use(ICharacter& target);
	void	status() const;

protected:
	const std::string&	type() const;
};

#endif
