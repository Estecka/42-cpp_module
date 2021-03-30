/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:15:44 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 18:18:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap& operator =(const NinjaTrap&);
	NinjaTrap(const NinjaTrap&);
	NinjaTrap(std::string name);
	~NinjaTrap();

	void	ninjaShoebox(const ClapTrap& target);
	void	ninjaShoebox(const FragTrap& target);
	void	ninjaShoebox(const ScavTrap& target);
	void	ninjaShoebox(const NinjaTrap& target);

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
	void	msgCopyConstructor(const NinjaTrap& original) const;
	void	msgDefaultConstructor(void) const;
	void	msgNamedConstructor(std::string name) const;
	void	msgDestructor() const;
};

#endif
