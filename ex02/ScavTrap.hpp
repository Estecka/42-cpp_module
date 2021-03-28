/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:18:18 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 17:22:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap& operator =(const ScavTrap&);
	ScavTrap(const ScavTrap&);
	ScavTrap(std::string name);
	~ScavTrap();

	void	challengeNewcomer();

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
	void	msgCopyConstructor(const ScavTrap& original) const;
	void	msgDefaultConstructor(void) const;
	void	msgNamedConstructor(std::string name) const;
	void	msgDestructor() const;
};

#endif
