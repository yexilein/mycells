

/**
 * @file siteavailability.cpp
 * @brief Implementation of the SiteAvailability class.
 * 
 * @authors Marc Dinh, Stephan Fischer
 */


// ==================
//  General Includes
// ==================
//
#include <iostream>

// ==================
//  Project Includes
// ==================
//
#include "siteavailability.h"
#include "siteobserver.h"

// ==========================
//  Constructors/Destructors
// ==========================
//
SiteAvailability::SiteAvailability (int first, int last, 
				    SiteObserver& site_observer)
  : _first (first)
  , _last (last)
  , _observer (site_observer)
  , _last_value_notified (-1)
{
  /** @pre First position must be positive. */
  REQUIRE (first >= 0);
  /** @pre Last position must be greater than first. */
  REQUIRE (last >= first);
}

// Not needed for this class (use of compiler generated versions)
// SiteAvailability::SiteAvailability (const SiteAvailability& other_site_availability);
// SiteAvailability& SiteAvailability::operator= (const SiteAvailability& other_site_availability);
// SiteAvailability::~SiteAvailability (void);

// ===========================
//  Public Methods - Commands
// ===========================
//
void SiteAvailability::notify (int number_sites)
{
  /** @pre Number of sites must be positive. */
  REQUIRE (number_sites >= 0);

  if (number_sites != _last_value_notified)
    {
      _observer.update (number_sites);
      _last_value_notified = number_sites;
    }
}

// ============================
//  Public Methods - Accessors
// ============================
//

// =================
//  Private Methods
// =================
//
