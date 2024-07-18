#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    
    while (1) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            arr[low] = arr[j];
            arr[j] = pivot;
            return j;
        }
    }
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int a[15000], n, i, ch;
    clock_t start, end;

    while (1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:  
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                quicksort(a, 0, n - 1);
                end = clock();
                printf("\nSorted array is: ");
                for (i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                break;

            case 2:
                return 0;

            default:
                printf("Invalid choice, please try again.");
        }
        getchar(); // To consume the newline character left by scanf
    }
}
