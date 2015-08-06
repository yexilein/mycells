

/**
 * @file  sitelocation.h
 * @brief Header for the SiteLocation class.
 * 
 * @authors Marc Dinh, Stephan Fischer
 */


// Multiple include protection
//
#ifndef SITELOCATION_H
#define SITELOCATION_H

// ==================
//  General Includes
// ==================
//


// ==================
//  Project Includes
// ==================
//
#include "forwarddeclarations.h"
#include "macros.h"

/**
 * @brief Class storing site location variables.
 *
 * Simply stores and gives access to (position,length). Can be used for
 * simplicity and clarity by other classes.
 */
class SiteLocation
{
 public:

  // ==========================
  //  Constructors/Destructors
  // ==========================
  //
  /**
   * @brief Constructor based on position and length.
   * @param position Position of site.
   * @param length Length of site.
   */
  SiteLocation ( int position, int length )
    : _position ( position )
    , _length ( length ) {}

  // Not needed for this class (use of default copy constructor) !
  // /*
  //  * @brief Copy constructor
  //  */
  // SiteLocation (SiteLocation& other_site_location);

  /**
   * @brief Destructor.
   */
  virtual ~SiteLocation (void);

  // ===========================
  //  Public Methods - Commands
  // ===========================
  //


  // ============================
  //  Public Methods - Accessors
  // ============================
  //
  /**
   * @brief Returns position of the site.
   * @return Position of site.
   */
  int position ( void ) const;


  /**
   * @brief Returns length of the site.
   * @return Length of site.
   */
  int length ( void ) const;

  // ==========================
  //  Public Methods - Setters
  // ==========================
  //
  /**
   * @brief Sets position of the site.
   * @param position Position of site.
   */
  void set_position ( int position );


  /**
   * @brief Sets length of the site.
   * @param length Length of site.
   */
  void set_length ( int length );
  

  // =======================================
  //  Public Methods - Operator overloading
  // =======================================
  //
  // Not needed for this class (use of default overloading) !
  // /*
  //  * @brief Assignment operator
  //  */
  // SiteLocation& operator= (SiteLocation& other_site_location);

  // ==================================
  //  Public Methods - Class invariant
  // ==================================
  //
  /**
   * @brief Check class invariant.
   * @return True if class invariant is preserved
   */
  virtual bool check_invariant (void) const;


private:

  // ============
  //  Attributes
  // ============
  //
  /** @brief Position of site. */
  int _position;

  /** @brief Length of site. */
  int _length;

  // =================
  //  Private Methods
  // =================
  //

};

// ======================
//  Inline declarations
// ======================
//
inline int SiteLocation::length ( void ) const { return _length; }

inline int SiteLocation::position ( void ) const { return _position; }

inline void SiteLocation::set_length ( int length )
{ 
  REQUIRE( length > 0 ); /** @pre Length must be positive. */
  _length = length;
}

inline void SiteLocation::set_position ( int position )
{ 
  REQUIRE( position > 0 ); /** @pre Position must be positive. */
  _position = position;
}


#endif // SITELOCATION_H
