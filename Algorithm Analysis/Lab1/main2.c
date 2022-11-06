
//
//  main.c
//  MaximumSubArray
//  Created by Asude Merve Ekiz on 3.11.2022.
#include <stdio.h>
#include<stdlib.h>
int startIndex=-1;
int endIndex=-1;

int * maxSubArrayByBruteForce(int n,int* array);
//int maxOfTwo(int a, int b);
//int maxOfThree(int a, int b, int c) ;
//int maxCrossingSum(int arr[], int l, int m, int h);
//int maxSubArraySum(int arr[], int l, int h);
int maxSumSubArray(int ar[], int low, int high);
int maximum(int a, int b, int c);
int maxCrossingSubarray(int ar[], int low, int mid, int high);


int main(int argc, const char * argv[]) {
    int n,i,options=0;
    int *array;
    int *maxSubArray;
    printf("Enter the n number:\n");
    scanf("%d",&n);
    
    array=(int*)calloc(n,sizeof(int)); //array allocated.
    if (array!=NULL) {
        printf("Array allocated.\n");
    }
    maxSubArray=(int*)calloc(n,sizeof(int)); //maxSubArray allocated.
    if (maxSubArray!=NULL) {
        printf("maxSubArray allocated.\n");
    }
    
    for (i=0; i<n; i++) {
        printf("%d.value:",i+1 );
        scanf("%d", &array[i]);
    }
    printf("\n");
    printf("Your array is:\n");//to see the array clearly
    for (i=0; i<n; i++) {
        printf("%d ",array[i] );
    }
    printf("\n\n");
    
    printf("Which way do you want to see the maxSubArray and maxSum?\n Press 1 for Brute Force Solution \n Press 2 for Divide and Conquer Based Solution\n");
    scanf("%d",&options);
    if (options==1) {
        printf("This is the Brute Force Solution.\n");
        maxSubArray = maxSubArrayByBruteForce(n, array);
        for (i=0; i<n; i++) {
            printf("%d ",maxSubArray[i]);
        }
    }
    else if(options==2){
        printf("This is the Divide and Conquer Based Solution.\n");
        int max_sum =maxSumSubArray(array, 0, n-1) ;
        printf("Maximum contiguous sum is %d\n", max_sum);
       
        
    }
  
    return 0;
}


int *   maxSubArrayByBruteForce(int n,int* array) {
      int *subArray;
      int maximumSubArraySum = -255;
      int start = 0, end=0;
      
      int i,j ;//i left,j right
      subArray=(int*)calloc(n,sizeof(int));
   
      for ( i = 0; i < n; i++) {
          int sum = array[i];
          for (j = i+1; j < n; j++) {
              sum += array[j];
   
              if (sum > maximumSubArraySum) {
                  maximumSubArraySum = sum;
                  start = i;
                  end = j;
              }
          }
      }
    
      printf("Found Maximum Subarray between {%d} and {%d}\n", start, end);
        for (i=start; i<=end; i++) {
            subArray[i]=array[i];
        }
       printf("The max sum is : %d\n",maximumSubArraySum);
       return subArray;
  }


int maximum(int a, int b, int c)
{
  if (a>=b && a>=c)
    return a;
  else if (b>=a && b>=c)
    return b;
  return c;
}


int maxCrossingSubarray(int ar[], int low, int mid, int high){
 
  int left_sum = -255;
  int sum = 0;
  int i;


  /*
    iterating from middle
    element to the lowest element
    to find the maximum sum of the left
    subarray containing the middle
    element also.
  */
    
  for (i=mid; i>=low; i--){
    sum = sum+ar[i];
    if (sum>left_sum)
      left_sum = sum;
      //startIndex=i;
  }

  int right_sum = -255;
  sum = 0;

  for (i=mid+1; i<=high; i++)
  {
    sum=sum+ar[i];
    if (sum>right_sum)
      right_sum = sum;
      //endIndex=i;
      
  }
  /*
    returning the maximum sum of the subarray
    containing the middle element.
  */
  return (left_sum+right_sum);
}


// function to calculate the maximum subarray sum
int maxSumSubArray(int ar[], int low, int high)
{
  if (high == low) // only one element in an array
  {
    return ar[high];
  }

  int mid = (high+low)/2;
    
  int maximumSumLeftSubArray = maxSumSubArray(ar, low, mid);  // maximum sum in the left subarray
  int maximumSumRightSubArray = maxSumSubArray(ar, mid+1, high);  // maximum sum in the right subarray
  int maximumSumCrossingSubArray = maxCrossingSubarray(ar, low, mid, high); // maximum sum in the array containing the middle element

  // returning the maximum among the above three numbers
  
  return maximum(maximumSumLeftSubArray, maximumSumRightSubArray, maximumSumCrossingSubArray);
  
    
}
























/*
int maxOfTwo(int a, int b) { //to find maximum of two integers
    return (a > b) ? a : b;
}
int maxOfThree(int a, int b, int c) {//to find maximum of three integers
    return maxOfTwo(maxOfTwo(a, b), c);
}
 
// Find the maximum possible sum in arr[] such that arr[m]
// is part of it

int maxCrossingSum(int arr[], int l, int m, int h){
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = -255;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
    // Include elements on right of mid
    sum = 0;
    int right_sum = -255;
    for (int i = m; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
 
    // Return sum of elements on left and right of mid
    // returning only left_sum + right_sum will fail for
    // [-2, 1]
    return maxOfThree(left_sum + right_sum - arr[m], left_sum, right_sum);
}
 
// Returns sum of maximum sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int l, int h){
      //Invalid Range: low is greater than high
      if (l > h)
          return -255;
    // Base Case: Only one element
    if (l == h)
        return arr[l];
    int m = (l + h) / 2;  // Find middle point
    return maxOfThree(maxSubArraySum(arr, l, m - 1),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}
*/
