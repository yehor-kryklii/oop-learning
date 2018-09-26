// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "purse.hpp"
#include "messages.hpp"

/*****************************************************************************/

Purse::Purse(const std::string & _brandOfPurse, PurseColor::Enum _purseColor, double _weightOfPurse, int _amountOfPurse)
	: brandOfPurse(_brandOfPurse),
	purseColor(_purseColor),
	weightOfPurse(_weightOfPurse),
	amountOfPurse(_amountOfPurse)

{

	if (_brandOfPurse.empty())
		throw(std::logic_error(Messages::EmptyBrandName));

	if (_weightOfPurse <= 0)
		throw(std::logic_error(Messages::NonPositiveWeightPurse));

	if (_amountOfPurse <= 0)
		throw(std::logic_error(Messages::NonPoitiveAmount));

}




/*****************************************************************************/
