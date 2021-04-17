/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:28:25 by abaur             #+#    #+#             */
/*   Updated: 2021/04/17 20:06:50 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <sstream>

template <typename T>
class Array
{
public:
	Array(void) {
		this->content = NULL;
		this->length = 0;
	}
	Array(const Array<T>& other){
		this->length = 0;
		this->content = NULL;
		*this = other;
	}
	Array(int size) {
		this->content = new T[size];
		this->length = size;
	}
	~Array() {
		if (this->length)
			delete[] this->content;
	}
	Array<T>&	operator=(const Array<T>& other) {
		this->~Array();

		this->length = other.length;
		if (!length)
			this->content = NULL;
		else {
			this->content = new T[length];
			for (size_t i=0; i<length; i++)
				(*this)[i] = other[i];
		}
		return *this;
	}

	T&	operator[](size_t index) {
		if (0 <= index && index < length)
			return this->content[index];
		else {
			std::ostringstream	what;
			what << "Index "<<index<<" out of "<<length <<" is invalid.";
			throw std::out_of_range(what.str());
		}
	}
	const T&	operator[](size_t index) const {
		if (0 <= index && index < length)
			return this->content[index];
		else {
			std::ostringstream	what;
			what << "Index "<<index<<" out of "<<length <<" is invalid.";
			throw std::out_of_range(what.str());
		}
	}

	size_t	size() const {
		return this->length;
	}

	void	Dump() const {
		std::cout << (void*)this->content << "["<<this->size()<<"] { ";
		for (size_t i=0; i<length; i++){
			std::cout << (*this)[i];
			if (i+1 < length)
				std::cout << ", ";
		}
		std::cout << " }" << std::endl;
	}

private:
	T*	content;
	size_t	length;
};


#endif
