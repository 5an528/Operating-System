#include <stdio.h>
#include <pthread.h>
#include <math.h>

int num = 1;
int thread=1;
int sum=0,sum1=0;
void *kidfunc(void *p)
{
    int i, flag;
    printf("Thread no. = %d ",thread);
    printf(", Value Start = %d ",num);
    for(i=num; i<=num+9; i++)
    {
        sum=sum+i;
        flag=i;
        sum1=sum1+i;
    }
    printf(", Value end = %d ",flag);
    printf(", Sum = %d ",sum);
    sum=0;
    thread++;
    printf("\n");

}



main ( )
{
    pthread_t kid ;
    int i;

    for(i=0; i<7; i++)
    {
        pthread_create (&kid, NULL, kidfunc, NULL) ;
        pthread_join (kid, NULL) ;
        num+=10;
    }
    printf("This is main thread. Total sum, S = %d ",sum1);

    return 0;
}

