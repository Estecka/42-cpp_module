/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:35 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 21:17:30 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void) : std::stack<T>() {}
	MutantStack(const std::stack<T>& other) : std::stack<T>(other) {}
	~MutantStack() {}

	MutantStack&	operator=(const std::stack<T>& other) {
		this->std::stack<T>::operator=(other);
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

	void	Dump() const {
		std::cout << "["<<this->size()<<"]{ ";
		for (int i=0; i<this->size(); i++)
		{
			std::cout << this->c[i];
			if (i+1 < this->size)
				std::cout << ", ";
		}
		std::cout << " }";
	}
};

#endif
