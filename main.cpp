#include <iostream>

using namespace std;

int linearSearch(int aArray[], int size, int val); // returns the position of int through linearSearch. Returns -1 if not found
int binarySearch(int aArray[], int size, int val); // returns the position of int through binarySearch. Returns -1 if not found
void bubbleSort(int aArray[], int size); // sorts array with bubbleSort
void selectionSort(int aArray[], int size); // sorts array with selectionSort
void insertionSort(int aArray[], int size); // sorts array with insertionSort
void insertionSortBetter (int aArray[], int size); // sorts array with better insertionSort
int main (void)
{
    int unsorted[100] =
            {
                    85, 64, 16, 18, 1, 88, 48, 63, 54, 83, 79, 50, 0, 55,
                    17, 99, 69, 53, 65, 22, 93, 86, 9, 37, 56, 23, 21, 52,
                    78, 29, 14, 58, 35, 47, 68, 87, 3, 34, 5, 74, 4, 45,
                    41, 49, 67, 89, 92, 60, 72, 20, 8, 15, 42, 71, 31, 36,
                    90, 84,70, 51, 28, 32, 81, 10, 82, 40, 57, 24, 25, 91,
                    44, 66, 30, 62, 94, 6, 7, 46, 43,38, 75, 11, 39, 80,
                    98, 27, 12, 76, 96, 2, 77, 19, 26, 59, 33, 73, 13,
                    61, 95, 97
            };

    for (int i:unsorted)
    {
        cout << i << ' ';
    }

    cout << endl;
    cout << endl;

    // bubbleSort(unsorted, 100);
    // selectionSort (unsorted, 100);
    // insertionSort (unsorted, 100);
    insertionSortBetter (unsorted, 100);

    for (int i : unsorted)
    {
        cout << i << ' ';
    }

    cout << endl;

    // int searchVal = linearSearch (unsorted, 100, 24);
    int searchVal = binarySearch (unsorted, 100, 24);

    cout << searchVal << endl;

    return 0;

}


int linearSearch(int aArray[], int size, int val) // returns the position of int through linearSearch. Returns -1 if not found
{
    int posFound = -1;
    for (int i = 0; i < size; ++i)
    {
        if (aArray[i] == val)
        {
            posFound = i;
            break;
        }
    }
    return posFound;
}

int binarySearch(int aArray[], int size, int val) // returns the position of int through binarySearch. Returns -1 if not found
{
    int min = 0;
    int max = size - 1;
    bool found = false;

    while (!found && max >= min)
    {
        int mid = (max + min) / 2;

        if (aArray[mid] == val)
        {
            return mid;
        }
        else if (aArray[mid] > val)
        {
            max = mid - 1;
            mid = (max + min) / 2;
        }
        else
        {
            min = mid + 1;
            mid = (max + min) / 2;
        }
    }
    return -1;
}

void bubbleSort(int aArray[], int size) // sorts array with bubbleSort
{
    int temp;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (aArray[j] > aArray[j+1])
            {
                temp = aArray[j];
                aArray[j] = aArray[j + 1];
                aArray[j + 1] = temp;

                // std::swapArray(aArray[j], array[j + 1];
            }
        }
    }

}

void selectionSort(int aArray[], int size) // sorts array with selectionSort
{
    int currentMin = 0;
    int temp;

    for (int i = 0; i < size - 1; ++ i)
    {
        currentMin = i;

        for (int j = i + 1; j < size; ++j)
        {
            if (aArray[j] < aArray[currentMin])
            {
                currentMin = j;
            }
        }

        if (currentMin != i)
        {
            temp = aArray[currentMin];
            aArray[currentMin] = aArray[i];
            aArray[i] = temp;
        }
    }
}

void insertionSort(int aArray[], int size) // sorts array with insertionSort
{
    int temp;

    for (int i = 1; i < size; ++i)
    {
        int j = i;
        while (j > 0 && aArray[j - 1] > aArray[j])
        {
            temp = aArray[j];
            aArray[j] = aArray[j - 1];
            aArray[j - 1] = temp;
            --j;
        }
    }
}

void insertionSortBetter(int aArray[], int size)
{
    int toBeSorted, j;
    for (int i = 1; i < size; ++i)
    {
        toBeSorted = aArray[i];
        j = i - 1;
        while (j >= 0 && aArray[j] > toBeSorted)
        {
            aArray[j + 1] = aArray [j];
            --j;
        }
        aArray[j + 1] = toBeSorted;
    }
}