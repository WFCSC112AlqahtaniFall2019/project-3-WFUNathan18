#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);
void bubbleSort(int *a, int n);

/*int argc, char* argv[]*/
int main() {
    // get input: first is random seed, second is vector length
    int seed, length;
    //seed = atoi(argv[1]);
    //length = atoi(argv[2]);
    cin >> seed;
    cin >> length;
    srand(seed);

    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace

    // define an integer pointer dynamically allocate an array of integers
    /* your code here */
    int* arr = new int[length];

    // initialize and print input
    cout << "Unsorted (Vectors with mergeSort()):" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // copy the random list of integers from vector to array
    /* your code here */
    for (int i = 0; i < length; i++) {
        *(arr + i) = v.at(i);
    }

    // Print unsorted array
    cout << "Unsorted (Array with bubbleSort()):" << endl;
    for(int i = 0; i < (length); i++) {
        cout << *(arr + i) << '\t';
    }
    cout << endl;

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    /* your code here */
    bubbleSort(arr, length);
    clock_t end_bubbleSort = clock();


    // print sorted vector after mergeSort
    cout << "Sorted (Vectors with mergeSort()):" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort
    /* your code here */
    cout << "Sorted (Array with bubbleSort())" << endl;
    for(int i = 0; i < (length); i++) {
        cout << *(arr + i) << '\t';
    }

    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << elapsed_mergeSort << " " << elapsed_bubbleSort << endl;

    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {
    /* your code here */
    int temp = *a;
    *a = *b;
    *b = *a;
}

// BubbleSort function
void bubbleSort(int *a, int n) {
    /* your code here */
    int j = 1;
    while (n > (j - 1)) {
        for (int i = 1; i < (n - j); i++) {
            if (*(a + i) < *(a + (i - 1))) { // If the currently selected element is lesser in value than the element before it...
                swap(*(a + i), *(a + (i - 1))); // Swap the currently selected element with the one before it
            }
        }
        j++;
    }
}