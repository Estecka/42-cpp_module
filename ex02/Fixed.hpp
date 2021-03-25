/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:08:33 by abaur             #+#    #+#             */
/*   Updated: 2021/03/25 18:29:31 by abaur            ###   ########.fr       */
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

	Fixed& operator =(const Fixed& original);
	Fixed& operator >(const Fixed& other) const;
	Fixed& operator <(const Fixed& other) const;
	Fixed& operator >=(const Fixed& other) const;
	Fixed& operator <=(const Fixed& other) const;
	Fixed& operator ==(const Fixed& other) const;
	Fixed& operator !=(const Fixed& other) const;

	Fixed& operator ++();
	Fixed& operator --();
	Fixed& operator ++(int);
	Fixed& operator --(int);

	int  	toInt() const;
	float	toFloat() const;
	std::string	toString() const;

private:
	static const int	fixedPoint;
};

std::ostream& operator <<(std::ostream& dst, const Fixed& src);
const Fixed&	min(const Fixed& a, const Fixed& b);
const Fixed&	max(const Fixed& a, const Fixed& b);
Fixed&	min(Fixed& a, Fixed& b);
Fixed&	max(Fixed& a, Fixed& b);

#endif
