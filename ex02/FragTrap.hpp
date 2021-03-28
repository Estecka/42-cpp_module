/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:17:15 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 16:01:59 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap& operator =(const FragTrap&);
	FragTrap(const FragTrap&);
	FragTrap(std::string name);
	~FragTrap();

	void	vaulthunter_dot_exe(std::string targetName);

protected:
	virtual void	defaultInit(void);


	virtual void	msgMelee(std::string targetName) const;
	virtual void	msgRanged(std::string targetName) const;
	virtual void	msgDamage(unsigned amount) const;
	virtual void	msgNoDamage() const;
	virtual void	msgAlreadyDead() const;
	virtual void	msgHeal(unsigned amount) const;
	virtual void	msgFullHealth() const;
	virtual void	msgNoEnergy() const;
	virtual void	msgNoHealth() const;

private:
	void	msgCopyConstructor(const FragTrap& original) const;
	void	msgDefaultConstructor(void) const;
	void	msgNamedConstructor(std::string name) const;
	void	msgDestructor() const;
};

#endif
