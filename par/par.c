/* 
   ------------------------------------------------------ Maman: 11 ----------------------------------------------------------
    Eilon Alter  208500603

    This program gets input from user/file and validating brackets in the input per line and total
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* ------------------------------------------------- function to validate row in the input ---------------------------------------- */
bool isRowValid(char openBracket, char closeBracket, char i, char rowOpensBracketsArray[])
{
    if (i == closeBracket)
    {
        if (rowOpensBracketsArray[strlen(rowOpensBracketsArray) - 1] == openBracket)
        {
            rowOpensBracketsArray[strlen(rowOpensBracketsArray) - 1] = '\0';
        }
        else
        {
            return false;
        }
    }
    return true;
}

/* ----------------------------------------- function to validate the total input--------------------------------------------------  */
bool isTotalValid(char openBracket, char closeBracket, char i, char totalArr[])
{
    if (i == closeBracket)
    {
        if (totalArr[strlen(totalArr) - 1] == openBracket)
        {
            totalArr[strlen(totalArr) - 1] = '\0';
        }
        else
        {
            return false;
        }
    }
    return true;
}

/* --------------------------------------------- function to add string ----------------------------------------------------------- */
void add(char *s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

/*---------------------------------------------------- function to validate input  -------------------------------------------------------------------*/
void checkValidation()
{
    char i;

    char rowOpensBracketsArray[100]; /* keep the rows opening brackets*/
    char totalArr[100];   /* keep the total opening brackets*/

    bool rowValid = true;   /* decide if row is valid or not*/
    bool totalValid = true; /* decide if total is valid or not*/

    bool isQuote = false; /* track the quotes*/
    int isComment = 0;    /* track the comments*/

    strcpy(rowOpensBracketsArray, "");

    printf("Please enter a string:\n");

    while ((i = getchar()) != EOF) /* Loop untill EOF*/
    {
        printf("%c", i); /* Print the input*/

        if ((i == '\n')) /* When a line is finished in the input*/
        {
            if (strlen(rowOpensBracketsArray) > 0)
            {
                rowValid = false;
            }
            if (rowValid == true)
            {
                printf(" This row is valid  \n\n");
            }
            else
            {
                printf(" This row is not valid  \n\n");
            }
            rowValid = true;
            strcpy(rowOpensBracketsArray, "");
        }

        if (i == '/') /* if it part of a comment*/
        {
            if (isComment == 0)
            {
                isComment = 1;
                continue;
            }
            else if (isComment == 3)
            {
                isComment = 0;
                continue;
            }
        }

        if (i == '*') /* if it part of a comment*/
        {
            if (isComment == 1)
            {
                isComment = 2;
                continue;
            }
            else if (isComment == 2)
            {
                isComment = 3;
                continue;
            }
        }
        else if (isComment == 3) /* if it part of a comment*/
        {
            isComment = 2;
        }

        if (i == '"') /* if it part of a quote*/
        {
            if (isQuote == false)
            {
                isQuote = true;
                continue;
            }
            else
            {
                isQuote = false;
                continue;
            }
        }

        if ((isQuote == true) || (isComment == 2)) /* if it part of a quote*/
        {
            continue;
        }

        if ((i == '{') || (i == '[') || (i == '(')) /*add open brackets to arry*/
        {
            add(rowOpensBracketsArray, i);
            add(totalArr, i);
        }
        else
        {
            rowValid = isRowValid('{', '}', i, rowOpensBracketsArray) && isRowValid('[', ']', i, rowOpensBracketsArray) && isRowValid('(', ')', i, rowOpensBracketsArray); 

            totalValid = totalValid && isTotalValid('{', '}', i, totalArr) && isTotalValid('[', ']', i, totalArr) && isTotalValid('(', ')', i, totalArr);
        }
    }

    if (strlen(rowOpensBracketsArray) > 0) /* check the last row after EOF */
    {
        rowValid = false;
    }
    if (rowValid == true)
    {
        printf("\n This row is valid  \n\n");
    }
    else
    {
        printf("\n This row is not valid  \n\n");
    }
    
    /*------------------------------- printing the total outputs -----------------------------------------*/
    if (strlen(totalArr) > 0 || totalValid == false)
    {
        printf("--------------------------------------------------------------------------------------------------- \n");
        printf("The total input is not valid \n");
    }
    else
    {
        printf("---------------------------------------------------------------------------------------------------- \n");
        printf("The total input is valid \n");
    }
}

int main()
{
    checkValidation();
    return 0;
}