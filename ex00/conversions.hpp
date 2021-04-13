/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:12:48 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 17:03:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP

#include "conversion_templates.hpp"

#include <iostream>

bool	ValidateChar(std::string);
void	ParseChar(std::string);

bool	ValidateInt(std::string);
void	ParseInt(std::string);

bool	ValidateFloat(std::string);
void	ParseFloat(std::string);

bool	ValidateDouble(std::string);
void	ParseDouble(std::string);

#endif
