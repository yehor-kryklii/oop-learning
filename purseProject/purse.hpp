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

	const std::string & getColor() const;
	const std::string & getNameOfPurse() const;

	Purse(std::string & _nameOfPurse, PurseColor::Enum _PurseColor, double _WeightOfPurse, int _AmountOfPurse);

	void AddThing(std::string & _nameOfThing, double _Weight);

	int GetThing(std::string & _nameOfThing);

	double GetWeighOfThing(std::string & _nameOfThing);

	void CheckContent(std::string & _nameOfThing, double _Weight);


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
