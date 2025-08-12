// REPL for StrooLang
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

    printf("StrooLang Interactive Repl (Built by StruanMclean):\n");
    printf("!quit to quit, !clear to clear\n");

    while (1)
    {
        printf("> ");
        char *code = readline();

        if (strcmp(code, "!quit") == 0)
        {
            free(code);
            break;
        }

        if (strcmp(code, "!clear") == 0)
        {
            fclose(tmpfile);
            tmpfile = fopen("tmp/repl.sl", "w");
            ASSERT(tmpfile, "Could not open repl\n");
            fclose(tmpfile);
            
            tmpfile = fopen("tmp/repl.sl", "a");
            ASSERT(tmpfile, "Could not open repl\n");
            system("@cls||clear");
            printf("StrooLang Interactive Repl (Built by StruanMclean):\n");
            printf("!quit to quit, !clear to clear\n");
            continue;
        }

        fprintf(tmpfile, "%s\n", code);
        fflush(tmpfile);

        free(code);
    }
}

void get_repl(void)
{
    FILE *fp = fopen("tmp/repl.sl", "r");
    ASSERT(fp, "Could not open repl file");

    char *linebuffer = NULL;
    size_t size = 0;
    size_t len = 0;
    int line = 1;
    int c;

    printf("\n\nYour code which is currently stored in the repl as tmp file: \n\n");

    while ((c = fgetc(fp)) != EOF)
    {
        if (len + 1 >= size)
        {
            size = size ? size * 2 : 16;
            linebuffer = realloc(linebuffer, size);

            ASSERT(linebuffer, "Failed to read text");
        }

        linebuffer[len++] = (char)c;

        if (c == '\n') {
            linebuffer[len] = '\0';
            printf("line %i: %s", line, linebuffer);
            len = 0;
            line++;
        }
    }

    if (len > 0)
    {
        linebuffer[len] = '\0';
        printf("line %i: %s", line, linebuffer);
    }

    printf("\nEOF \n\n");

    free(linebuffer);
    fclose(fp);
}