// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "purse.hpp"
#include "messages.hpp"

/*****************************************************************************/

Purse::Purse(const std::string & _brandOfPurse, PurseColor::Enum _purseColor, double _weightOfPurse, int amountOfPurse)
{
	if (_brandOfPurse.empty())
		throw(std::logic_error(Messages::EmptyBrandName));

		brandOfPurse = _brandOfPurse;

}




/*****************************************************************************/
