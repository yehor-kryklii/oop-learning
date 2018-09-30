// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "purse.hpp"
#include "messages.hpp"

/*****************************************************************************/

Purse::Purse(
		const std::string & _brandOfPurse, 
		PurseColor::Enum _purseColor, 
		double _weightOfPurse, 
		int _amountOfPurse
)
	: brandOfPurse(_brandOfPurse),
	PurseColor(_purseColor),
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

bool Purse::hasItem(const std::string & _nameOfThing) const // make this method const because found an example where such function is const; need to ask you why)
{
	if (_nameOfThing.empty())
		throw(std::logic_error(Messages::EmptyItemName));

	if (mapOfItems.count(_nameOfThing) == 0)
		return false;
		
	else

		return true;
}

double Purse::getThingWeight(const std::string & _nameOfThing)
{
	if (_nameOfThing.empty())
		throw(std::logic_error(Messages::EmptyItemName));

	if (!hasItem(_nameOfThing))
		throw(std::logic_error(Messages::NoSuchItemInPurse));

	mapOfItems.at(_nameOfThing);
	return mapOfItems(); //Don't know how realise






}



/*****************************************************************************/
