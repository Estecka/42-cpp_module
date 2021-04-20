/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:35 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 19:00:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

template <typename T>
class mutantstack
{
	mutantstack(void);
	mutantstack(const mutantstack&);
	~mutantstack();

	mutantstack&	operator=(const mutantstack&);
};

#endif
