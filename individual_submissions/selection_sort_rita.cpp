#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Generate random records
void generateRecords(int data[], int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % 1000 + 1;
    }
}

// Display records
void displayRecords(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";

        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

// Selection Sort
void selectionSort(int data[], int size)
{
    int temp;
    int max_index;
    int rightmost, current;

    for (rightmost = size - 1; rightmost > 0; rightmost--)
    {
        max_index = 0;

        for (current = 1; current <= rightmost; current++)
        {
            if (data[current] > data[max_index])
                max_index = current;
        }

        if (data[max_index] > data[rightmost])
        {
            temp = data[max_index];
            data[max_index] = data[rightmost];
            data[rightmost] = temp;
        }
    }
}

int main()
{
    const int SIZE = 100;

    int data[SIZE];

    generateRecords(data, SIZE);

    cout << "Before Sorting\n\n";
    displayRecords(data, SIZE);

    auto start = high_resolution_clock::now();

    selectionSort(data, SIZE);

    auto stop = high_resolution_clock::now();

    cout << "\nAfter Sorting\n\n";
    displayRecords(data, SIZE);

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nSelection Sort Execution Time: "
         << duration.count() << " ms" << endl;

    return 0;
}
