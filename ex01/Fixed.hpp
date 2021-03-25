/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:08:33 by abaur             #+#    #+#             */
/*   Updated: 2021/03/25 14:36:10 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed& original);
	Fixed(int value);
	Fixed(float value);
	~Fixed();

	Fixed& operator =(const Fixed& original);

	static int	GetFixedPoint();

	int 	getRawBits() const;
	void	setRawBits(const int raw);

	int  	toInt() const;
	float	toFloat() const;
	std::string	toString() const;

private:
	static const int	fixedPoint;
	signed int	raw;
};

std::ostream& operator <<(std::ostream& dst, const Fixed& src);

#endif
