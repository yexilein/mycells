// 
// Copyright 2017 INRA
// Authors: M. Dinh, S. Fischer
// Last modification: 2017-09-19
// 
// 
// Licensed under the GNU General Public License.
// You should have received a copy of the GNU General Public License
// along with BiPSim.  If not, see <http://www.gnu.org/licenses/>.
// 


/**
 * @file reactantbuilder.h
 * @brief Header for the BindingSiteBuilder, SwitchBuilder, SwitchSiteBuilder,
 *  FreeChemicalBuilder, BoundChemicalBuilder, ChemicalSequenceBuilder,
 *  DoubleStrandBuilder classes.
 * @authors Marc Dinh, Stephan Fischer
 */

// Multiple include protection
//
#ifndef REACTANT_BUILDER_H
#define REACTANT_BUILDER_H

// ==================
//  General Includes
// ==================
//

// ==================
//  Project Includes
// ==================
//
#include "builder.h"

// ======================
//  Forward declarations
// ======================
//
#include "forwarddeclarations.h"

/**
 * @brief Class creating BindingSite from text input.
 */
class BindingSiteBuilder : public Builder
{
 public:
  /**
   * @brief Constructor.
   * @param cell_state Object in which entities are stored and fetched from.
   */
  BindingSiteBuilder (CellState& cell_state);

  // redefined from Builder
  bool match (InputLine& text_input);

 private:
  /** @brief Check validity of positions read. */
  void check_positions (const ChemicalSequence& location);

  // format and values read
  Rule _format; 
  IntToken _rf_format;
  std::string _family_name, _location_name;
  int _start, _end, _reading_frame;
  double _k_on, _k_off; 
};

/**
 * @brief Class creating Switch from text input.
 */
class SwitchBuilder : public Builder
{
 public:
  /**
   * @brief Constructor.
   * @param cell_state Object in which entities are stored and fetched from.
   */
  SwitchBuilder (CellState& cell_state);

  // redefined from Builder
  bool match (InputLine& text_input);

 private:
  // format and values read
  Rule _format; 
  std::string _name, _input, _output;
};

/**
 * @brief Class creating a SwitchSite from text input.
 */
class SwitchSiteBuilder : public Builder
{
 public:
  /**
   * @brief Constructor.
   * @param cell_state Object in which entities are stored and fetched from.
   */
  SwitchSiteBuilder (CellState& cell_state);

  // redefined from Builder
  bool match (InputLine& text_input);

 private:
  // format and values read
  Rule _format; 
  std::string _location, _switch_name;
  int _position;
};

/**
 * @brief Class creating FreeChemical from text input.
 */
class FreeChemicalBuilder : public Builder
{
 public:
  /**
   * @brief Constructor.
   * @param cell_state Object in which entities are stored and fetched from.
   */
  FreeChemicalBuilder (CellState& cell_state);

  // redefined from Builder
  bool match (InputLine& text_input);

 private:
  // format and values read
  Rule _format;
  TagToken _constant_tag;
  std::string _name;
};

/**
 * @brief Class creating BoundChemical from text input.
 */
class BoundChemicalBuilder : public Builder
{
 public:
  /**
   * @brief Constructor.
   * @param cell_state Object in which entities are stored and fetched from.
   */
  BoundChemicalBuilder (CellState& cell_state);

  // redefined from Builder
  bool match (InputLine& text_input);

 private:
  // format and values read
  Rule _format;
  std::string _name;
};

/**
 * @brief Class creating ChemicalSequence from text input.
 */
class ChemicalSequenceBuilder : public Builder
{
 public:
  /**
   * @brief Constructor.
   * @param cell_state Object in which entities are stored and fetched from.
   */
  ChemicalSequenceBuilder (CellState& cell_state);

  // redefined from Builder
  bool match (InputLine& text_input);

 private:
  /** @brief Check validity of product bounds. */
  void check_out_of_bounds (const ChemicalSequence& parent);
  /** @brief Check validity of child sequence. */
  void check_child_sequence (void);
  /** @brief Check inferred sequence corresponds to existing sequence. */
  void check_product_consistency (const ChemicalSequence& chemical);

  // format and values read
  Rule _header_format, _sequence_format, _product_format;
  std::string _name, _sequence, _parent_name, _table_name;
  int _pos1, _pos2;
};

/**
 * @brief Class creating DoubleStrand from text input.
 */
class DoubleStrandBuilder : public Builder
{
 public:
  /**
   * @brief Constructor.
   * @param cell_state Object in which entities are stored and fetched from.
   */
  DoubleStrandBuilder (CellState& cell_state);

  // redefined from Builder
  bool match (InputLine& text_input);

 private:
  // format and values read
  Rule _format;
  std::string _name, _sense_name, _antisense_name, 
    _sequence, _table_name, _circularity;
};


#endif // REACTANT_BUILDER_H
