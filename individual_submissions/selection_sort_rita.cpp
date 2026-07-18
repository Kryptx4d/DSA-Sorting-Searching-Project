#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

long long counter = 0;

// Generating  random records
void generateRecords(int data[], int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % 100;
    }
}

// Displaying records
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
    int pass = 1;

    for (rightmost = size - 1; rightmost > 0; rightmost--)
    {
        max_index = 0;

        // Finding the largest element
        for (current = 1; current <= rightmost; current++)
        {
            counter++; // Comparison

            if (data[current] > data[max_index])
            {
                max_index = current;
            }
        }

        // Swaping
        if (max_index != rightmost)
        {
            temp = data[max_index];
            data[max_index] = data[rightmost];
            data[rightmost] = temp;

            counter++; // Swap
        }

        // Show every pass only when input size is 100
        if (size == 100)
        {
            cout << "\nPass " << pass << endl;

            displayRecords(data, size);
        }

        pass++;
    }
}

int main()
{
    const int SIZE = 100;   // Change to 500,1000,5000,10000,50000 to test execution time and total operations

    int data[SIZE];

    generateRecords(data, SIZE);

    // Display before 
    if (SIZE == 100)
    {
        cout << "========== BEFORE SORTING ==========\n\n";
        displayRecords(data, SIZE);
    }

    auto start = high_resolution_clock::now();

    selectionSort(data, SIZE);

    auto stop = high_resolution_clock::now();

    // Display after sorting only for 100 records
    if (SIZE == 100)
    {
        cout << "\n========== AFTER SORTING ==========\n\n";
        displayRecords(data, SIZE);
    }

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\n-----------------------------------" << endl;
    cout << "Input Size      : " << SIZE << endl;
    cout << "Execution Time  : " << duration.count() << " ms" << endl;
    cout << "Total Operations: " << counter << endl;

    return 0;
}
