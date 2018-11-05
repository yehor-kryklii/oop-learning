// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _RECIPE_HPP_
#define _RECIPE_HPP_

/*****************************************************************************/

#include <string>
#include <unordered_map>

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
	,	const std::string & _description
	,	const std::string & _author
);


	

	Recipe(const Recipe & _recipe) = delete;

	Recipe& operator = (const Recipe & _resipe) = delete;

	bool hasIngredient(const std::string & _nameOfIngredient) const;

	void addIngredient(const std::string & _nameOfIngredient, int _weightOfIngredient);

	void modifyIngredient(const std::string & _nameOfIngredient, int _weightOfIngredient);

	int getIngredientValue(const std::string & _nameOfIngredient) const;

	int getCookStepsCount() const;

	int getCookStep() const;

	void addCookStep(std::string & _cookStep);

	std::pair<std::string, int> beginIngredients;

	std::pair<std::string, int> endIngredients;



/*-----------------------------------------------------------------*/

private:

	std::string nameOfRecipe;

	std::string descriptionOfRecipe;

	std::string authorOfRecipe;
	
	int ingredientCount;

	std::unordered_map<std::string, int> mapOfIngredients;



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

inline int getIngredientCount() 
{
	return ingredientCount;
}

/*****************************************************************************/


#endif // _RECIPE_HPP_
