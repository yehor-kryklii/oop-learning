// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _RECIPE_HPP_
#define _RECIPE_HPP_

/*****************************************************************************/

#include <string>

/*****************************************************************************/


class Recipe
{

/*-----------------------------------------------------------------*/

public:

/*-----------------------------------------------------------------*/
	const std::string & getName() const;

	const std::string & getDescription() const;

	const std::string & getAuthor() const;

	int getIngredientsCount() const;



	Recipe(
		const std::string & _name
		, const std::string & _description
		, const std::string & _author
	);

/*-----------------------------------------------------------------*/

private:

	std::string nameOfRecipe;

	std::string descriptionOfRecipe;

	std::string authorOfRecipe;

/*-----------------------------------------------------------------*/

	

/*-----------------------------------------------------------------*/

};

/*****************************************************************************/

inline const std::string & Recipe::getName() const
{
	return nameOfRecipe;
}

inline const std::string & Recipe::getDescription() const
{
	return descriptionOfRecipe;
}

inline const std::string & Recipe::getAuthor() const
{
	return authorOfRecipe;
}

/*****************************************************************************/


#endif // _RECIPE_HPP_
