#ifndef MMIND_CMDLINEPARSING_H_INCLUDED
#define MMIND_CMDLINEPARSING_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include <string>
#include <utility>
#include <iosfwd>

namespace NMasterMind
{

/**
 * Prints a usage string; displays the command line options
 *
 * @param a_progName the executable name to prepend to the usage statement
 * @param ar_str the output stream
 */
void usage( const char *a_progName, std::ostream &ar_str);

/**
 * Checks the options
 *
 * @param argc the argument count
 * @param argv the argument list
 * @return a pair, encapsulating status and a code given by the user, if any.
 */
std::pair<bool, std::string> checkOpts( int argc, char **argv );

}

#endif  // MMIND_CMDLINEPARSING_H_INCLUDED
