#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 50000;
int data[MAX_SIZE];
int stackData[MAX_SIZE * 2];

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

void quickSort(int data[], int size)
{
    int top = -1;

    stackData[++top] = 0;
    stackData[++top] = size - 1;

    while (top >= 0)
    {
        int high = stackData[top--];
        int low = stackData[top--];
        int pivot = data[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (data[j] <= pivot)
            {
                i++;

                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }

        int temp = data[i + 1];
        data[i + 1] = data[high];
        data[high] = temp;

        int pivotIndex = i + 1;

        if (pivotIndex - 1 > low)
        {
            stackData[++top] = low;
            stackData[++top] = pivotIndex - 1;
        }

        if (pivotIndex + 1 < high)
        {
            stackData[++top] = pivotIndex + 1;
            stackData[++top] = high;
        }
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
    quickSort(data, size);
    time = (double)(std::clock() - start)
           * 1000 / CLOCKS_PER_SEC;

    std::cout << "After Sorting: ";
    displayRecords(data, size);

    std::cout << "Quick Sort Execution Time: "
              << time << " ms\n";

    return 0;
}
