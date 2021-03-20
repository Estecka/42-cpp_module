/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:21:03 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 20:30:48 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie(std::string name, std::string type);
	~Zombie();

	std::string	GetName();
	std::string	GetType();
	std::string	GetMatricule();

	void	Announce();

private:
	std::string	name;
	std::string	type;
};

#endif
