/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:35:09 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 17:36:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

#include <iostream>

B::B(void){ std::cout << "Created a B" << std::endl; }
B::B(const B&){}
B::~B(){}
B&	B::operator=(const B&){ return *this; }
