/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:31:08 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 17:33:45 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
	Base(void);
	virtual ~Base() = 0;

private:
	Base(const Base&);
	Base&	operator=(const Base&);
};

#endif
