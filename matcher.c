/**
 * As in every CS skeleton, the contents of this file are
 * only a suggestion. Please feel free to change anything.
 */

#include "matcher.h"

/**
 * Parses pattern for next character and sets
 * necessary parameters that are referenced inside/outside
 * of this function.
 *
 * Add any additional inputs to function signature if necessary.
 */
char *parse_char(char *partial_pattern, char *target) {
    // You can use this recommended helper function, or not.
    
    return '\0';
}

/**
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {
  // You can use this recommended helper function, or not.
  return 0;
}

/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 * 
 * This function is REQUIRED and is not a suggestion.
 */

char *oripattern;

int firsttime = 1;

void setoriginal(char *opattern) {
	if (firsttime) {
		oripattern = opattern;
	}
}

int rgrep_matches(char *line, char *pattern) {

    //
    // TODO: put your code here.
    //
    setoriginal(pattern);
    firsttime = 0;
    char *next = pattern + 1;
    if (*pattern == '\0') {
		return 1;
	}
	if (*line == '\0') {
		return 0;
	}
    if (*pattern == '\\') {
        if (*next == '\0') {
                return 0;
            }
        if (*(next + 1) == '+') {
            if (*next == *line) {
                return rgrep_matches(line + 1, pattern) ||
                rgrep_matches(line + 1, pattern + 3);
            } else {
                return rgrep_matches(line + 1, oripattern);
            }
        } else if (*(next + 1) == '?') {
            if (*next == *line) {
                return rgrep_matches(line, pattern + 3) ||
                rgrep_matches(line + 1, pattern + 3);
            } else {
                return rgrep_matches(line, pattern + 3) ||
                rgrep_matches(line + 1, pattern + 3) ||
                rgrep_matches(line + 1, oripattern);;
            }
        } else {
            if (*next == *line) {
                return rgrep_matches(line + 1, pattern + 2);
            } else {
                return rgrep_matches(line + 1,oripattern) ||
                rgrep_matches(line, oripattern);
            }
        
        }
    }
    if (*next == '+') {
    	if (*pattern == '.' || *line == *pattern) {
    		return rgrep_matches(line + 1, pattern + 2) || 
    		rgrep_matches(line + 1, pattern);
    	} else {
    		return rgrep_matches(line + 1, oripattern);
    	}
    }
    if (*next == '?') {
    	if (*pattern == '.' || *line == *pattern) {
    		return rgrep_matches(line + 1, pattern + 2) ||
    		rgrep_matches(line, pattern + 2);
    	
    	} else {
    		return rgrep_matches(line, pattern + 2) ||
    		rgrep_matches(line + 1, oripattern);
    	}
    	
    }

    if (*pattern == '.' || *line == *pattern) {
    	return rgrep_matches(line + 1, pattern + 1);
    }
    return rgrep_matches(line + 1, oripattern);
}
