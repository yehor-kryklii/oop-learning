// (C) 2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "testslib.hpp"

#include "purse.hpp"
#include "messages.hpp"

/*****************************************************************************/


DECLARE_OOP_TEST ( test_Purse_Constructor )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );
	
	assert( p.getBrandOfPurse() == "Gucci" );
	assert( p.getAmountOfPurse() == 5 );
	assert( p.getCurrrentLoad() == 0 );
    assert( p.getWeightOfPurse() == 7.2 );
    assert( p.getColor() == Purse::PurseColor::Red );
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_Purse_Constructor_EmptyName )
{
	ASSERT_THROWS(
			Purse ( "", Purse::PurseColor::Red, 5, 7.2 )
		,	Messages::EmptyBrandName
	);
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_Purse_Constructor_BadItemsCount_and_Weight )
{
	ASSERT_THROWS(
            Purse ( "Gucci", Purse::PurseColor::Red, 0, 7.2 )
		,	Messages::NonPoitiveAmount
	);

	ASSERT_THROWS(
            Purse ( "Gucci", Purse::PurseColor::Red, -1, 7.2 )
		,	Messages::NonPoitiveAmount
	);
    
    ASSERT_THROWS(
            Purse ( "Gucci", Purse::PurseColor::Red, 1, -1 )
		,	Messages::NonPositiveWeightPurse
	);
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_Purse_QueryItems_WhenEmpty )
{
	Purse p("Gucci", Purse::PurseColor::Red, 5, 7.2);

	assert( ! p.hasItem( "Lipstick" ) );
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_Purse_add_item )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    p.addThing( "Lipstick", 0.1 ); 
    
	assert( p.hasItem( "Lipstick" ) );
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_Purse_add_item_empty_space )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 1, 7.2 );

    p.addThing( "Lipstick", 0.1 ); 
    
    ASSERT_THROWS(
            p.addThing( "Pen", 0.1 )
		,	Messages::NoSpaceInPurse
	);
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_Purse_add_item_empty_name )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    
    ASSERT_THROWS(
            p.addThing( "", 0.1 )
		,	Messages::EmptyItemName
	);
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_Purse_add_item_non_positive_weight )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    ASSERT_THROWS(
            p.addThing( "Lipstick", -1 )
		,	Messages::NonPositiveItemsWeight
	);
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_query_item )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    p.addThing( "Lipstic", 0.1 );
    
    p.getThing( "Lipstic" ); 
    
	assert( ! p.hasItem( "Lipstick" ) );
}


/*****************************************************************************/



DECLARE_OOP_TEST ( test_query_item_non_existant_name )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    p.addThing( "Gucci", 0.1 );
     
    ASSERT_THROWS(      
            p.getThing( "Lipstic" )
        ,   Messages::NoSuchItemInPurse
    ); 
}


/*****************************************************************************/



DECLARE_OOP_TEST ( test_get_item_weight )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    p.addThing( "Lipstic", 0.1 );
    
    p.getThing( "Lipstic" ); 
    
	assert( ! p.hasItem( "Lipstick" ) );
}


/*****************************************************************************/



DECLARE_OOP_TEST ( test_get_item_weight__non_existant_name )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    p.addThing( "Gucci", 0.1 );
     
    ASSERT_THROWS(      
            p.getThingWeight( "Lipstic" )
        ,   Messages::NoSuchItemInPurse
    ); 
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_get_purse_weight_and_load )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    p.addThing( "Lipstic", 0.1 );
    p.addThing( "Pen", 0.3 );
    
    p.getThing( "Lipstic" ); 
    
	assert( p.hasItem( "Lipstick" ) );
    assert( p.hasItem( "Pen" ) );
    
    assert( p.getThingWeight( "Lipstick" ) == 0.1 );
    assert( p.getThingWeight( "Pen" ) == 0.3 );
    
    assert( p.getCurrentWeight() == 0.4 );
    assert( p.getCurrrentLoad() == 2 );
}


/*****************************************************************************/


DECLARE_OOP_TEST ( test_get_all_items )
{
	Purse p( "Gucci", Purse::PurseColor::Red, 5, 7.2 );

    p.addThing( "Lipstic", 0.1 );
    p.addThing( "Pen", 0.3 );
    
    std::string allItems = p.getAllThings();
    
    assert( "Lipstic Pen" );
}


/*****************************************************************************/


