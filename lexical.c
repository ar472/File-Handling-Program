#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* List of C keywords */
char keywords[10][10] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void", "main"};

/* Function to check keyword */
int isKeyword(char word[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    FILE *fp;
    char ch, buffer[20];
    int i = 0;

    fp = fopen("input.txt", "r"); // Input file

    if (fp == NULL)
    {
        printf("Cannot open input file\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        /* Operator checking */
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>')
        {
            printf("Operator : %c\n", ch);
        }

        /* Identifier / Keyword checking */
        else if (isalnum(ch))
        {
            buffer[i++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && i != 0)
        {
            buffer[i] = '\0';
            i = 0;

            if (isKeyword(buffer))
                printf("Keyword  : %s\n", buffer);
            else
                printf("Identifier : %s\n", buffer);
        }
    }

    fclose(fp);
    return 0;
}
