#include <stdio.h>
#include <pthread.h>


int thread=1;
int sum=0;

void *kidfunc(void *p)
{
    int factorial=1;
    printf("This is Thread no. = %d ",thread);
    for(int i=1; i<=thread; i++)
    {
        factorial = factorial*i;
    }
    printf(", factorial = %d ",factorial);
    sum=sum+factorial;
    thread++;
    printf("\n");

}



main ( )
{
    pthread_t kid ;
    int n;
    printf("Enter Your Number --> ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        pthread_create (&kid, NULL, kidfunc, NULL) ;
        pthread_join (kid, NULL) ;
    }
    printf("This is main thread. Total sum, S = %d ",sum);

    return 0;
}


