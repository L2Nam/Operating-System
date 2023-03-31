#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "    **************************FIFO****************************\n\n";
    int i, j, k, n, hitCount = 0;
    int frames = 3;
    vector<int> pages;
    cout << "Length of reference string: ";
    cin >> n;
    cout << "Enter reference string: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pages.push_back(x);
    }
    cout << "Enter number of frames: ";
    cin >> frames;
    vector<int> hit(n);
    vector<vector<int>> a(frames);
    cout << "\n";
    for (i = 0; i < frames; i++)
    {
        a[i] = vector<int>(n, -1);
    }
    map<int, int> mp;
    for (i = 0; i < n; i++)
    {
        vector<pair<int, int>> c;
        for (auto x : mp)
        {
            c.push_back({x.second, x.first});
        }
        sort(c.begin(), c.end());
        bool hasCompleted = false;
        for (j = 0; j < frames; j++)
        {
            if (a[j][i] == pages[i])
            {
                hitCount++;
                hit[i] = true;
                mp[pages[i]]++;
                hasCompleted = true;
                break;
            }
            if (a[j][i] == -1)
            {
                for (k = i; k < n; k++)
                    a[j][k] = pages[i];
                mp[pages[i]]++;
                hasCompleted = true;
                break;
            }
        }
        if (j == frames || hasCompleted == false)
        {
            for (j = 0; j < frames; j++)
            {
                if (a[j][i] == c[c.size() - 1].second)
                {
                    mp.erase(a[j][i]);
                    for (k = i; k < n; k++)
                        a[j][k] = pages[i];
                    mp[pages[i]]++;
                    break;
                }
            }
        }
        for (auto x : mp)
        {
            if (x.first != pages[i])
            {
                mp[x.first]++;
            }
        }
    }
    cout << "Process     ";
    for (i = 0; i < n; i++)
    {
        cout << pages[i] << "  ";
    }
    cout << endl;
    for (i = 0; i < frames; i++)
    {
        cout << "Frame" << i << "      ";
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == -1)
                cout << "-  ";
            else
                cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "Page Fault  ";
    for (i = 0; i < n; i++)
    {
        if (hit[i])
            cout << "   ";
        else
            cout << "F  ";
    }
    cout << "\n\n";
    cout << "Page Fault " << n - hitCount << endl;
    return 0;
}