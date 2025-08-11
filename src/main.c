#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSERT(e, ...) if (!(e)) { fprintf(stderr, __VA_ARGS__); exit(1); }

int main(int argc, char *argv[]) 
{
    ASSERT(argc >= 2, "No arguments given\n");

    if (strcmp(argv[1], "run") == 0)
    {
        ASSERT(argc >= 3, "No file provided\n");
    }

    return 0;
}