/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:09:35 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 19:32:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

static void	PonyOnTheHeap(){
	Pony	*pony;

	(void)pony;
}

static void	PonyOnTheStack(){
	Pony	pony;

	(void)pony;
}

extern int	main(){
	PonyOnTheHeap();
	PonyOnTheStack();
}
