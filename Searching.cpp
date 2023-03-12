#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int LinearSearch(int arr[],int n,int key){  //O(n)
   for(int i=0;i<n;i++){
      if(arr[i]==key){
         return i;
      }
   }
   return -1;
}

int BinarySearch(int arr[],int n, int key){    //O(log n)
   int upper = n,lower = 0;
   
   while(upper>=lower){
      int mid = (upper+lower)/2;
      if(key>arr[mid]){
         lower = mid+1;
      }
      
      else if(key<arr[mid]){
         upper = mid-1;
      }
      else if(arr[mid]==key){ 
         return mid;
      }
   }
   return -1;
   
}



int main(){

   int n;
   cin>>n;

   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }

   int key;
   
   cout<<"enter the key:";
   cin>>key;

   cout<<BinarySearch(arr,n,key);
   return 0;
}


//*4