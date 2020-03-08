#include <iostream>
using namespace std;

pair<int, int> LongestConsecutiveSec(int n, int v[100])
{
    int maxi = 1, len = 1, maxIndex = 0;
    for (int i=1; i<n; i++)
    {

        if (v[i] > v[i-1])
            len++;
        else
        {
            if (maxi < len)
            {
                maxi = len;
                maxIndex = i - maxi;
            }
            len = 1;
        }
    }

    if (maxi < len)
    {
        maxi = len;
        maxIndex = n - maxi;
    }

    pair<int, int> pereche;
    pereche.first = maxIndex;
    pereche.second = maxi + maxIndex - 1;
    return pereche;
}
