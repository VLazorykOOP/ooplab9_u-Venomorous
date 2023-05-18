#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

int main()
{
    string name = "output.txt";
    vector<int> V = {1, 2, 3, 4, 2, 1, 5, 6, 7, 2, 4, 3};

    size_t midpoint = V.size() / 2;

    vector<int> firstHalf(V.begin(), V.begin() + midpoint);
    vector<int> secondHalf(V.begin() + midpoint, V.end());

    sort(firstHalf.begin(), firstHalf.end());
    sort(secondHalf.begin(), secondHalf.end());

    vector<int> commonNumbers;

    // Find the common numbers
    set_intersection(firstHalf.begin(), firstHalf.end(),
                     secondHalf.begin(), secondHalf.end(),
                     back_inserter(commonNumbers));

    ofstream outputFile(name);

    if (!outputFile)
    {
        cerr << "Failed to open the file " << name << " for writing." << endl;
        return 1;
    }

    for (const int &num : commonNumbers)
    {
        outputFile << num << " ";
    }

    outputFile.close();

    cout << "Common numbers written to " << name << " successfully." << endl;

    return 0;
}
