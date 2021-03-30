/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:51:39 by abaur             #+#    #+#             */
/*   Updated: 2021/03/30 14:38:57 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap(void);
	SuperTrap& operator =(const SuperTrap&);
	SuperTrap(const SuperTrap&);
	SuperTrap(std::string name);
	~SuperTrap();

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
	void	msgCopyConstructor(const SuperTrap& original) const;
	void	msgDefaultConstructor(void) const;
	void	msgNamedConstructor(std::string name) const;
	void	msgDestructor() const;
};

#endif
