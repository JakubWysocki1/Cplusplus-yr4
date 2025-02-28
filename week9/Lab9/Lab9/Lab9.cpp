#include <iostream>
#include <vector>
#include <random>
using namespace std;

/* References 
https://www.geeksforgeeks.org/cpp-program-for-quicksort/
https://www.geeksforgeeks.org/merge-sort/
*/

#ifdef _WIN32
#include <Windows.h>


double get_wall_time() {
    LARGE_INTEGER time, freq;
    if (!QueryPerformanceFrequency(&freq)) {
        //  Handle error
        return 0;
    }
    if (!QueryPerformanceCounter(&time)) {
        //  Handle error
        return 0;
    }
    return (double)time.QuadPart / freq.QuadPart;
}
double get_cpu_time() {
    FILETIME a, b, c, d;
    if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0) {
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
            (double)(d.dwLowDateTime |
                ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }
    else {
        //  Handle error
        return 0;
    }
}
#endif

void merge(vector<int>& vec, int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    vector<int> leftArray(subArrayOne);
    vector<int> rightArray(subArrayTwo);

    for (int i = 0; i < subArrayOne; i++) {
        leftArray[i] = vec[left + i];
    }

    for (int j = 0; j < subArrayTwo; j++) {
        rightArray[j] = vec[mid + 1 + j];
    }

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            vec[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            vec[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        vec[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        vec[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(vector<int>& vec, int const begin, int const end) {

    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;
    mergeSort(vec, begin, mid);
    mergeSort(vec, mid + 1, end);
    merge(vec, begin, mid, end);

    
}

void printVector(vector<int> const& vec) {
    for (int const& elem : vec) {
        cout << elem << " ";
    }
}
 
int partition(vector<int>& vec, int start, int end)
{
    int pivot = vec[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (vec[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(vec[pivotIndex], vec[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (vec[i] <= pivot) {
            i++;
        }

        while (vec[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(vec[i++], vec[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int>& vec, int start, int end)
{
    if (start >= end)
        return;

    int p = partition(vec, start, end);

    quickSort(vec, start, p - 1);

    quickSort(vec, p + 1, end);
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 1000);

    vector<int> vec1,vec2,vec3,vec4,vec5;

    for (int i = 0; i < 10; i++) {
        vec1.push_back(distribution(gen));
    }
    for (int i = 0; i < 100; i++) {
        vec2.push_back(distribution(gen));
    }
    for (int i = 0; i < 1000; i++) {
        vec3.push_back(distribution(gen));
    }
    for (int i = 0; i < 10000; i++) {
        vec4.push_back(distribution(gen));
    }
    for (int i = 0; i < 100000; i++) {
        vec5.push_back(distribution(gen));
    }


    double start_time, elapsed_time;

    start_time = get_cpu_time();
    mergeSort(vec1, 0, vec1.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Merge sort cpu time for vecor of size " << vec1.size() << ": " << elapsed_time << "\n";
  
    start_time = get_cpu_time();
    mergeSort(vec2, 0, vec2.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Merge sort cpu time for vecor of size " << vec2.size() << ": " << elapsed_time << "\n";

    start_time = get_cpu_time();
    mergeSort(vec3, 0, vec3.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Merge sort cpu time for vecor of size " << vec3.size() << ": " << elapsed_time << "\n";

    start_time = get_cpu_time();
    mergeSort(vec4, 0, vec4.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Merge sort cpu time for vecor of size " << vec4.size() << ": " << elapsed_time << "\n";

    start_time = get_cpu_time();
    mergeSort(vec5, 0, vec5.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Merge sort cpu time for vecor of size " << vec5.size() << ": " << elapsed_time << "\n";

    cout << endl;

    

    // Sort vec1
    start_time = get_cpu_time();
    quickSort(vec1, 0, vec1.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Quick sort cpu time for vecor of size " << vec1.size() << ": " << elapsed_time << "\n";

    // Sort vec2
    start_time = get_cpu_time();
    quickSort(vec2, 0, vec2.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Quick sort cpu time for vecor of size " << vec2.size() << ": " << elapsed_time << "\n";

    // Sort vec3
    start_time = get_cpu_time();
    quickSort(vec3, 0, vec3.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Quick sort cpu time for vecor of size " << vec3.size() << ": " << elapsed_time << "\n";

    // Sort vec4
    start_time = get_cpu_time();
    quickSort(vec4, 0, vec4.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Quick sort cpu time for vecor of size " << vec4.size() << ": " << elapsed_time << "\n";

    // Sort vec5
    start_time = get_cpu_time();
    quickSort(vec5, 0, vec5.size() - 1);
    elapsed_time = get_cpu_time() - start_time;
    cout << "Quick sort cpu time for vecor of size " << vec5.size() << ": " << elapsed_time << "\n";

    return 0;
}
