#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 50000;
int data[MAX_SIZE], tempData[MAX_SIZE], stackData[MAX_SIZE * 2];
int randomSeed;

void generateRecords(int data[], int size)
{
    std::srand(randomSeed);
    for (int i = 0; i < size; i++)
        data[i] = std::rand() % 1000;
}

void displayRecords(const int data[], int size)
{
    int limit = size;
    if (limit > 20) limit = 20;

    for (int i = 0; i < limit; i++)
        std::cout << data[i] << " ";

    if (size > 20) std::cout << "...";
    std::cout << "\n";
}

void selectionSort(int data[], int size)
{
    for (int rightmost = size - 1; rightmost > 0; rightmost--)
    {
        int maxIndex = 0;

        for (int current = 1; current <= rightmost; current++)
            if (data[current] > data[maxIndex])
                maxIndex = current;

        int temp = data[maxIndex];
        data[maxIndex] = data[rightmost];
        data[rightmost] = temp;
    }
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

void mergeSort(int data[], int size)
{
    for (int width = 1; width < size; width = width * 2)
    {
        for (int left = 0; left < size - 1; left = left + 2 * width)
        {
            int middle = left + width - 1;
            int right = left + 2 * width - 1;

            if (middle >= size - 1) continue;
            if (right >= size) right = size - 1;

            int i = left, j = middle + 1, k = left;

            while (i <= middle && j <= right)
            {
                if (data[i] <= data[j]) tempData[k++] = data[i++];
                else tempData[k++] = data[j++];
            }

            while (i <= middle) tempData[k++] = data[i++];
            while (j <= right) tempData[k++] = data[j++];

            for (i = left; i <= right; i++)
                data[i] = tempData[i];
        }
    }
}

int binarySearch(const int data[], int size, int target)
{
    int first = 0, last = size - 1;

    while (first <= last)
    {
        int middle = (first + last) / 2;

        if (target == data[middle]) return middle;
        if (target < data[middle]) last = middle - 1;
        else first = middle + 1;
    }

    return -1;
}

int interpolationSearch(const int data[], int size, int target)
{
    int first = 0, last = size - 1;

    while (first <= last &&
           target >= data[first] && target <= data[last])
    {
        if (data[first] == data[last])
        {
            if (data[first] == target) return first;
            return -1;
        }

        int position = first +
            (target - data[first]) * (last - first) /
            (data[last] - data[first]);

        if (data[position] == target) return position;
        if (data[position] < target) first = position + 1;
        else last = position - 1;
    }

    return -1;
}

int main()
{
    int size;
    char choice;
    randomSeed = std::time(NULL);

    std::cout << "Enter number of records (100-50000): ";
    std::cin >> size;
    if (size < 100 || size > MAX_SIZE) size = 100;

    do
    {
        std::cout << "\nA. Display Records\n";
        std::cout << "B. Sort Records\n";
        std::cout << "C. Search for Number\n";
        std::cout << "D. Exit\nEnter choice: ";
        std::cin >> choice;

        if (choice == 'A')
        {
            generateRecords(data, size);
            displayRecords(data, size);
        }
        else if (choice == 'B')
        {
            int sortChoice;
            generateRecords(data, size);

            std::cout << "1. Selection Sort\n";
            std::cout << "2. Quick Sort\n";
            std::cout << "3. Merge Sort\nEnter choice: ";
            std::cin >> sortChoice;

            std::clock_t start = std::clock();

            if (sortChoice == 1)
            {
                std::cout << "Selection Sort\n";
                selectionSort(data, size);
            }
            else if (sortChoice == 2)
            {
                std::cout << "Quick Sort\n";
                quickSort(data, size);
            }
            else if (sortChoice == 3)
            {
                std::cout << "Merge Sort\n";
                mergeSort(data, size);
            }
            else
            {
                std::cout << "Invalid choice.\n";
                continue;
            }

            double time = (double)(std::clock() - start)
                          * 1000 / CLOCKS_PER_SEC;

            std::cout << "Sorted Records: ";
            displayRecords(data, size);
            std::cout << "Execution Time: " << time << " ms\n";
        }
        else if (choice == 'C')
        {
            int searchChoice, target, position;
            generateRecords(data, size);
            quickSort(data, size);

            std::cout << "1. Binary Search\n";
            std::cout << "2. Interpolation Search\nEnter choice: ";
            std::cin >> searchChoice;
            std::cout << "Enter target: ";
            std::cin >> target;

            std::clock_t start = std::clock();

            if (searchChoice == 1)
            {
                std::cout << "Binary Search\n";
                position = binarySearch(data, size, target);
            }
            else if (searchChoice == 2)
            {
                std::cout << "Interpolation Search\n";
                position = interpolationSearch(data, size, target);
            }
            else
            {
                std::cout << "Invalid choice.\n";
                continue;
            }

            double time = (double)(std::clock() - start)
                          * 1000 / CLOCKS_PER_SEC;

            if (position == -1) std::cout << "Number not found.\n";
            else std::cout << "Number found at index " << position << ".\n";

            std::cout << "Execution Time: " << time << " ms\n";
        }
        else if (choice == 'D')
            std::cout << "Application Exited.\n";
        else
            std::cout << "Invalid choice.\n";

    } while (choice != 'D');

    return 0;
}
