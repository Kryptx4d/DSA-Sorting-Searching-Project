#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 50000;
int data[MAX_SIZE];

void generateRecords(int data[], int size)
{
    for (int i = 0; i < size; i++)
        data[i] = std::rand() % 1000;
}

void displayRecords(const int data[], int size)
{
    int limit = size;

    if (limit > 20)
        limit = 20;

    for (int i = 0; i < limit; i++)
        std::cout << data[i] << " ";

    if (size > 20)
        std::cout << "...";

    std::cout << "\n";
}

void selectionSort(int data[], int size)
{
    for (int rightmost = size - 1; rightmost > 0; rightmost--)
    {
        int maxIndex = 0;

        for (int current = 1; current <= rightmost; current++)
        {
            if (data[current] > data[maxIndex])
                maxIndex = current;
        }

        int temp = data[maxIndex];
        data[maxIndex] = data[rightmost];
        data[rightmost] = temp;
    }
}

int main()
{
    int size;
    std::clock_t start;
    double time;

    std::srand(std::time(NULL));

    std::cout << "Enter number of records (100-50000): ";
    std::cin >> size;

    if (size < 100 || size > MAX_SIZE)
        size = 100;

    generateRecords(data, size);

    std::cout << "\nBefore Sorting: ";
    displayRecords(data, size);

    start = std::clock();
    selectionSort(data, size);
    time = (double)(std::clock() - start)
           * 1000 / CLOCKS_PER_SEC;

    std::cout << "After Sorting: ";
    displayRecords(data, size);

    std::cout << "Selection Sort Execution Time: "
              << time << " ms\n";

    return 0;
}
