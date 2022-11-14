
//  main.c
//  MaximumSubArray
//  Created by Asude Merve Ekiz on 3.11.2022.



#include <stdio.h>
#include<stdlib.h>
int * maxSubArrayByBruteForce(int n,int* array);
int * maxSumSubArray(int ar[], int low, int high);
int maximum(int a, int b, int c);
int maxCrossingSubarray(int ar[], int low, int mid, int high);
int startIndex=-1;
int endIndex=-1;
int start=0;
int end=0;


int main(int argc, const char * argv[]) {
    int n,i,options=-1;
    int *array;
    int *maxSubArray;
    int *backupArray;
    int maxValue=0;
    printf("\n");
    printf("ALGORITHM ANALYSIS ASSIGNMENT2 \n");
    printf("20011623 - Asude Merve Ekiz \n");
    
    printf("Enter the n number:\n");
    scanf("%d",&n);
    
    array=(int*)calloc(n,sizeof(int)); //array allocated.
    if (array!=NULL) {
        //printf("Array allocated.\n");
    }
    maxSubArray=(int*)calloc(n,sizeof(int)); //maxSubArray allocated.
    if (maxSubArray!=NULL) {
        //printf("maxSubArray allocated.\n");
    }
    backupArray=(int*)calloc(n,sizeof(int)); //maxSubArray allocated.
    if (backupArray!=NULL) {
        //printf("backupArray allocated.\n");
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
    
    printf("\nWhich way do you want to see the maxSubArray and maxSum?\n Press 1 for Brute Force Solution \n Press 2 for Divide and Conquer Based Solution\n Press 3 to exit\n");
    while (options!=0) {
        printf("\nOption:\n");
        scanf("%d",&options);
        if (options==1) {
            printf("This is the Brute Force Solution.\n");
            maxSubArray = maxSubArrayByBruteForce(n, array);
            for (i=start; i<=end; i++) {
                printf("%d ",array[i]);
            }
        }
        
        else if(options==2){
            
            printf("This is the Divide and Conquer Based Solution.\n");
            backupArray=maxSumSubArray(array, 0, n-1) ;
           
            printf("Found Maximum Subarray between {%d} and {%d}\n", startIndex, endIndex);
            for (i=startIndex; i<=endIndex; i++) {
                maxValue+=array[i];
            }
            printf("The max sum is : %d\n",maxValue);
            for (i=startIndex; i<=endIndex; i++) {
                printf("%d ",array[i]);
            }
            
        }
    }
    
  
    return 0;
}


int *   maxSubArrayByBruteForce(int n,int* array) {
      int *subArray;
      int maximumSubArraySum = -255;
      
      
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
    if (a>=b && a>=c){
        return a;
    }
    
  else if (b>=a && b>=c)
    return b;
  return c;
}


int maxCrossingSubarray(int ar[], int low, int mid, int high){
 
  int left_sum = -255;
  int sum = 0;
  int i;

  for (i=mid; i>=low; i--){
    sum = sum+ar[i];
      if (sum>left_sum){
          left_sum = sum;
          startIndex=i;
      }
  }

  int right_sum = -255;
  sum = 0;

  for (i=mid+1; i<=high; i++)
  {
    sum=sum+ar[i];
      if (sum>right_sum){
          right_sum = sum;
          endIndex=i;
      }
  }
  
  return (left_sum+right_sum);
}


int * maxSumSubArray(int ar[], int low, int high)
{
  if (high == low) // only one element in an array
  {
      startIndex=low;
      endIndex=high;
      return ar[high];
  }

  int mid = (high+low)/2;
    
  int maximumSumLeftSubArray = maxSumSubArray(ar, low, mid);  // maximum sum in the left subarray
  int maximumSumRightSubArray = maxSumSubArray(ar, mid+1, high);  // maximum sum in the right subarray
  int maximumSumCrossingSubArray = maxCrossingSubarray(ar, low, mid, high); // maximum sum in the array include the middle element
    
   int maxValue= maximum(maximumSumLeftSubArray, maximumSumRightSubArray, maximumSumCrossingSubArray);
  
  
    if(maxValue==maximumSumLeftSubArray){
        return maxSumSubArray(ar, low, mid);
    }
    else if(maxValue==maximumSumRightSubArray){
        return maxSumSubArray(ar, mid+1, high);
    }
    else{
        return maxCrossingSubarray(ar, low, mid, high);
    }
    
}



