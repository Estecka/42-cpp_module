/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:06:38 by abaur             #+#    #+#             */
/*   Updated: 2021/04/19 17:47:11 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <list>

template <typename T>
int	easyfind(const T& container, int target)
{
	typename T::const_iterator it = container.begin();
	int	i = 0;
	int	value;

	while (it != container.end())
	{
		value = *it;
		if (value == target)
			return i;

		it++;
		i++;
	}
	return -1;
}

#endif
