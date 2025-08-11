#include "../include/repl.h"

char *readline(void)
{
    char *buffer = NULL;
    size_t size = 0;
    size_t len = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (len + 1 >= size)
        {
            size = size ? size * 2 : 16;
            buffer = realloc(buffer, size);
            
            ASSERT(buffer, "Failed to read text");
        }
        
        buffer[len++] = (char)c;
    }

    if (buffer) buffer[len] = '\0';
    return buffer;
}

void repl(void)
{
    // Clear repl before opening
    FILE *tmpfile = fopen("tmp/repl.sl", "w");
    ASSERT(tmpfile, "Could not open repl\n");
    fclose(tmpfile);
    
    tmpfile = fopen("tmp/repl.sl", "a");
    ASSERT(tmpfile, "Could not open repl\n");

    while (1)
    {
        printf("> ");
        char *code = readline();

        fprintf(tmpfile, "%s\n", code);
        fflush(tmpfile);

        if (strcmp(code, "!quit") == 0)
        {
            free(code);
            break;
        }

        free(code);
    }
}