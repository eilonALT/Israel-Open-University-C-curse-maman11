/* 
   ------------------------------------------------------ Maman: 11 ----------------------------------------------------------
    Eilon Alter  208500603

    This program gets input from user/file and minimize sequences
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*-------------------------------------------------- minimize function --------------------------------------------------------*/

void contract(char s1[], char s2[])
{
    int separator = 0; /* track if "-" is needed */
    int i = 0;
    int lastValue = (int)s1[0];

    strcpy(s2, "");
    strncat(s2, s1, 1);

    for (i = 1; i <= strlen(s1); i++) /* Loop on every char in the input */
    {
        int currentValue = (int)s1[i];

        if ((isalpha(s1[i]) || isdigit(s1[i])) && (isalpha(s1[i - 1]) || isdigit(s1[i - 1])) && currentValue == lastValue + 1)
        {
            if (separator == 0)
            {
                separator = 1;
            }
            else if (separator == 1)
            {
                strcat(s2, "-");
                separator = 2;
            }
        }
        else
        {
            if (separator != 0)
            {
                strncat(s2, &s1[i - 1], 1);
            }
            separator = 0;
            strncat(s2, &s1[i], 1);
        }

        lastValue = currentValue;
    }
}

int main()
{
    char string1[81];
    char string2[81] = "";

    printf("Please enter a string:\n\n");
    fgets(string1, 81, stdin);
    printf("The original string is: %s \n\n", string1);
    contract(string1, string2);
    printf("The result string is: %s \n", string2);

    return 0;
}