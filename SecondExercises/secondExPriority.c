#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct process{
    int id, atime, btime, priority;
};

int cmpArrival(const void *a, const void *b){
    struct process *x = (struct process *) a;
    struct process *y = (struct process *) b;
    return x->atime > y->atime;
}

int main()
{
    // Initialize variables
    int i = 0, num_processes = 0, total_time = 0, x, output_flag = 0,
        time_quantum = 0;
    int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10],
        temp[10], priorities[10];
    float average_wait_time = 0, average_turnaround_time = 0;
    bool round_robin_algorithm = false;
    for (i = 0; i < 10; i++)
    {
        arrival_time[i] = 0;
        burst_time[i] = 0;
        temp[i] = 0;
        priorities[i] = -1;
    }

    // Define Number of Processes
    while (num_processes < 1 || num_processes > 10)
    {
        printf("\nEnter Total Number of Processes (1 - 10):\t");
        scanf("%d", &num_processes);
        if (num_processes < 1 || num_processes > 10)
        {
            printf("Incorrect Value Entered");
        }
    }
    // Define Process Details
    x = num_processes;
    struct process pArr[num_processes];
    for (i = 0; i < num_processes; i++)
    {
        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Arrival Time (>-1):\t");
        scanf("%d", &arrival_time[i]);

        printf("Burst Time (>0):\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
        
        printf("Priority (>=0):\t");
        scanf("%d",&priorities[i]);

        pArr[i].id = i+1;
        pArr[i].atime = arrival_time[i];
        pArr[i].btime = burst_time[i];
        pArr[i].priority = priorities[i];

        if (arrival_time[i] < 0 || burst_time[i] < 1 || priorities < 0)
        {
            printf("Incorrect Values Entered");
            i--;
        }
    }

    // Define Quantum
    if (round_robin_algorithm)
    {
        while (time_quantum < 1)
        {
            printf("\nEnter Time Quantum (>0):\t");
            scanf("%d", &time_quantum);
            if (time_quantum < 1)
            {
                printf("Incorrect Value Entered");
            }
        }
    }

    // Prepare Output
    printf("\nProcess ID\t\tArrival Time\t\tBurst Time\t\tPriority\t Turnaround Time\t Waiting Time\n");
 
    // Perform Scheduling Calculations
    if (!round_robin_algorithm)
    {
        qsort(pArr, num_processes,sizeof(struct process), cmpArrival);
        int currentTime = pArr[0].atime;
        for(int i = 0; i<num_processes;++i){
            currentTime += pArr[i].btime;
            int turnaroundTime = currentTime - pArr[i].atime;
            int waitingTime = turnaroundTime - pArr[i].btime;
            printf("\nProcess[%d] \t\t%d \t\t\t%d\t\t\t%d\t\t %d\t\t\t %d\n",pArr[i].id,pArr[i].atime,pArr[i].btime,pArr[i].priority,turnaroundTime,waitingTime);
            average_turnaround_time += (double)turnaroundTime;
            average_wait_time += (double)waitingTime;
        }
    }
    else
    {
        qsort(pArr, num_processes,sizeof(struct process), cmpArrival);
        int currentTime = pArr[0].atime;
        bool flag = true;
        while(flag){
            flag = false;
            int turnaroundTime = 0;
            int waitingTime = 0;
            for(int i = 0; i<num_processes;++i){
                if(pArr[i].btime > 0){
                    flag = true;
                    if(time_quantum>pArr[i].btime){
                        currentTime += pArr[i].btime;
                    }
                    else{
                        currentTime += time_quantum;
                    }
                    pArr[i].btime -= time_quantum;
                }
                if (pArr[i].btime<= 0 && pArr[i].id>0){
                    waitingTime = currentTime - temp[pArr[i].id -1] - pArr[i].atime;
                    turnaroundTime = waitingTime + temp[pArr[i].id -1];
                    average_turnaround_time += turnaroundTime;
                    average_wait_time += waitingTime;
                    printf("\nProcess[%d] \t\t%d \t\t\t%d\t\t\t%d\t\t %d\t\t\t %d\n",pArr[i].id,pArr[i].atime,temp[pArr[i].id-1],pArr[i].priority,turnaroundTime,waitingTime);
                    pArr[i].id = -1;
                }
            }
        }

    }
    // Calculate & Print Average Wait and Turnaround Times
    average_wait_time/=(double)num_processes;
    average_turnaround_time/=(double)num_processes;
    printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
    printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
    return 0;
}