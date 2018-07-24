#include <algorithm>

void BubbleSort(int arr[], int len);

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
