#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTime(struct process proc[], int n, int quantum) {
    int t = 0;
    bool done;
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                done = false;
                if (proc[i].remaining_time > quantum) {
                    t += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    t += proc[i].remaining_time;
                    proc[i].waiting_time = t - proc[i].burst_time;
                    proc[i].remaining_time = 0;
                }
            }
        }
    } while (!done);
}

void calculateTurnaroundTime(struct process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void priorityRoundRobin(struct process proc[], int n, int quantum) {
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time;
    }

    calculateWaitingTime(proc, n, quantum);
    calculateTurnaroundTime(proc, n);

    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waiting_time;
        total_tat += proc[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n, quantum;
    struct process proc[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].arrival_time, &proc[i].burst_time, &proc[i].priority);
        proc[i].pid = i + 1;
    }

    // Sort processes by priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].priority > proc[j + 1].priority) {
                struct process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    priorityRoundRobin(proc, n, quantum);

    return 0;
}