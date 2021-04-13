/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:12:48 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 17:58:52 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP

#include "conversion_templates.hpp"

#include <iostream>

bool	ConvertChar(std::string);
bool	ConvertInt(std::string);
bool	ConvertFloat(std::string);
bool	ConvertDouble(std::string);

#endif
