
/**
 * @brief Get the Tokens object
 * 
 * @param s BLANK
 * @param args BLANK
 * @return int BLANK
 */

// This function should accept a (C-type) string and a pointer to a pointer
// to char (or, if you prefer, a pointer to an array of pointers to char) 
// (i.e., a pointer to the same type as argv in a C program), 
// and should point args to an array with each element being a pointer pointing to 
// the separate tokens extracted from the string, and it should return a number of tokens. 
// If some problem occurred during the operation of the function, the value returned should be -1.

#include <stdio.h>
#include "funs.h"


int getTokens(char *s, char ***args)
{
    char *token;
    //Use strtok on char *s or str s and make char ***args have each element pointing to a separate token?

    token = strtok(s," "); // Use space as the delimiter?

    //**args = malloc(3 * sizeof(char *));
    
    int tokenCount = 0;
    while( token != NULL ) {
     
        printf( " %s\n", token ); // Step through the tokens? -> (https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)
    
        token = strtok(NULL, " "); // Understand this
        //char *newWords = malloc(strlen(token) + 1);
        //*args[tokenCount] = token;

        tokenCount++;
    }

        //args[tokenCount] = "\0";


    return 1;

}
