#include <string.h>
#include <stdio.h>

/* Print binary stored in plain 32 bit block */ 
void intToBinary(unsigned int n)
{
        int c, k;
        for (c = 31; c >= 0; c--)
        {
                k = n >> c;
                if (k & 1)  printf("1");
                else        printf("0");
        }
        printf("\n");
}

int main(void) 
{
        unsigned int m;
        float f = 3.14;

        /* See hex representation */
        printf("f = %a\n", f);  


        /* Copy memory representation of float to plain 32 bit block */
        memcpy(&m, &f, sizeof (m));     
        intToBinary(m);

        return 0;
}
