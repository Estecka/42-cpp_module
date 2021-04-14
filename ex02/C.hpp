/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:31:08 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 17:40:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base
{
public:
	C(void);
	~C();

private:
	C(const C&);
	C&	operator=(const C&);
};

#endif
