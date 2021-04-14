/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:31:08 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 17:40:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
public:
	B(void);
	~B();

private:
	B(const B&);
	B&	operator=(const B&);
};

#endif
