#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int bt; // Burst Time
    int at; // Arrival Time
};

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// waiting time of all process
void findWaitingTime(Process proc[], int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if (check == false)
        {
            t++;
            continue;
        }
        // decrementing the remaining time
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
        // If a process gets completely
        // executed
        if (rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;
            // Calculate waiting time
            wt[shortest] = finish_time -
                           proc[shortest].bt -
                           proc[shortest].at;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        // Increment time
        t++;
    }
}
// Function to calculate average time
void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                       total_tat = 0;
    // Function to find waiting time of all
    // processes
    findWaitingTime(proc, n, wt);
    // Function to find turn around time for
    // all processes
    findTurnAroundTime(proc, n, wt, tat);
    cout << "Processes "
         << " Burst time "
         << "     Waiting time = Response time"
         << "     Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i + 1 << "\t\t" << proc[i].bt << "\t\t       " << wt[i] << "\t\t             " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = Average response time =" << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n << endl;
}
// main function
int main()
{
    int n;
    cout << "        ******SJF_non_pre******\n\n";
    cout << "Enter number of processes: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Error!!!\n";
        return 0;
    }
    Process proc[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << '\n';
        cout << "Enter AT: ";
        cin >> proc[i].at;
        cout << "Enter BT: ";
        cin >> proc[i].bt;
    }
    int no = sizeof(proc) / sizeof(proc[0]);
    findavgTime(proc, no);
    return 0;
}