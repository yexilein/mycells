

/**
 * @file processivechemical.h
 * @brief Header for the ProcessiveChemical class.
 * 
 * @authors Marc Dinh, Stephan Fischer
 */


// Multiple include protection
//
#ifndef PROCESSIVECHEMICAL_H
#define PROCESSIVECHEMICAL_H

// ==================
//  General Includes
// ==================
//
#include <list> // std::list

// ==================
//  Project Includes
// ==================
//
#include "forwarddeclarations.h"
#include "boundchemical.h"

/**
 * @brief Class that represents elements that can process a chemical sequence.
 *
 * This means that, in addition to binding a chemical sequence, a processive 
 * chemical can move along it and, possibly, use the sequence as a template to
 * perform an elongation reaction.
 * Inherits class BoundChemical.
 * @sa BoundChemical Elongation
 */
class ProcessiveChemical : public BoundChemical
{
public:

  // ==========================
  //  Constructors/Destructors
  // ==========================
  //
  /**
   * @brief Constructor
   * @param stalled_form 
   *  BoundChemical that results when the processive chemical encounters
   *  a termination site (for example).
   */
  ProcessiveChemical (BoundChemical& stalled_form);

  // Not needed for this class (use of compiler-generated versions)
  // (3-0 rule: either define all 3 following or none of them)
  // /* @brief Copy constructor */
  // ProcessiveChemical (ProcessiveChemical& other_chemical);
  // /* @brief Assignment operator. */
  // ProcessiveChemical& operator= (ProcessiveChemical& other_chemical);
  // /* @brief Destructor */
  // ~ProcessiveChemical (void);

  // ===========================
  //  Public Methods - Commands
  // ===========================
  //
  /**
   * @brief Adds a termination site family that is recognized by the
   *  chemical.
   * @param family SiteFamily recognized by the chemical.
   */
  void add_recognized_termination_site (const SiteFamily& family);
  
  /**
   * @brief Move focused unit by a step of a given size.
   * @param step_size Size of step.
   */  
  void step_forward (int step_size);


  // ============================
  //  Public Methods - Accessors
  // ============================
  //
  /**
   * @brief Checks wether focused unit is on a termination site.
   * @return True if focused unit is on a termination site.
   */
  bool is_terminating (void);

  /**
   * @brief Stalled form of processive chemical.
   * @return BoundChemical that represents the stalled form.
   */
  BoundChemical& stalled_form (void);

private:
  // ============
  //  Attributes
  // ============
  //
  /** @brief The list of termination sites the chemical recognizes. */
  std::list <const SiteFamily*> _termination_sites;

  /**
   * @brief BoundChemical that results when the processive chemical encounters
   * a termination site (for example).
   */
  BoundChemical& _stalled_form;
  
  // =================
  //  Private Methods
  // =================
  //
};

// ======================
//  Inline declarations
// ======================
//
inline void ProcessiveChemical::add_recognized_termination_site (const SiteFamily& family)
{
  _termination_sites.push_back (&family);
}

inline BoundChemical& ProcessiveChemical::stalled_form ( void )
{
  return _stalled_form;
}


#endif // PROCESSIVECHEMICAL_H
