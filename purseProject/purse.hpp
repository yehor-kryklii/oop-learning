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
		const std::string nameOfThing;

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

	PurseColor::Enum & getColor() const;
	const std::string & getBrandOfPurse() const;
	const double & getWeightOfPurse() const;
	const int & getAmountOfPurse() const;

	Purse(const std::string & _brandOfPurse, PurseColor::Enum _purseColor, double _weightOfPurse, int _amountOfPurse);

	Purse(const Purse & _purse) = delete; // prohibit call of the copy constructor using "delete" operator.

	Purse& operator = (const Purse & _purse) = delete; // remote assignment operator.

	Purse(Purse && _purse); 

	Purse & operator = (Purse && _purse); 

	void addThing(const std::string & _nameOfThing, double _Weight);

	const PurseItem getThing(const std::string & _nameOfThing);

	double getWeighOfThing(const std::string & _nameOfThing);

	bool hasItem(const std::string & _nameOfThing);




private:

	std::string brandOfPurse;

	PurseColor::Enum purseColor;

	double weightOfPurse;

	int amountOfPurse;

	std::unordered_map< std::string, int > mapOfItems;



};


inline const int & getAmountOfPurse() 
{
	return amountOfPurse;
}

inline const double & getWeightOfPurse()
{
	return weightOfPurse;
}

inline const Purse::PurseColor::Enum getColor() 
{
	return PurseColor;

}

inline const std::string & Purse::getBrandOfPurse() const
{
	return brandOfPurse;
}

/*****************************************************************************/

#endif // _PURSE_HPP_
