// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include<stdio.h>
int main(){
    int n, k;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[100];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search:");
    scanf("%d", &k);
    
    int comparisons = 0;
    int found = 0;
    for(int i = 0; i < n; i++){
        comparisons++;
        if(arr[i] == k){
            found = 1;
            printf("Element %d found at position %d\n", k, i + 1);
            break;
        }
    }
    
    if(!found){
        printf("Element %d not found in the array\n", k);
    }
    
    printf("Number of comparisons made: %d\n", comparisons);
    return 0;
}   