#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Client
{
    int year;
    int month;
    int duration;
    int code;
};

bool compareClients(const Client &client1, const Client &client2)
{
    if (client1.duration == client2.duration)
        return client1.code < client2.code;
    return client1.duration > client2.duration;
}

int main()
{
    vector<Client> clients = {
        {2022, 1, 5, 1001},
        {2021, 12, 3, 1002},
        {2022, 3, 2, 1001},
        {2022, 2, 4, 1003},
        {2021, 11, 6, 1002},
        {2021, 12, 7, 1001},
        {2022, 1, 4, 1002},
        {2022, 2, 3, 1001},
        {2022, 3, 5, 1003}};

    map<int, int> totalDurationByCode;

    for (const Client &client : clients)
    {
        int code = client.code;
        int duration = client.duration;
        totalDurationByCode[code] += duration;
        // cout << "Code: " << code << ", Duration: " << duration << endl;
    }

    vector<Client> sortedClients;
    for (const auto &entry : totalDurationByCode)
    {
        int code = entry.first;
        int duration = entry.second;
        sortedClients.push_back({0, 0, duration, code});
    }

    sort(sortedClients.begin(), sortedClients.end(), compareClients);

    for (const Client &client : sortedClients)
    {
        cout << "Total duration: " << client.duration << " hours, Code: " << client.code << endl;
    }

    return 0;
}
