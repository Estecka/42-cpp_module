/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:28:25 by abaur             #+#    #+#             */
/*   Updated: 2021/04/17 18:40:03 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdlib.h>

template <typename T>
class Array
{
public:
	Array(void);
	Array(const Array<T>&);
	Array(int size);
	~Array();
	Array<T>	operator=(const Array<T>&);

	T&	operator[](size_t);
	size_t	size() const;

private:
	T*	content;
	size_t	length;
};


#endif
