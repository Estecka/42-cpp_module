/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:21:03 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 19:33:07 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
public:
	Zombie(std::string name, std::string type);
	~Zombie();

	std::string	GetName();
	std::string	GetType();
	std::string	GetMatricule();

	void	Advert();

private:
	std::string	name;
	std::string	type;
};
