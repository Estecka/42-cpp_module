/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:35 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 22:33:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <stdexcept>

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
	public:
		iterator(void){
			this->target = NULL;
			this->index = 0;
		}
		iterator(MutantStack& target, size_t startIndex){
			this->target = &target;
			this->index = startIndex;
		}

		iterator&	operator++() { this->index++; return *this; }
		iterator&	operator--() { this->index--; return *this; }
		iterator 	operator++(int) { iterator tmp(*target, index); this->index++; return tmp;}
		iterator 	operator--(int) { iterator tmp(*target, index); this->index--; return tmp;}

		iterator	operator+(const iterator& other) { checkTarget(other); return iterator(*target, index + other.index); }
		iterator	operator-(const iterator& other) { checkTarget(other); return iterator(*target, index - other.index); }

		T&	operator*(){
			if (target)
				return target->c[this->index];
			throw std::domain_error("Dereferenced a NULL iterator.");
		}

		bool	operator==(const iterator& other) { return target == other.target && index == other.index; }
		bool	operator!=(const iterator& other) { return target != other.target || index != other.index; }
		bool	operator<=(const iterator& other) { checkTarget(other); return this->index <= other.index; }
		bool	operator>=(const iterator& other) { checkTarget(other); return this->index >= other.index; }
		bool	operator< (const iterator& other) { checkTarget(other); return this->index <  other.index; }
		bool	operator> (const iterator& other) { checkTarget(other); return this->index >  other.index; }

	private:
		MutantStack*	target;
		size_t	index;

		void	checkTarget(const iterator& other) const {
			if (this->target != other.target)
				throw std::domain_error("Iterators point to different containers.");
		}
	};

	iterator	begin() { return iterator(*this, 0           ); }
	iterator	end()   { return iterator(*this, this->size()); }

	void	Dump() const {
		std::cout << "stck["<<this->size()<<"]{ ";
		for (size_t i=0; i<this->size(); i++)
		{
			std::cout << this->c[i];
			if (i+1 < this->size())
				std::cout << ", ";
		}
		std::cout << " }" << std::endl;
	}
};

#endif
