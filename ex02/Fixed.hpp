/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:08:33 by abaur             #+#    #+#             */
/*   Updated: 2021/03/25 19:08:16 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	signed int	raw;

	Fixed(void);
	Fixed(const Fixed& original);
	Fixed(int value);
	Fixed(float value);
	~Fixed();

	static int	GetFixedPoint();

	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
	static Fixed&	min(Fixed& a, Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);

	Fixed& operator =(const Fixed& original);
	bool operator >(const Fixed& other) const;
	bool operator <(const Fixed& other) const;
	bool operator >=(const Fixed& other) const;
	bool operator <=(const Fixed& other) const;
	bool operator ==(const Fixed& other) const;
	bool operator !=(const Fixed& other) const;

	Fixed operator +(const Fixed& other) const;
	Fixed operator -(const Fixed& other) const;
	Fixed operator *(const Fixed& other) const;
	Fixed operator /(const Fixed& other) const;

	Fixed& operator ++();
	Fixed& operator --();
	Fixed operator ++(int);
	Fixed operator --(int);


	int  	toInt() const;
	float	toFloat() const;
	std::string	toString() const;

private:
	static const int	fixedPoint;
};

std::ostream& operator <<(std::ostream& dst, const Fixed& src);

#endif
