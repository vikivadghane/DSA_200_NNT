// tutorial 3 input
#include <stdio.h>

void insert(int arr[], int n)
{
    int i;

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void bubblesort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nBubble Sort : ");
    display(arr, n);
}

void Insertsort(int arr[], int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;
    }

    printf("\nInsertion Sort: ");
    display(arr, n);
}

void Selection(int arr[], int n)
{
    int i, j, temp, min;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("\nSelection Sort: ");
    display(arr, n);
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    int pi;

    if (low < high)
    {
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[100], temp[100];
    int n, choice, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    insert(arr, n);

    for (;;)
    {
        printf("\n\n===== SORTING MENU =====");
        printf("\n1. Bubble Sort");
        printf("\n2. Insertion Sort");
        printf("\n3. Selection Sort");
        printf("\n4. Merge Sort");
        printf("\n5. Quick Sort");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        for (i = 0; i < n; i++)
        {
            temp[i] = arr[i];
        }

        switch (choice)
        {
        case 1:
            bubblesort(temp, n);
            break;

        case 2:
            Insertsort(temp, n);
            break;

        case 3:
            Selection(temp, n);
            break;

        case 4:
            mergeSort(temp, 0, n - 1);
            printf("\nMerge Sort : ");
            display(temp, n);
            break;

        case 5:
            quickSort(temp, 0, n - 1);
            printf("\nQuick Sort : ");
            display(temp, n);
            break;

        case 6:
            printf("\nExiting program...");
            break;

        default:
            printf("\nInvalid choice!");
        }

        if (choice == 6)
        {
            break;
        }
    }

    return 0;
}
