// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _PURSE_HPP_
#define _PURSE_HPP_

/*****************************************************************************/

#include <string>
#include <unordered_map>

/*****************************************************************************/
std::pair < std::string, int >
Item;

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

	const std::string & getColor() const;
	const std::string & getNameOfPurse() const;

	Purse(const std::string & _nameOfPurse, PurseColor::Enum _PurseColor, double _WeightOfPurse, int _AmountOfPurse);

	Purse(const Purse & _purse) = delete; // ��������� ����� �������������� ����� � ������� ��������� "delete".

	Purse& operator = (const Purse & _purse) = delete; // ��������� �������� ����������, ���������� ��������� ��� ����� � ������� "delete".

	Purse(Purse && _purse); // ����������� �����������.

	Purse & operator = (Purse && _purse); // �������� �����������.

	void addThing(const std::string & _nameOfThing, double _Weight);

	std::string getThing(const std::string & _nameOfThing);

	double getWeighOfThing(const std::string & _nameOfThing);

	void hasItem(const std::string & _nameOfThing);




private:

	std::string nameOfPurse;

	std::unordered_map< std::string, int > mapOfItems;



};




inline const std::string & Purse::getColor() const
{
	

}

inline const std::string & Purse::getNameOfPurse() const
{

}

/*****************************************************************************/

#endif // _PURSE_HPP_
