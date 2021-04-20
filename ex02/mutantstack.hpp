/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:35 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 19:43:43 by abaur            ###   ########.fr       */
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
	mutantstack(void);
	mutantstack(const mutantstack&);
	~mutantstack();

	mutantstack&	operator=(const mutantstack&);

	// All c++11 extension; cannot be implemented
	//using container_type  = typename std::stack<T>::container_type;
	//using value_type      = typename std::stack<T>::value_type;
	//using size_type       = typename std::stack<T>::size_type;
	//using refernce        = typename std::stack<T>::reference;
	//using const_reference = typename std::stack<T>::const_reference;

	Treference	top();
	Tconst_reference	top() const;

	bool	empty() const;

	Tsize_type	size() const;

	void	push(const Tvalue_type& value);
	void	pop();

	bool	operator==(const mutantstack& rhs) const;
	bool	operator!=(const mutantstack& rhs) const;
	bool	operator<=(const mutantstack& rhs) const;
	bool	operator>=(const mutantstack& rhs) const;
	bool	operator<(const mutantstack& rhs) const;
	bool	operator>(const mutantstack& rhs) const;

private:
	std::stack<T, Container>	_stack;
	const std::stack<T, Container>*const	_cstack;
};

#endif
