/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:32:23 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 17:56:24 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
public:
	Squad(void);
	Squad(const Squad&);
	~Squad();

	Squad&	operator=(const Squad&);

	int	getCount() const;
	ISpaceMarine*	getUnit(int i) const;
	int	push(ISpaceMarine* newUnit);

private:
	ISpaceMarine**	content;
	int	capacity;
	int	length;

	void	expand(int newCount);
};