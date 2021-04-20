/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:35 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 20:03:10 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

#define Tcontainer_type 	typename std::stack<T>::container_type
#define Tvalue_type     	typename std::stack<T>::value_type
#define Tsize_type      	typename std::stack<T>::size_type
#define Treference      	typename std::stack<T>::reference
#define Tconst_reference	typename std::stack<T>::const_reference

template <typename T, class Container = std::deque<T> >
class mutantstack
{
public:
	mutantstack(void) : _stack() {}
	mutantstack(const mutantstack& other) : _stack(other._stack) {}
	~mutantstack() {}

	mutantstack&	operator=(const mutantstack& other) { _stack = other._stack; }

	// All c++11 extension; cannot be implemented
	//using container_type  = typename std::stack<T>::container_type;
	//using value_type      = typename std::stack<T>::value_type;
	//using size_type       = typename std::stack<T>::size_type;
	//using refernce        = typename std::stack<T>::reference;
	//using const_reference = typename std::stack<T>::const_reference;

	Treference      	top()       { return _stack.top(); }
	Tconst_reference	top() const { return _stack.top(); }

	bool	empty() const { return _stack.empty(); }

	Tsize_type	size() const { return _stack.size(); }

	void	push(const Tvalue_type& value) { return _stack.push(value); }
	void	pop() { _stack.pop(); }

	bool	operator==(const mutantstack& rhs) const { return _stack == rhs._stack; }
	bool	operator!=(const mutantstack& rhs) const { return _stack != rhs._stack; }
	bool	operator<=(const mutantstack& rhs) const { return _stack <= rhs._stack; }
	bool	operator>=(const mutantstack& rhs) const { return _stack >= rhs._stack; }
	bool	operator< (const mutantstack& rhs) const { return _stack <  rhs._stack; }
	bool	operator> (const mutantstack& rhs) const { return _stack >  rhs._stack; }

private:
	std::stack<T, Container>	_stack;
};

#endif
