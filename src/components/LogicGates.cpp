//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "LogicGates.hpp"

namespace nts
{
	Tristate operator&&(Tristate a, Tristate b)
	{
		if (a == Tristate::UNDEFINED || b == Tristate::UNDEFINED)
			return Tristate::UNDEFINED;
		if (a == Tristate::TRUE && b == Tristate::TRUE)
			return Tristate::TRUE;
		return Tristate::FALSE;
	}

	Tristate operator||(Tristate a, Tristate b)
	{
		if (a == Tristate::TRUE || b == Tristate::TRUE)
			return Tristate::TRUE;
		if (a == Tristate::FALSE && b == Tristate::FALSE)
			return Tristate::FALSE;
		return Tristate::UNDEFINED;
	}

	Tristate operator^(Tristate a, Tristate b)
	{
		if (a == Tristate::UNDEFINED || b == Tristate::UNDEFINED)
			return Tristate::UNDEFINED;
		if ((a == Tristate::TRUE && b == Tristate::FALSE) ||
		    (a == Tristate::FALSE && b == Tristate::TRUE))
			return Tristate::TRUE;
		return Tristate::FALSE;
	}

	Tristate operator!(Tristate a)
	{
		return a == Tristate::UNDEFINED ? a : a == Tristate::TRUE
			? Tristate::FALSE : Tristate::TRUE;
	}
}
