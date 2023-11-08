#include <stdio.h>

int BinarySearch(int arr[], int size, int value){
   int left=0, right=size-1, count=0, mid;
   printf("value(%d)=> ", value);
   while(left<=right){
      ++count;
      mid=left+(right-left)/2;
      if(arr[mid]==value){
         printf("count: %d, ok, ", count);
         return mid;
      }else if(arr[mid]<value){
         left=mid+1;
      }else{
         right=mid-1;
      }
   }
   printf("\ncount: %d, fail, ", count);
   return -1;
}

int main() {
   int a[7]={1,2,3,4,5,6,7};
   for(int i=1; i<8; i++)
      printf("position: %d\n", BinarySearch(a, 7, i));
   return 0;
}
 