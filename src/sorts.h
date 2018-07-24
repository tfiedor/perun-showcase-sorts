void BubbleSort(int arr[], int len);
void InsertSort(int arr[], int len);

/** Inplace sort of the array using the BubbleSort algorithm
 *
 * @param arr: input array
 * @param len: lenght of the input array
 */
void BubbleSort(int *arr, int len) {
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(arr[j + 1] < arr[j]) {
                int swap = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = swap;
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

