#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* calculte(char str1[],char str2[])
{
    int k;
    char *str3;
    str3=(char*)malloc(sizeof(char)*100);
    for(int i=0;i<strlen(str1);i++)
    {
        for(int j=0;j<strlen(str2);j++)
        {
            if(str1[i]==str2[j])
            {
                k=0;
                if(strlen(str3)<strlen(str2)-j+i)
                {
                    for(int t=0;t<=i;t++)
                    {
                        str3[k]=str1[t];
                        k++; 
                    }
                    for(int t=j+1;t<strlen(str2);t++)
                    { 
                        str3[k] = str2[t];
                        k++;
                    }    
                }   
            }
        }
    }
   return str3;
}

int main() 
{   
    char str1[100];
    char str2[100];
    char* str3;
    char* str4;

    scanf("%s",str1);
    scanf("%s",str2);
    str3=calculte(str1,str2);
    str4 =calculte(str2,str1);
    if (strlen(str3)==0 && strlen(str4)==0 )
    printf("*");
    else if(strlen(str4)>strlen(str3))
    {
        printf("%s\n",str4);
        printf("%ld",strlen(str4));
    }
    else 
    {
       printf("%s\n",str3);
       printf("%ld",strlen(str3));
    }    
    return 0;
}