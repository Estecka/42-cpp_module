/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:00:05 by abaur             #+#    #+#             */
/*   Updated: 2021/04/17 18:03:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <stdlib.h>

template<typename T>
void	iter(T* array, size_t length, void(*func)(T&)) {
	for (size_t i=0; i<length; i++)
		func(array[i]);
}

#endif
