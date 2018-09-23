// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _PURSE_HPP_
#define _PURSE_HPP_

/*****************************************************************************/

#include <string>

/*****************************************************************************/


class Purse
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/
	
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

	std::string & getColor() const;
	std::string & getNameOfPurse() const;

	Purse(const std::string & _nameOfPurse, PurseColor::Enum _PurseColor, double _WeightOfPurse, int _AmountOfPurse);

	Purse(const Purse & _purse) = delete; // ��������� ����� �������������� ����� � ������� ��������� "delete".

	Purse& operator = (const Purse & _purse) = delete; // ��������� �������� ����������, ���������� ��������� ��� ����� � ������� "delete".

	Purse(Purse && _purse); // ����������� �����������.

	Purse & operator = (Purse && _purse); // �������� �����������.

	void addThing(const std::string & _nameOfThing, double _Weight);

	char getThing(const std::string & _nameOfThing);

	double getWeighOfThing(const std::string & _nameOfThing);

	void hasItem(const std::string & _nameOfThing, double _Weight);


/*-----------------------------------------------------------------*/

private:

/*-----------------------------------------------------------------*/

	

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

inline const std::string & Purse::getColor() const
{

}

inline const std::string & Purse::getNameOfPurse() const
{

}

/*****************************************************************************/

#endif // _PURSE_HPP_
