#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

    int p = CreateProcessA() ;

    if(p==-1){
        exit(-1) ;
    } else if(p==0) {
        printf("------fils------");
        printf("pid du processus : %d\n", getpid());
        printf("pid du père : %d\n", getppid());
        printf("----------------");
    } else {
        printf("pid du processus : %d\n", getpid());
        printf("pid du père : %d\n", getppid());
        printf("pid du fils : %d\n", p);
        WaitForSingleObject();
    }

    return EXIT_SUCCESS;
}
