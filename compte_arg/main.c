#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int S = 0 ;
    int i = 0 ;
    for(i = 1; i < argc; i++){
        S += atoi(argv[i]) ;
    }
    printf("%d", S);

    return EXIT_SUCCESS ;
}

