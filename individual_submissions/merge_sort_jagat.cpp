#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 50000;
int data[MAX_SIZE];
int tempData[MAX_SIZE];

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

void mergeSort(int data[], int size)
{
    for (int width = 1; width < size; width = width * 2)
    {
        for (int left = 0; left < size - 1;
             left = left + 2 * width)
        {
            int middle = left + width - 1;
            int right = left + 2 * width - 1;

            if (middle >= size - 1)
                continue;

            if (right >= size)
                right = size - 1;

            int i = left;
            int j = middle + 1;
            int k = left;

            while (i <= middle && j <= right)
            {
                if (data[i] <= data[j])
                    tempData[k++] = data[i++];
                else
                    tempData[k++] = data[j++];
            }

            while (i <= middle)
                tempData[k++] = data[i++];

            while (j <= right)
                tempData[k++] = data[j++];

            for (i = left; i <= right; i++)
                data[i] = tempData[i];
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
    mergeSort(data, size);
    time = (double)(std::clock() - start)
           * 1000 / CLOCKS_PER_SEC;

    std::cout << "After Sorting: ";
    displayRecords(data, size);

    std::cout << "Merge Sort Execution Time: "
              << time << " ms\n";

    return 0;
}

