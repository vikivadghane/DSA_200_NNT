#include <stdio.h>
void create_array(int arr[], int n) {
   int i;
   printf("\nEnter %d elements : \n", n);
   for (i = 0; i < n; i++) {
       printf("Enter element %d: ", i + 1);
       scanf("%d", &arr[i]);
   }
}
void display_array(int arr[], int n) {
   int i;
   printf("\n Created Array: ");
   for (i = 0; i < n; i++) {
       printf("\t%d", arr[i]);
   }
   printf("\n");
}
int linear_search(int arr[], int n, int key) {
   int i;
   for (i = 0; i < n; i++) {
       if (arr[i] == key) {
           return i;
       }
   }
   return -1;
}
int binary_search(int arr[], int n, int key) {
   int low = 0;
   int high = n - 1;


   while (low <= high) {
       int mid = low + (high - low) / 2;


       if (arr[mid] == key) {
           return mid;
       }
       if (arr[mid] < key) {
           low = mid + 1;
       } else {
           high = mid - 1;
       }
   }
   return -1;
}
void display_menu() {
   printf("\n1. Create Array");
   printf("\n2. Display Array");
   printf("\n3. Linear Search");
   printf("\n4. Binary Search");
   printf("\n5. Display Menu");
   printf("\n6. Exit");
}
int main() {
   int arr[100];
   int n = 0;
   int choice;
   int key;
   int result;
   display_menu();
   do {
       printf("\nEnter your choice: ");
       scanf("%d", &choice);
       switch (choice) {
           case 1:
               printf("\nEnter the size of an Array : ");
               scanf("%d", &n);
               create_array(arr, n);
               printf("\nArray created successfully");
               break;
           case 2:
               if (n == 0) {
                   printf("\nArray has not yet been created.");
               } else {
                   display_array(arr, n);
               }
               break;
           case 3:
               if (n == 0) {
                   printf("\nPlease create the array first.");
               } else {
                   printf("\nEnter the value to search: ");
                   scanf("%d", &key);
                   result = linear_search(arr, n, key);
                   if (result != -1) {
                       printf("\nValue %d found at position %d.", key, result + 1);
                   } else {
                       printf("\nValue %d not found in the array.", key);
                   }
               }
               break;
           case 4:
               if (n == 0) {
                   printf("\nPlease create the array first.");
               } else {
                   display_array(arr, n);
                   printf("\nEnter the value to search: ");
                   scanf("%d", &key);
                   result = binary_search(arr, n, key);
                   if (result != -1) {
                       printf("\nElement %d found at position %d.", key, result + 1);
                   } else {
                       printf("\nElement %d not found in the array.", key);
                   }
               }
               break;
           case 5:
               display_menu();
               break;
           case 6:
               printf("\nExit");
               break;
           default:
               printf("\nInvalid choice.");
       }
   } while (choice != 6);
   return 0;
}
