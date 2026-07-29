Run time measurement : #include <chrono>
using namespace std::chrono;

// Starting the timer before the search
auto startTime = high_resolution_clock::now();

// Running the interpolation search
int foundPos = interpolationSearch(arr, n, target, steps);

// Stopping the timer after search completes
auto endTime = high_resolution_clock::now();

// Getting the time difference and converting to milliseconds
auto duration = duration_cast<microseconds>(endTime - startTime);
double timeMs = duration.count() / 1000.0;

// Displaying the results
cout << "Time taken: " << timeMs << " ms" << endl;
cout << "Steps performed: " << steps << endl;
