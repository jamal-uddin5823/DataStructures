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

double sqrt(int n){
   double low = 0, high = n;

   while(high-low>=1e-4){
      double mid = (low+high)/2;

      if(mid*mid==n) return mid;
      else if(mid*mid > n) high = mid;
      else low = mid;
   }
   return high;
}

double mul(double n, int x){
   double ans = 1;
   for (int i = 0; i < x; i++)
   {
      ans*=n;
   }
   return ans;
}

double nthRoot(int n, int x){
   double low = 0,high = n;

   while(high-low>=1e-4){
      double mid = (low+high)/2;

      double val = mul(mid,x);

      if(val==n) return mid;

      else if(val>n) high = mid;
      else low =mid;
   }return high;
}


int main(){

   cout<<nthRoot(32,3)<<'\n';
   return 0;
}


//*4