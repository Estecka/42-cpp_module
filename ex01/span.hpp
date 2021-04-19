/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:28 by abaur             #+#    #+#             */
/*   Updated: 2021/04/19 18:25:13 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdlib.h>

class Span
{
public:
	Span(void);
	Span(size_t capacity);
	Span(const Span&);
	~Span();

	Span&	operator=(const Span&);
	int&	operator[](size_t index);
	const int&	operator[](size_t index) const;

	size_t	size() const;

	void	addNumber(int n);
	int	shortestSpan() const;
	int	longestSpan () const;

private:
	int*	content;
	size_t	capacity;
	size_t	length;
};

#endif
