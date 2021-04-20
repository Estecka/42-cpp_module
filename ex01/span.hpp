/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:28 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 15:10:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <stdexcept>
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
	size_t	cap()  const;

	void	addNumber(int n);

	template <typename IT>
	void	addNumber(const IT& begin, const IT& end)
	{
		if ((end - begin) < 0)
			throw std::invalid_argument("End comes after Begin");
		if ((capacity - length) < (size_t)(end - begin))
			throw std::length_error("Too many elements to iterate over");
		
		for (IT it=begin; it!=end; it++)
		{
			if (capacity <= length)
				throw std::logic_error("Iterator exceeded expected amount.");
			this->content[length] = *it;
			this->length++;
		}
	}

	unsigned int	shortestSpan() const;
	unsigned int	longestSpan () const;

	void Dump() const;

private:
	int*	content;
	size_t	capacity;
	size_t	length;
};

#endif
