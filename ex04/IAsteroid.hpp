#ifndef IASTEROID_HPP
#define IASTEROID_HPP

#include <iostream>

class StripMiner;
class DeepCoreMiner;

class IAsteroid
{
public:
	virtual ~IAsteroid() {}
	virtual std::string beMined(const StripMiner*) const = 0;
	virtual std::string beMined(const DeepCoreMiner*) const = 0;
	virtual std::string getName() const = 0;
};

#include "StripMiner.hpp"
#include "DeepCoreMiner.hpp"

#endif
