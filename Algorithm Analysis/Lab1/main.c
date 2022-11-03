//
//  main.c
//  MaximumSubArray
//
//  Created by Asude Merve Ekiz on 3.11.2022.
//

#include <stdio.h>
#include<stdlib.h>
int * maxSubArrayByBruteForce(int n,int* array);

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
