// External Includes
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

// Project Includes

// Definitions
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Constants
const char BORDER_CHAR = '*';
const char* START_TEXT = "PRESS ANY BUTTON TO START!";

// Types
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

// Prototypes
void validateTerminalSize(unsigned short height, unsigned short width);
void setTerminalTextColor(TextColor color);
void clearTerminal();
void drawBox(unsigned short x, unsigned short y, unsigned short width, unsigned short height, TextColor color, char symbol);
void printBorder(unsigned short height, unsigned short width, char symbol);

int main()
{
	// Get the height and width of the terminal
	struct winsize size;
	ioctl( 0, TIOCGWINSZ, (char *) &size );
	const unsigned short TERM_HEIGHT = size.ws_row;
	const unsigned short TERM_WIDTH = size.ws_col;

	// Check that the terminal meets any minimum size requirements
	validateTerminalSize(TERM_HEIGHT, TERM_WIDTH);

	// Clear the terminal
	clearTerminal();

	// Print the border
	printBorder(TERM_HEIGHT, TERM_WIDTH, BORDER_CHAR);

	printf("Rows: %u\nColumns: %u\n", size.ws_row, size.ws_col);

	// printf("FIRST_COLOR=%d\n", FIRST_COLOR);
	// printf("RED=%d\n", RED);
	// printf("GREEN=%d\n", GREEN);

	//usleep(3000000);
	return 0;
}

void validateTerminalSize(unsigned short height, unsigned short width)
{

}

void setTerminalTextColor(TextColor color)
{
	switch (color)
	{
		case RED:
			printf(ANSI_COLOR_RED);
			break;
		case GREEN:
			printf(ANSI_COLOR_GREEN);
			break;
		case YELLOW:
			printf(ANSI_COLOR_YELLOW); 
			break;
		case BLUE:
			printf(ANSI_COLOR_BLUE);
			break;
		case MAGENTA:
			printf(ANSI_COLOR_MAGENTA);
			break;
		case CYAN:
			printf(ANSI_COLOR_CYAN);
			break;
		case RESET:
			printf(ANSI_COLOR_RESET);
			break;
		default:
			break;
	}
}

void clearTerminal()
{
	printf("\e[1;1H\e[2J");
}

void drawBox(unsigned short x, unsigned short y, unsigned short width, unsigned short height, TextColor color, char symbol)
{

}

void printBorder(unsigned short height, unsigned short width, char symbol)
{
	// Print the top border
	for(unsigned short i = FIRST_COLOR; i < NUM_COLORS; i++)
	{
		setTerminalTextColor((TextColor)i);
		for(unsigned short j = 0; j < width; j++)
		{
			putchar(symbol);
		}

		putchar('\n');
	}
}