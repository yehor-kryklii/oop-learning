// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _PURSE_HPP_
#define _PURSE_HPP_

/*****************************************************************************/

#include <string>
#include <unordered_map>

/*****************************************************************************/


class Purse
{

	/*-----------------------------------------------------------------*/

public:

	struct PurseItem
	{
		std::string nameOfThing;

		double weightOfThing;
	};

	struct PurseColor
	{
		enum Enum
		{
			Green,
			Red,
			Black,
			Yellow,
			White
		};
	};

	PurseColor::Enum  getColor() const;
	const std::string & getBrandOfPurse() const;
	double getWeightOfPurse() const;
	int getAmountOfPurse() const;

	Purse(
		const std::string & _brandOfPurse
		, PurseColor::Enum _purseColor
		, int _amountOfPurse
		, double _weightOfPurse
	);

	Purse(const Purse & _purse) = delete; // prohibit call of the copy constructor using "delete" operator.

	Purse& operator = (const Purse & _purse) = delete; // remote assignment operator.

	Purse(Purse && _purse);

	Purse & operator = (Purse && _purse);

	void addThing(const std::string & _nameOfThing, double _Weight);

	PurseItem getThing(const std::string & _nameOfThing);

	double getThingWeight(const std::string & _nameOfThing) const;

	bool hasItem(const std::string & _nameOfThing) const;

	//TO DO

	std::string const & getAllThings() const;

	double getCurrentWeight() const;

	int getCurrrentLoad() const;

private:

	std::string brandOfPurse;

	PurseColor::Enum PurseColor;

	double weightOfPurse;

	int amountOfPurse;

	std::unordered_map< std::string, double > mapOfItems;

};


inline int Purse::getAmountOfPurse() const
{
	return amountOfPurse;
}

inline double Purse::getWeightOfPurse() const
{
	return weightOfPurse;
}

inline Purse::PurseColor::Enum Purse::getColor() const
{
	return PurseColor;

}

inline const std::string & Purse::getBrandOfPurse() const
{
	return brandOfPurse;
}

/*****************************************************************************/

#endif // _PURSE_HPP_
