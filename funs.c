
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



// |||| NOTE: We need to null terminate the args?    We also need to allocate room for each word in the args array too!        ||||

int getTokens(char *s, char ***args)
{
    char *token;
    //Use strtok on char *s or str s and make char ***args have each element pointing to a separate token?
    char *tempString = strdup(s);;
        

    token = strtok(s," "); // Use space as the delimiter?
    
    

    int tokenCount = countWords(tempString);
  
    *args =  malloc((tokenCount + 1) * sizeof(char*)); // or args = or **args = // This allocates for slots for each word?
    int iterate = 0;
    while( token != NULL ) {
        //printf( " %s\n", token ); // Step through the tokens? -> (https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)
        args[iterate] = malloc((strlen(token) + 1) * sizeof(char)); //This allocates for each word?
        *args[iterate] = token;
        //printf("Argument #%i is = %s\n",iterate , *args[iterate]);
        token = strtok(NULL, " "); 
        iterate++;
        }

        (*args)[iterate] = NULL;

        /*
        for(int i = 0; i < (tokenCount); i++){
                
            printf("Argument #%i is = %s\n", i , *args[i]);
            if(i == tokenCount - 1)
                printf("argument #%p\n",args[5]);

        }      */ 
        //printf("The final token is = : %s\n",token); // Null token

        //args[tokenCount] = "\0";

    return tokenCount;
}

// Temporary (Don't use!)
int countWords(const char *s) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    return count; // + 1 for the null token
}