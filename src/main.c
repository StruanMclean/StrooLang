#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/repl.h"

int main(int argc, char *argv[]) 
{
    ASSERT(argc >= 2, "No arguments given\n");

    if (strcmp(argv[1], "run") == 0)
    {
        ASSERT(argc >= 3, "No file provided\n");
    }

    else if (strcmp(argv[1], "repl") == 0)
    {
        if ((argc > 2) && (strcmp(argv[2], "get") == 0))
        {
            get_repl();
            return 0;
        } else
        {
            repl();
            return 0;
        }
    }

    return 0;
}