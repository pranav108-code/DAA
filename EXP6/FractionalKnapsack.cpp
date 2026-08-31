// Write a program to solve the Fractional Knapsack problem using the Greedy approach.
// CODE BY ALMALE PRANAV CHANDRASHEKHAR
// ROLL NO. 25/DA/009

#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int profit;
    double ratio;
};

// Compare items according to profit/weight ratio
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weight and profit of each item:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].profit;

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by profit/weight ratio
    sort(items, items + n, compare);

    double totalProfit = 0;

    // Select items greedily
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            // Take the complete item
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            // Take the fraction of the item
            totalProfit += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
