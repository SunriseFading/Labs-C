#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int
main ()
{
    setlocale (LC_ALL, "rus");
    char s[255];
    int i, j, count, count_num, count_alph;
    char vowel[]= "aeiouAEIOUÀÎÓÝÈÛßÅ¨Þàîóýûÿå¸þ";
    FILE *f=NULL;
    f = fopen ("file.txt", "r");
                    count = 0;
                    while (fgets (s, 255, f))
                    {
                        size_t len= strlen (s);
                        for (size_t i= 0; i< len; ++i)
                        {
                            if (ispunct (s[i]))
                            {
                                count++;
                            }
                        }
                    }
                    fclose (f);
                    printf ("Êîëè÷åñòâî çíàêîâ = %d\n", count);