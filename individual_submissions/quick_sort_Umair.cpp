#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void generateRandomData(int data[], int size) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100000;   
    }
}


void displayData(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}


int partitionArray(int data[], int low, int high) {
    int pivot = data[high];  
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++) {
        if (data[j] <= pivot) {
            i++;
          
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    temp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp;

    return i + 1;
}


void quickSort(int data[], int low, int high) {
    if (low < high) {
        int pivotIndex = partitionArray(data, low, high);

        quickSort(data, low, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, high);
    }
}

int main() {
    srand(time(0));

    const int SIZE = 1000;
    int data[SIZE];

    generateRandomData(data, SIZE);

    cout << "Original Data:\n";
    displayData(data, SIZE);

    auto start = high_resolution_clock::now();

    quickSort(data, 0, SIZE - 1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nSorted Data using Quick Sort:\n";
    displayData(data, SIZE);

    cout << "\nQuick Sort Execution Time: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
