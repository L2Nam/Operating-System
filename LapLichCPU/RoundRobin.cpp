#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

struct process
{
    int id;
    int at;
    int bt;
    int st;
    int tat;
    int wt;
    int rt;
};

bool compareAt(process p1, process p2)
{
    return p1.at < p2.at;
}

bool compareID(process p1, process p2)
{
    return p1.id < p2.id;
}

int main()
{
    cout << "          ******Round Robin******\n\n";
    int n, tq;
    struct process p[100];
    float avg_tat, avg_wt, avg_rt;
    int total_tat = 0, total_wt = 0, total_rt = 0;
    int br[100];
    int index;

    cout << setprecision(2) << fixed;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> tq;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].at;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].bt;
        br[i] = p[i].bt;
        p[i].id = i + 1;
        cout << endl;
    }
    sort(p, p + n, compareAt);
    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;
    while (completed != n)
    {
        index = q.front();
        q.pop();

        if (br[index] == p[index].bt)
        {
            p[index].st = max(current_time, p[index].at);
            current_time = p[index].st;
        }

        if (br[index] - tq > 0)
        {
            br[index] -= tq;
            current_time += tq;
        }
        else
        {
            current_time += br[index];
            br[index] = 0;
            completed++;

            p[index].tat = current_time - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            total_tat += p[index].tat;
            total_wt += p[index].wt;
            total_rt += p[index].rt;
        }
        for (int i = 1; i < n; i++)
        {
            if (br[i] > 0 && p[i].at <= current_time && mark[i] == 0)
            {
                q.push(i);
                mark[i] = 1;
            }
        }
        if (br[index] > 0)
        {
            q.push(index);
        }

        if (q.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (br[i] > 0)
                {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }
    avg_tat = (float)total_tat / n;
    avg_wt = (float)total_wt / n;
    avg_rt = (float)total_rt / n;
    sort(p, p + n, compareID);
    cout << "#Process\t"
         << "Arrival time\t"
         << "Burst time\t"
         << "Turn around time\t"
         << "Waiting time\t"
         << "Response time\t"
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "   " << p[i].id << "\t\t     " << p[i].at << "\t\t    "
             << p[i].bt << "\t\t       " << p[i].tat << "\t\t   "
             << p[i].wt << "\t\t      " << p[i].rt << "\t"
             << endl;
    }
    cout << "Average Response Time = " << avg_rt << endl;
    cout << "Average Waiting Time = " << avg_wt << endl;
    cout << "Average Turnaround Time = " << avg_tat << endl;
    return 0;
}