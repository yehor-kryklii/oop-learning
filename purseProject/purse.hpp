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

	Purse(const std::string & _brandOfPurse, PurseColor::Enum _purseColor, double _weightOfPurse, int _amountOfPurse);

	Purse(const Purse & _purse) = delete; // запрешаем вызов конструкторора копий с помощью оператора "delete".

	Purse& operator = (const Purse & _purse) = delete; // удаленный оператор присвоения, аналогично запрещаем его вызов с помощью "delete".

	Purse(Purse && _purse); // конструктор перемещения.

	Purse & operator = (Purse && _purse); // оператор перемещения.

	void addThing(const std::string & _nameOfThing, double _Weight);

	PurseItem getThing(const std::string & _nameOfThing);

	double getWeighOfThing(const std::string & _nameOfThing);

	int hasItem(const std::string & _nameOfThing);




private:

	std::string brandOfPurse;

	PurseColor::Enum purseColor;

	double weightOfPurse;

	int amountOfPurse;

	std::unordered_map< std::string, int > mapOfItems;



};


inline const int & getAmountOfPurse() 
{

}

inline const double & getWeightOfPurse()
{

}

inline  Purse::PurseColor::Enum getColor() 
{
	

}

inline const std::string & Purse::getBrandOfPurse() const
{

}

/*****************************************************************************/

#endif // _PURSE_HPP_
