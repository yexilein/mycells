

/**
 * @file sitehandler.cpp
 * @brief Implementation of the SiteHandler class.
 * 
 * @authors Marc Dinh, Stephan Fischer
 */


// ==================
//  General Includes
// ==================
//
#include <iostream> // std::cout
#include <vector>  // std::vector

// ==================
//  Project Includes
// ==================
//
#include "sitehandler.h"
#include "site.h"
#include "chemicalsequence.h"
#include "macros.h"



// ==========================
//  Constructors/Destructors
// ==========================
//
SiteHandler::SiteHandler (void)
{
}

SiteHandler::~SiteHandler (void)
{
}

// ===========================
//  Public Methods - Commands
// ===========================
//

// ============================
//  Public Methods - Accessors
// ============================
//


// ==========================
//  Public Methods - Setters
// ==========================
//


// =======================================
//  Public Methods - Operator overloading
// =======================================
//
std::ostream& operator<< (std::ostream& output, const SiteHandler& site_handler)
{
  site_handler.print (output);
  return output;
}

// ==================================
//  Public Methods - Class invariant
// ==================================
//
/**
 * Checks all the conditions that must remain true troughout the life cycle of
 * every object.
 */
bool SiteHandler::check_invariant ( void ) const
{
  bool result = true;
  return result;
}


// ===================
//  Protected Methods
// ===================
//
int SiteHandler::get_or_create_family_identifier (std::string& family_name)
{
  if ( _family_ids.exists ( family_name ) == false )
    {
      _family_ids.create_id ( family_name );
    }
  return _family_ids.id ( family_name );
}
