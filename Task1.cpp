#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> V = {1, 0, 2, 0, 3, 4, 0};

    auto it = find(V.begin(), V.end(), 0);

    if (it != V.end())
    {
        auto secondZero = find(it + 1, V.end(), 0);

        if (secondZero != V.end())
        {
            V.erase(secondZero);

            for (int num : V)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}