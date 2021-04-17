/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:37:39 by abaur             #+#    #+#             */
/*   Updated: 2021/04/17 17:42:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T a, T b) {
	T olda = a;

	a = b;
	b = olda;
}

template <typename T>
T	min(T a, T b) 
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T	max(T a, T b) 
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
