#include "philo.h"
#include <stdlib.h>

/** void * is generic **/

void*    myturn(void *arg)
{
    int i;
    int *i_ptr = (int *) malloc(sizeof(int)); // pthreads returns ultimately an int* value
    *i_ptr = 5;

    i = 0;
    while(i++ < 8)
    {
        sleep(1);
        printf("My Turn : %d %d\n", i, *i_ptr);
        (*i_ptr)++;
    }
    return (i_ptr);
}

void*    uturn()
{
    int i;
    i = 0;
    while(i++ < 3)
    {
        sleep(1);
        printf("your Turn : %d\n", i);
    }
    return(NULL);

}

// ** pthread retunrns void pointing
/*int main()
{
    pthread_t new_t;
    int *res;


    pthread_create(&new_t, NULL, myturn, NULL);
    //pthread_create(&new_t, NULL, uturn, &v);
    uturn();
    pthread_join(new_t, (void *)&res); // typecast it alwaays
    printf("threads done: *res = %d\n", *res); // Its returning an address
}*/
/** Thread safety **/
/**
 *
 */
#define BIG 100000000L
u_int64_t count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count_big(void *arg)
{
    u_int32_t i;
    i = 0;
    while (i++ < BIG)
    {
        pthread_mutex_lock(&lock); //--> thread waits here until it gets the lock.
        count++;
        pthread_mutex_unlock(&lock);
    }
    return (NULL);
}

/** i++ --> read i-> compute i+1 -> store new val (3 things)
 * Example of Race condition -->
 *
 * Fix --> Make the increment operator atomic ( One by one increment in individual thread/process)
 *  Here comes -> mutex locks ( exclusion locks)
 *  But makes it slower
 *
 *  Parallelism -> needs hardware support(multiple core)
 *
 *  Benefits of THreads:
 *  1. User interface interaction
 *  2. Cons-> complex
 * @return
 */
int main()
{
    pthread_t t;
    pthread_create(&t, NULL,count_big, NULL);
    count_big(NULL);
    pthread_join(t, NULL);
    printf("done. Counter = %llu\n", count);

}
