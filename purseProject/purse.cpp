// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "purse.hpp"
#include "messages.hpp"

/*****************************************************************************/

Purse::Purse(
		const std::string & _brandOfPurse, 
		PurseColor::Enum _purseColor, 
		int _amountOfPurse,
		double _weightOfPurse 
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


/*****************************************************************************/


bool Purse::hasItem(const std::string & _nameOfThing) const // make this method const because found an example where such function is const; need to ask you why)
{
	if (_nameOfThing.empty())
		throw(std::logic_error(Messages::EmptyItemName));

	return mapOfItems.count(_nameOfThing) > 0;
}

double Purse::getThingWeight(const std::string & _nameOfThing) const
{
	if (_nameOfThing.empty())
		throw(std::logic_error(Messages::EmptyItemName));

	if (!hasItem(_nameOfThing))
		throw(std::logic_error(Messages::NoSuchItemInPurse));
	
	return mapOfItems.at(_nameOfThing);
}


/*****************************************************************************/

void Purse::addThing(const std::string & _nameOfThing, double _Weight)
{
	if (getCurrrentLoad() + _Weight > amountOfPurse)
		throw(std::logic_error(Messages::NoSpaceInPurse));

	if (_nameOfThing.empty())
		throw(std::logic_error(Messages::EmptyItemName));

	if (_Weight <= 0)
		throw(std::logic_error(Messages::NonPositiveItemsWeight));

	mapOfItems.emplace(_nameOfThing, _Weight);
}

/*****************************************************************************/

 Purse::PurseItem Purse::getThing (const std::string & _nameOfThing) 
{
	 if (_nameOfThing.empty())
		 throw(std::logic_error(Messages::EmptyItemName));

	 if (!hasItem(_nameOfThing))
		 throw(std::logic_error(Messages::NoSuchItemInPurse));

	 Purse::PurseItem i;
	 i.nameOfThing = _nameOfThing;
	 i.weightOfThing = mapOfItems.at(_nameOfThing);
	 mapOfItems.erase(_nameOfThing); 

	 return i;
}

 /*****************************************************************************/


 std::string  Purse::getAllThings() const
 {

	 std::string total;

	 for (auto element : mapOfItems)
		 total += (element.first + " ");

	 return total;

 }

 /*****************************************************************************/


 double Purse::getCurrentWeight() const
 {
	 double total = 0;

	 for (auto element : mapOfItems)
		 total += element.second;

	 return total;  // need to sum up .second
 }

 /*****************************************************************************/


 int Purse::getCurrrentLoad() const
 {
	 return mapOfItems.size(); // size returns the number of elements in the map container.
 }

 /*****************************************************************************/

 Purse::Purse(Purse && _purse)
	 : brandOfPurse(_purse.brandOfPurse),
	 PurseColor(_purse.PurseColor),
	 weightOfPurse(_purse.weightOfPurse),
	 amountOfPurse(_purse.amountOfPurse)

 {

	 std::swap(mapOfItems, _purse.mapOfItems);

 }

 /*****************************************************************************/


 Purse & Purse::operator = (Purse && _purse)
 {

	 if (&_purse == this)
		 return *this;

	 std::swap(brandOfPurse, _purse.brandOfPurse);
	 std::swap(PurseColor, _purse.PurseColor);
	 std::swap(weightOfPurse, _purse.weightOfPurse);
	 std::swap(amountOfPurse, _purse.amountOfPurse);

 }

 /*****************************************************************************/


 