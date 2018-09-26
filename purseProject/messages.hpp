// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _MESSAGES_HPP_
#define _MESSAGES_HPP_

/*****************************************************************************/

namespace Messages
{
	const char * const EmptyBrandName = "Brand name cannot be empty";
	const char * const EmptyItemName = "Item name cannot be empty";
	const char * const NonPositiveItemsCount = "Number of items must be positive";
    const char * const NonPositiveItemsWeight = "Weight of items must be positive";
	const char * const NoSpaceInPurse = "No space left in the purse";
    const char * const NotEnoughWeightForItem = "Impossible to put more weight to purse.";
	const char * const NoSuchItemInPurse = "No such item in purse";
	const char * const NotEnoughItemsInPurse = "Not enough items of this type stored in purse";
	const char * const NonPositiveWeightPurse = "Weight of purse must be poitive";
	const char * const NonPoitiveAmount = "Amount of purse must be positive";
	
}

/*****************************************************************************/

#endif // _MESSAGES_HPP_
