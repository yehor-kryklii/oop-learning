// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "recipe.hpp"
#include "messages.hpp"

/*****************************************************************************/

Recipe::Recipe(
	const std::string & _name
	, const std::string & _description
	, const std::string & _author
)
	: nameOfRecipe(_name),
	descriptionOfRecipe(_description),
	authorOfRecipe(_author)

{
	if (_name.empty())
		throw(std::logic_error(Messages::EmptyRecipeName));

	if (_description.empty())
		throw(std::logic_error(Messages::EmptyRecipeDescription));

	if (_author.empty())
		throw(std::logic_error(Messages::EmptyRecipeAuthor));

}

/*****************************************************************************/

bool Recipe::hasIngredient(const std::string & _nameOfIngredient) const
{
	if (_nameOfIngredient.empty())
		throw(std::logic_error(Messages::IngredientCannotBeFound));

		return mapOfIngredients.count(_nameOfIngredient) > 0;
}

/*****************************************************************************/


void Recipe::addIngredient(const std::string & _nameOfIngredient, int _weightOfIngreient)
{
	if (_nameOfIngredient.empty)
		throw(std::logic_error(Messages::EmptyIngredientName));

	if (_weightOfIngreient < 0)
		throw(std::logic_error(Messages::IngredientValueMustBePositive));

	mapOfIngredients.emplace(_nameOfIngredient, _weightOfIngreient);
}

/*****************************************************************************/


void Recipe::modifyIngredient(const std::string & _nameOfIngredient, int _newWeightOfIngredient)
{
	if (_nameOfIngredient.empty())
		throw(std::logic_error(Messages::EmptyIngredientName));

	if (_newWeightOfIngredient < 0)
		throw(std::logic_error(Messages::IngredientValueMustBePositive));

	if (!hasIngredient(_nameOfIngredient))
		throw(std::logic_error(Messages::IngredientCannotBeFound));

	mapOfIngredients[_nameOfIngredient] = _newWeightOfIngredient;
}
