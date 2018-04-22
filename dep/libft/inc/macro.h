//
// Created by pelluro on 23/04/18.
//

#ifndef MACRO_H
# define MACRO_H

/*
** ERROR_PRINTING_MODE:
** 0 (STD_MODE): standard mode
** 1 (DEBUG_MODE): debug mode, with non-compliant messages
** --> has to be put on 0 before pushing the project!!
** colors can be combined: "\033[41;4;32m"
*/

# ifndef NULL
#  define NULL					((void *)0)
# endif

/*
** I/O define
*/
# define STDIN					0
# define STDOUT					1
# define STDERR					2

/*
** Boolean flags
*/
# define TRUE					1
# define FALSE					0

# define ERROR_PRINTING_MODE	1

# define COL_RESET				"\033[0m"
# define COL_UNDERLINED			"\033[4m"
# define COL_REVERSE			"\033[7m"
# define COL_BLACK				"\033[22;30m"
# define COL_RED				"\033[22;31m"
# define COL_GREEN				"\033[22;32m"
# define COL_YELLOW				"\033[22;33m"
# define COL_BLUE				"\033[22;34m"
# define COL_MAGENTA			"\033[22;35m"
# define COL_CYAN				"\033[22;36m"
# define COL_WHITE				"\033[1;37m"
# define COL_GRAY				"\033[1;30m"
# define COL_LIGHT_GRAY			"\033[22;37m"
# define COL_LIGHT_RED			"\033[1;31m"
# define COL_LIGHT_GREEN		"\033[1;32m"
# define COL_LIGHT_YELLOW		"\033[1;33m"
# define COL_LIGHT_BLUE			"\033[1;34m"
# define COL_LIGHT_MAGENTA		"\033[1;35m"
# define COL_LIGHT_CYAN			"\033[1;36m"
# define COL_BACK_RED			"\033[41m"
# define COL_BACK_GREEN			"\033[42m"
# define COL_BACK_YELLOW		"\033[43m"
# define COL_BACK_BLUE			"\033[44m"
# define COL_BACK_MAGENTA		"\033[45m"
# define COL_BACK_CYAN			"\033[46m"

#endif //COREWARMINE_MACRO_H
