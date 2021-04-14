/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:31:08 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 17:40:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base
{
public:
	A(void);
	~A();

private:
	A(const A&);
	A&	operator=(const A&);
};

#endif
