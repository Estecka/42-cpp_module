/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:35 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 21:12:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(void) : std::stack<T, Container>() {}
	MutantStack(const std::stack<T, Container>& other) : std::stack<T, Container>(other) {}
	~MutantStack() {}

	MutantStack&	operator=(const std::stack<T, Container>& other) {
		this->std::stack<T, Container>::operator=(other);
		return *this;
	}

	struct iterator {
		iterator&	operator++();
		iterator&	operator++(int);
		iterator&	operator--();
		iterator&	operator--(int);

		iterator&	operator+(const iterator& other);
		iterator&	operator-(const iterator& other);

		bool	operator==(const iterator& other);
		bool	operator!=(const iterator& other);
		bool	operator<=(const iterator& other);
		bool	operator>=(const iterator& other);
		bool	operator< (const iterator& other);
		bool	operator> (const iterator& other);
	};

	iterator	begin() { return iterator(); }
	iterator	end()   { return iterator(); }
};

#endif
