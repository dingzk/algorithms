#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>

int main(void)
{
    char a = 'A';
    if (isalpha(a)) {
        printf("%c\n", tolower(a));
    }

    //printf("%d\n", (uint8_t)str[0]);
    return 0;

}
