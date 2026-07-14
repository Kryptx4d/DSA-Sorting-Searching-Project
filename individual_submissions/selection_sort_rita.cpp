#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

long long counter = 0;

// Generate random records
void generateRecords(int data[], int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % 100;   // numbers from 0 to 99
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
    int pass = 1;

    for (rightmost = size - 1; rightmost > 0; rightmost--)
    {
        max_index = 0;

        for (current = 1; current <= rightmost; current++)
        {
            counter++;   // Count each comparison

            if (data[current] > data[max_index])
                max_index = current;
        }

        if (data[max_index] > data[rightmost])
        {
            temp = data[max_index];
            data[max_index] = data[rightmost];
            data[rightmost] = temp;

            counter++;   // Count each swap
        }

        cout << "Pass " << pass
             << " | Counter = " << counter << endl;

        pass++;
    }
}

int main()
{
    const int SIZE = 100;   // changing 100, 500 and more...

    int data[SIZE];

    generateRecords(data, SIZE);

    cout << "========== BEFORE SORTING ==========\n\n";
    displayRecords(data, SIZE);

    auto start = high_resolution_clock::now();

    selectionSort(data, SIZE);

    auto stop = high_resolution_clock::now();

    cout << "\n========== AFTER SORTING ==========\n\n";
    displayRecords(data, SIZE);

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nSelection Sort Execution Time: "
         << duration.count() << " ms" << endl;

    cout << "Total Operations = " << counter << endl;

    return 0;
}

  
   

      

  












INTRODUCTION
Selection sort is the process of sorting algorithm that arranges data in ascending order. First, it finds the largest element and puts it into the last place. And it keeps doing this process until all the elements are sorted. In this process, random records are sorted using selection sort, and the execution time and the number of operations are measured using the sorting algorithm.

OBJECTIVES
To apply selection sort in C++
To arrange random records in ascending order
To measure the sorting operations
To see the performance using a random input size
To measure the execution time


ALGORITHM
First, it generates the random records
Show the records before sorting elements 
Suppose the unsorted array is the largest element
Swap those elements with the last element of the unsorted portion 
Increase the operation counter during the comparison and swap 
Shows the counter after every pass
Keeps this process until all elements are sorted 
Finally, shows the execution time, sorted record, and total operations


Program Description
At program beginning, random number generate & inserted into the array and before sorting sort the array display by records, and after every pass the unsorted part reduce by 1, selectionSort () find largest element in an unsorted array and swap it with last element of unsorted array and after every pass sorted position is occupied by sorted element, sorting complete after every pass complete sort of array.. Time measures with the help of chrono library and compare and swap operation is measured using the counter variable which count number of operation. And finally it shows total operations performed and after pass number display counter..


USED FUNCTIONS
generateRecords()
This function generates the random numbers and puts them into the array.
displayRecords()
this function shows the before and after sorting array.
Selectionsort()
This function sorts the array using the selection sort algorithm and also measures the number of operations.
High resolution clock::now()
This function takes the time of begging and the end of the execution time.
Duration case <milliseconds>()
This function is used to measure execution time 

TIME COMPLEXITY

case	Time complexity
best case	o(n2)
Average case	o(n2)
Worst case	o(n2)

Selection sort compares each elements with every other remaining un-sorted element. Even though array is already sorted compare time would almost be same. That's why best,average and worst all time complexity would be o(n2).

७. Space Complexity
O(1)
व्याख्या (Explanation)
Selection Sort ले swap र operation count गर्न केही अतिरिक्त variables मात्र प्रयोग गर्छ। Input size बढे पनि अतिरिक्त memory को आवश्यकता बढ्दैन।

SPACE COMPLEXITY
O(1)
Selection sort only used the variables to sort and the operation count.  Even though the input size increases, it does not require memory.


ADVANTAGES
Easy to understand
Easy to make a program
Does not require extra memory
Useful for a small dataset



DISADVANTAGES
Slow work for large datasets
It performs many comparisons
Not suitable for large datasets


TESTING
Remaining 

OUTPUT
Before sorting records
After sorting records
After every pass Operation counter
Total operation counter
Execution time (milliseconds)

 
Selection sort is the process of sorting algorithm, and it is easy to understand. it searches the unsorted largest element and puts it into its right place. Operation Counter shows the ongoing operations as it sorting the data while the execution time tells us the time it took to sort the data. As a result, Selection Sort could be useful for small dataset but as the size of the dataset increases it’s futility increases too because of the time complexity O(n2)




