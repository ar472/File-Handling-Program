#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;

    /* ---------------- CREATE & WRITE TO FILE ---------------- */
    fp = fopen("data.txt", "w"); // File create / open in write mode

    if (fp == NULL)
    {
        printf("File cannot be created\n");
        return 1;
    }

    fprintf(fp, "Hello, this is File Handling Program in C.\n");
    fprintf(fp, "This file is created using write mode.\n");

    fclose(fp); // Close file
    printf("Data written successfully.\n\n");

    /* ---------------- APPEND DATA TO FILE ---------------- */
    fp = fopen("data.txt", "a"); // Open file in append mode

    if (fp == NULL)
    {
        printf("File cannot be opened for appending\n");
        return 1;
    }

    fprintf(fp, "This line is appended to the file.\n");

    fclose(fp);
    printf("Data appended successfully.\n\n");

    /* ---------------- READ DATA FROM FILE ---------------- */
    fp = fopen("data.txt", "r"); // Open file in read mode

    if (fp == NULL)
    {
        printf("File cannot be opened for reading\n");
        return 1;
    }

    printf("Reading data from file:\n\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch); // Print each character
    }

    fclose(fp); // Close file

    return 0;
}
