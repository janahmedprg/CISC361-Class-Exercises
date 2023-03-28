#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#define MAX_NO_OF_THREADS 500
#define MAX_NO_OF_ELEMENTS 100000000
typedef struct arg_data {
    int thread_number;
} arg_data;
//shared data on which threads will work concurrently
//array which will be summed
static int arr[MAX_NO_OF_ELEMENTS];
//sum variable that will store the total sum
static long long int sum;
void* worker_sum(void* arg)
{
    arg_data* current_thread_data = (arg_data*)arg;
 
    printf("Current thread no is : %d\n", current_thread_data->thread_number);
 
    //Determine the bounds
    int startpart = (current_thread_data->thread_number-1)*(MAX_NO_OF_ELEMENTS/MAX_NO_OF_THREADS);
    int endpart = (current_thread_data->thread_number)*(MAX_NO_OF_ELEMENTS/MAX_NO_OF_THREADS);
    printf("Here we will sum %d to %d\n", arr[startpart], arr[endpart - 1]);
    //Generate the sum
    long long int current_thread_sum = 0;
    for(int i = startpart+1; i<=endpart;++i){
        current_thread_sum +=i;
    }
    sum += current_thread_sum;
 
    return NULL;
}
int main()
{
    //let the array consists of first MAX_NO_OF_ELEMENTS integers,
    //1 to MAX_NO_OF_ELEMENTS
    for (int i = 0; i < MAX_NO_OF_ELEMENTS; i++)
        arr[i] = i + 1;
   
    //pthread objects
    pthread_t id[MAX_NO_OF_THREADS];
   
    //argument data to send in worker functions
    arg_data arg_arr[MAX_NO_OF_THREADS];
   
    //total number of threads we will create
    int no_of_threads = MAX_NO_OF_THREADS;
    printf("Creating %d number of threads...\n", no_of_threads);
    //Setup timing
    clock_t start, end;
    double cpu_time_taken;
    start = clock(); 
    //creating the child threads
    for(int i = 0;i<MAX_NO_OF_THREADS;++i){
        arg_arr[i].thread_number = i +1; 
        pthread_create(&id[i], NULL, worker_sum, &arg_arr[i]);
    }
    //joining the threads one by one
    for(int i = 0; i<MAX_NO_OF_THREADS; ++i){
        pthread_join(id[i],NULL);
    }
    end = clock();
    cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("All child threads has finished their works...\n");
    printf("Total sum: %lld\n", sum);
    printf("Time taken to sum all the numbers are %lf\n", cpu_time_taken);
    return 0;
}