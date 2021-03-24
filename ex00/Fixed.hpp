/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:08:33 by abaur             #+#    #+#             */
/*   Updated: 2021/03/24 19:22:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed& original);
	~Fixed();

	Fixed& operator =(const Fixed& original);

	static unsigned	GetFixedPoint();

	int 	getRawBits() const;
	void	setRawBits(const int raw);

private:
	static const unsigned	fixedPoint;
	signed int	raw;
};

#endif
