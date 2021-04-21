/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:28 by abaur             #+#    #+#             */
/*   Updated: 2021/04/21 17:12:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

class Span : private std::vector<int>
{
public:
	Span(void);
	Span(size_t capacity);
	Span(const Span&);
	~Span();

	Span&	operator=(const Span&);

	size_t	size() const;
	size_t	capacity() const;
	std::vector<int>::const_iterator	cbegin() const;
	std::vector<int>::const_iterator	cend()   const;

	void	addNumber(int n);

	template <typename IT>
	void	addNumber(const IT& begin, const IT& end)
	{
		if ((end - begin) < 0)
			throw std::invalid_argument("End comes after Begin");
		if ((capacity() - size()) < (size_t)(end - begin))
			throw std::length_error("Too many elements to iterate over");
		
		for (IT it=begin; it!=end; it++)
		{
			if (capacity() <= size())
				throw std::logic_error("Iterator exceeded expected amount.");
			this->push_back(*it);
		}
		this->_dirty = true;
	}

	unsigned int	shortestSpan();
	unsigned int	longestSpan ();

	void Dump() const;
private:
	bool	_dirty;

	void	CheckSpanability();
};

#endif
