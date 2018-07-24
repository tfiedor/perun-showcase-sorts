#include <algorithm>

void QuickSort(int *data, int count);
int Partition(int* data, int left, int right);
void BubbleSort(int arr[], int len);
void InsertSort(int arr[], int len);
void Swap(int& lhs, int &rhs);

/** Inplace sort of the array using the BubbleSort algorithm
 *
 * @param arr: input array
 * @param len: lenght of the input array
 */
void BubbleSort(int *arr, int len) {
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(arr[j + 1] < arr[j]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

/** Inplace sort of the array using the InsertSort algorithm
 *
 * @param arr: input array
 * @param len: lenght of the input array
 */
void InsertSort(int *arr, int len) {
    for(int i = 1; i < len - 1; i++) {
        int j = i + 1;
        int tmp = arr[j];
        while(j > 0 && tmp > arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tmp;
    }
}

/** Inplace sort of the array using the QuickSort algorithm
 *
 * @param arr: input array
 * @param len: lenght of the input array
 */
void QuickSort(int *data, int count) {
    int startIndex = 0;
    int endIndex = count - 1;
    int top = -1;
    int* stack = new int[count];

    stack[++top] = startIndex;
    stack[++top] = endIndex;

    while (top >= 0)
    {
        endIndex = stack[top--];
        startIndex = stack[top--];

        int p = Partition(data, startIndex, endIndex);

        if (p - 1 > startIndex)
        {
            stack[++top] = startIndex;
            stack[++top] = p - 1;
        }

        if (p + 1 < endIndex)
        {
            stack[++top] = p + 1;
            stack[++top] = endIndex;
        }
    }

    delete[] stack;
}

/** Helper function for swapping two values
 *
 * @param lhs: left operand of swap
 * @param rhs: right operand of swap
 */
void Swap(int& lhs, int &rhs) {
    std::swap(lhs, rhs);
}

/** Helper function for partitioning array for QuickSort
 *
 * @param data: array with values
 * @param left: left index of partition
 * @param right: right index of partition
 */
int Partition(int* data, int left, int right) {
    int pivot_idx = (left + right) / 2;
    Swap(data[pivot_idx], data[right]);

    int i = (left - 1);

    for (int j = left; j <= right - 1; ++j)
    {
        if (data[j] <= data[right])
        {
            ++i;
            Swap(data[i], data[j]);
        }
    }

    Swap(data[i + 1], data[right]);

    return (i + 1);
}
