/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:17:15 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 15:19:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap& operator =(const ClapTrap&);
	FragTrap(const FragTrap&);
	FragTrap(std::string name);
	~FragTrap();

	void	vaulthunter_dot_exe(std::string targetName);

protected:
	virtual void	defaultInit(void) override;

	virtual void	msgDefaultConstructor(void) const override;
	virtual void	msgCopyConstructor(const ClapTrap& original) const override;
	virtual void	msgNamedConstructor(std::string name) const override;
	virtual void	msgDestructor() const override;

	virtual void	msgMelee(std::string targetName) const override;
	virtual void	msgRanged(std::string targetName) const override;
	virtual void	msgDamage(unsigned amount) const override;
	virtual void	msgNoDamage() const override;
	virtual void	msgAlreadyDead() const override;
	virtual void	msgHeal(unsigned amount) const override;
	virtual void	msgFullHealth() const override;
	virtual void	msgNoEnergy() const override;
	virtual void	msgNoHealth() const override;
};

#endif
