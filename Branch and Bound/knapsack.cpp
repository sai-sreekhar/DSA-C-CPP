#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int level, profit, weight;
    float bound;
    vector<int> items;
};

bool cmp(Node a, Node b)
{
    return a.bound < b.bound;
}

int bound(Node knapsackNode, int n, int totalCapacity, vector<int> &profitArray, vector<int> &weightArray)
{
    if (knapsackNode.weight >= totalCapacity)
    {
        return 0;
    }

    int profit_bound = knapsackNode.profit;
    int j = knapsackNode.level + 1;
    int tot_weight = knapsackNode.weight;

    while (j < n && tot_weight + weightArray[j] <= totalCapacity)
    {
        tot_weight += weightArray[j];
        profit_bound += profitArray[j];
        j++;
    }

    if (j < n)
    {
        profit_bound += (totalCapacity - tot_weight) * profitArray[j] / weightArray[j];
    }

    return profit_bound;
}

int knapsack(int n, vector<int> &profitArray, vector<int> &weightArray, int totalCapacity, vector<int> &itemsToBeUsed)
{
    vector<Node> q;

    Node knapsackNode, v;
    knapsackNode.level = -1;
    knapsackNode.profit = knapsackNode.weight = 0;
    knapsackNode.bound = bound(knapsackNode, n, totalCapacity, profitArray, weightArray);
    q.push_back(knapsackNode);

    int maxProfit = 0;

    while (!q.empty())
    {
        knapsackNode = q.front();
        q.erase(q.begin());

        if (knapsackNode.level == n - 1)
        {
            continue;
        }

        v.level = knapsackNode.level + 1;
        v.weight = knapsackNode.weight + weightArray[v.level];
        v.profit = knapsackNode.profit + profitArray[v.level];
        v.items = knapsackNode.items;
        v.items.push_back(v.level);

        if (v.weight <= totalCapacity && v.profit > maxProfit)
        {
            maxProfit = v.profit;
            itemsToBeUsed = v.items;
        }

        v.bound = bound(v, n, totalCapacity, profitArray, weightArray);
        if (v.bound > maxProfit)
        {
            q.push_back(v);
        }

        v.weight = knapsackNode.weight;
        v.profit = knapsackNode.profit;
        v.items = knapsackNode.items;
        v.bound = bound(v, n, totalCapacity, profitArray, weightArray);
        if (v.bound > maxProfit)
        {
            q.push_back(v);
        }
    }

    return maxProfit;
}

int main()
{
    int n = 7, totalCapacity = 15;

    vector<int> profitArray{10, 5, 15, 7, 6, 18, 3};
    vector<int> weightArray{2, 3, 5, 7, 1, 4, 1};

    vector<int> itemsToBeUsed;
    int maxProfit = knapsack(n, profitArray, weightArray, totalCapacity, itemsToBeUsed);

    cout << "The maximum profit that can be obtained is: " << maxProfit << endl;
    cout << "Items used in the knapsack: " << endl;
    for (int i = 0; i < itemsToBeUsed.size(); i++)
    {
        cout << itemsToBeUsed[i] << endl;
    }
    cout << endl;

    return 0;
}