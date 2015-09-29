

/**
 * @file parser.cpp
 * @brief Implementation of the Parser class.
 * 
 * @authors Marc Dinh, Stephan Fischer
 */


// ==================
//  General Includes
// ==================
//
#include <iostream> // std::cout
#include <fstream> // std::ifstream
#include <sstream> // std::istringstream
#include <string> // std::string

// ==================
//  Project Includes
// ==================
//
#include "parser.h"
#include "factory.h"
#include "cellstate.h"
#include "inputdata.h"

// ==========================
//  Constructors/Destructors
// ==========================
//
Parser::Parser (CellState& cell_state, EventHandler& event_handler)
  : _unit_factory (cell_state)
  , _reaction_factory (cell_state)
  , _event_factory (cell_state, event_handler)
{
}

// Not needed for this class (use of default copy constructor) !
// Parser::Parser ( const Parser& other_parser );

Parser::~Parser (void)
{
}

// ===========================
//  Public Methods - Commands
// ===========================
//
void Parser::parse (InputData& input_data)
{
  // we loop through the data until no creation takes place anymore
  // the idea is that as long as dependencies may not have been resolved
  // we need to try to create everything again
  while (loop_through_data (input_data) == true) {}
}

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
// Not needed for this class (use of default overloading) !
// Parser& Parser::operator= ( const Parser& other_parser );

// =================
//  Private Methods
// =================
//
bool Parser::loop_through_data (InputData& input_data)
{
  bool entity_created = false;
  input_data.rewind();
  while (input_data.is_eof()==false)
    {
      if (_unit_factory.handle (input_data.line())
	  || _reaction_factory.handle (input_data.line())
	  || _event_factory.handle (input_data.line()))
	{
	  entity_created = true;
	  input_data.mark_line_as_treated();
	}

      input_data.go_next();
    }

  return entity_created;
}
