/**
 * @file ocean.c
 * @author Roman Salazar (RASalazar@nic.edu)
 * @brief This program simulates a shell
 * @version 0.1
 * @date 2026-01-19
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "funs.h"





int main()
{

    int EXIT = 1; // Set exit = 0 when the user enters the word: (exit)
    char *keys[16];
    keys[0] = "help\n"; // First keyword is help (Is this the only one we need?)
    keys[1] = "exit\n";
    // Start by declaring the creator and info
    printf("Created By: Roman Salazar\n");
    printf("Type \"help\" to see implemented commands \n \n");



    while(EXIT)
    {
        char buffed[256];
        printf("rsshell> ");
        fgets(buffed,255,stdin);        
        // (Debug for output) V
        //printf("%s",buffed);
        
        // If the command == help (keyword) -> display message

        //char **arrayOfTokens, str[] = buffed;
        //int numberOfTokens;
        
        //char **arrayOfTokens, str[] = buffed; (Doesn't work) Why? Is it the null terminator or newline?
        char *stringy = buffed;
        printf("We found the buffed string = %s\n",stringy);
        

        // Parse through buffed using " " (space) as a delimiter

        // char **arrayOfTokens;
        // while(buffed[i] != "\0")
        // {


        // }
        
        char **arrayOfTokens; 
        int numberOfTokens = getTokens(buffed, &arrayOfTokens);
        printf("The number of tokens = %d\n",numberOfTokens);
        if(strcmp(buffed,keys[0]) == 0)
        {
            printf("exit - Exit Shell\n");
            printf("help - Display this message\n");
            printf("<UNIX cmd>    - Spawn child process, execute <UNIX cmd> in the foreground\n");
            printf("bg <UNIX cmd> - Spawn child process, execute <UNIX cmd> in the background\n");
            printf("bglist        - List background programs\n");
            printf("bgkill <int>  - Kill background process <int> int values: 1-5\n \n");

        }
        // If the command == exit (keyword) -> exit program
        else if(strcmp(buffed,keys[1]) == 0)
        { 
            exit(0); // Is there a cleaner method than this?

        }       
        




    }
        








}
