#include <iostream>
using namespace std;

// So tien trinh
const int P = 4;

// So nguon tai nguyen
const int R = 3;

// Tinh ma tran need
void calculateNeed(int need[P][R], int maxm[P][R],
                   int allot[P][R])
{
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}

// Ktra he thong co an toan hay khong
bool isSafe(int processes[], int avail[], int maxm[][R],
            int allot[][R])
{
    int need[P][R];

    calculateNeed(need, maxm, allot);

    bool finish[P] = {0};

    int safeSeq[P];

    int work[R];
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P)
    {
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R)
                {
                    for (int k = 0; k < R; k++)
                        work[k] += allot[p][k];

                    safeSeq[count++] = p;

                    finish[p] = 1;

                    found = true;
                }
            }
        }

        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }

    cout << "System is in safe state.\nSafe"
            " sequence is: ";
    for (int i = 0; i < P; i++)
        cout << safeSeq[i] << " ";

    return true;
}

int main()
{
    int processes[] = {0, 1, 2, 3};

    int avail[] = {3, 2, 1};

    int maxm[][R] = {{3, 0, 2},
                     {3, 1, 1},
                     {0, 1, 2},
                     {3, 2, 0}};

    int allot[][R] = {
        {1, 0, 2},
        {2, 1, 0},
        {0, 1, 1},
        {2, 2, 0}};

    isSafe(processes, avail, maxm, allot);

    return 0;
}