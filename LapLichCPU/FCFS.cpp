#include <iostream>

using namespace std;

float average(int a[], int n)
{
    float t = a[0];
    for (int i = 1; i < n; i++)
    {
        t += a[i];
    }
    return t / n;
}

int main()
{
    cout << "          ******FCFS******\n\n";
    int n, t = 0;
    cout << "Enter number of processes: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Error!!!\n";
        return 0;
    }
    int a[n], b[n], w[n], tat[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << '\n';
        cout << "Enter AT: ";
        cin >> a[i];
        cout << "Enter BT: ";
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > t)
        {
            t = a[i];
        }
        w[i] = t - a[i];
        t += b[i];
        tat[i] = t - a[i];
    }
    cout << "Process  "
         << " Arrival time  "
         << " Burst time  "
         << " Waiting time  "
         << " Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i + 1 << "\t       " << a[i] << "\t     " << b[i] << "\t           "
             << w[i] << "\t\t    " << tat[i] << endl;
    }
    cout << "Average waiting time = "
         << average(w, n);
    cout << "\nAverage turn around time = "
         << average(tat, n) << "\n";
    return 0;
}