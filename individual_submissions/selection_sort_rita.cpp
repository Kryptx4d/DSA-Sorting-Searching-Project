#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

long long counter = 0;

// true = show before sorting, passes and after sorting(full output)
// false = show only testing result
bool showDetails = true;

// generates the random numbers
void generateRecords(int data[], int size)
{
    srand(time(NULL));
   
    //stores random numbers in array

    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % 100;
    }
}

// Display the array or record
void displayRecords(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";

//print 10 numbers in one line
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

// Selection Sort function
void selectionSort(int data[], int size)
{
    int temp;
    int max_index;
    int pass = 1;

// Repeat until the whole array is sorted
    for (int rightmost = size - 1; rightmost > 0; rightmost--)
    {
        max_index = 0;

        // Find the largest value
        for (int current = 1; current <= rightmost; current++)
        {
            counter++;

            if (data[current] > data[max_index])
            {
                max_index = current;
            }
        }

        // Swap if needed
        if (max_index != rightmost)
        {
            temp = data[max_index];
            data[max_index] = data[rightmost];
            data[rightmost] = temp;

            counter++;
        }

        // Show passes only when showDetails is true
        if (showDetails)
        {
            cout << "\nPass " << pass << endl;
            cout << "Operation Counter : " << counter << endl;

            displayRecords(data, size);
        }
 // Go to the next pass
        pass++;
    }
}
 
int main()
{
    // Change this value to test execution time: 100, 500, 1000, 5000, 10000, 50000 and more if project ask
    const int SIZE = 50000;

    int data[SIZE];
 // Generate records
    generateRecords(data, SIZE);

   // Show records before sorting
    if (showDetails)
    {
        cout << "Before Sorting\n\n";
        displayRecords(data, SIZE);
    }

    // Start measuring execution time
    auto start = high_resolution_clock::now();

 // Sort the records
    selectionSort(data, SIZE);

     // Stop measuring execution time
    auto stop = high_resolution_clock::now();

     // Show records after sorting
    if (showDetails)
    {
        cout << "\nAfter Sorting\n\n";
        displayRecords(data, SIZE);
    }

        // Calculate execution time
    auto duration = duration_cast<milliseconds>(stop - start);


     // Display final result
    cout << "\nInput Size       : " << SIZE << endl;
    cout << "Execution Time   : " << duration.count() << " ms" << endl;
    cout << "Total Operations : " << counter << endl;


    // End of program
    return 0;
}
