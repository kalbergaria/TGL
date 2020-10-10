#ifndef TLIB_H
#define TLIB_H

////////////////////////////////////////////////////////////////////////////////////////////////////
// NAMESPACE:
// The TLib (short for Terminal Library) namespace contains functions for advanced terminal
// printing/formatting. Check out the full list of festures below.
//
// FEATURE SUMMARY:
// - Specify text colors
// - Clear the terminal
// - Draw boxes
// - Center text in a row
// - Center text in the terminal
// - Print text at a particular line/column
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace TLib
{

////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTANTS:
////////////////////////////////////////////////////////////////////////////////////////////////////
// Colors
static const char* ANSI_COLOR_RED     = "\x1b[31m";
static const char* ANSI_COLOR_GREEN   = "\x1b[32m";
static const char* ANSI_COLOR_YELLOW  = "\x1b[33m";
static const char* ANSI_COLOR_BLUE    = "\x1b[34m";
static const char* ANSI_COLOR_MAGENTA = "\x1b[35m";
static const char* ANSI_COLOR_CYAN    = "\x1b[36m";
static const char* ANSI_COLOR_RESET   = "\x1b[0m";
// Commands
static const char* TERM_CLEAR         = "\e[1;1H\e[2J";

////////////////////////////////////////////////////////////////////////////////////////////////////
// TYPES:
////////////////////////////////////////////////////////////////////////////////////////////////////
enum TextColor
{
	FIRST_COLOR,
	RED = FIRST_COLOR,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	RESET,
	NUM_COLORS
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// METHODS:
//
// UNITS: All coordinates map to lines and columns from the top left corned of the terminal.
//        x-axis -> columns
//        y-axis -> lines/rows
////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned short getTerminalWidth();
unsigned short getTerminalHeight();
bool validateTerminalSize(unsigned short height, unsigned short width);
void setTerminalTextColor(TextColor color);
void clearTerminal();
void moveCursorTo(unsigned short col, unsigned short line);
void drawBox(unsigned short col, unsigned short line, unsigned short width, unsigned short height,
		TextColor color, char symbol);
void printBorderWithAllColors(unsigned short height, unsigned short width, char symbol);

} // namespace TLib

#endif // TLIB_H