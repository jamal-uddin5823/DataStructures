#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

//Swapping two numbers
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int arr[],int low,int high, int exp){

    int pivot = (arr[low]/exp)%10;
    int i = low-1, j = high+1;
    while(1){
        i++;
        while((arr[i]/exp)%10 < pivot) i++;
        j--;
        while((arr[j]/exp)%10>pivot) j--;

        if(i>=j) return j;
        swap(&arr[i],&arr[j]);
    }
}

//Quick Sort--------------------------------------------------
void quickSort(int arr[],int low,int high, int exp){
    if(low>=high) return;
    int p =  partition(arr,low,high,exp);
    quickSort(arr,low,p,exp);
    quickSort(arr,p+1,high,exp);
}

//Merge Sort--------------------------------------------------
/* Function to merge the subarrays of A[] */
void merge(int A[],int left,int mid,int right, int exp){
    int i,j;
    int size_left =mid-left+1;
    int size_right =right-mid;
    
//temporary arrays
    int L[size_left],R[size_right]; 

//copy data to temp arrays
    for(i=0;i<size_left;i++){ 
        L[i]=A[left+i];
    }
    for(j=0;j<size_right;j++){
        R[j]=A[mid+1+j];
    }

    i=0;
    j=0;
    int k=left;

    while(i<size_left && j<size_right){
        if((L[i]/exp)%10<=(R[j]/exp)%10){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<size_left){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<size_right){
        A[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int low,int high, int exp){
    if(low>=high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr,low,mid,exp);
    mergeSort(arr,mid+1,high,exp);
    merge(arr,low,mid,high,exp);
}

//Counting Sort--------------------------------------------------
//Function to get the largest element from an array
int getMax(int arr[],int n){
  int max=arr[0];
  for(int i = 1; i < n; i++)
    if(arr[i]>max)
      max=arr[i];
  return max;
}

//Using counting sort to sort the elements in the basis of significant places
void countingSort(int arr[], int n, int exp){
  int output[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}



//Selection Sort-------------------------------------------------
void selectionSort(int arr[],int size,int exp){
    for(int i=0;i<size-1;i++){
        int mn = i;
        for(int j=i+1;j<size;j++){
            if((arr[j]/exp)%10 <= (arr[mn]/exp)%10)
                mn = j;
        }
        swap(&arr[i],&arr[mn]);
    }
}


void radixsortUsingcounting(int arr[], int n) {
    int mx = getMax(arr,n);

    for (int place = 1; mx / place > 0; place *= 10)
        countingSort(arr, n, place);
}

void radixsortUsingquick(int arr[], int n) {
    int mx = getMax(arr,n);

    for (int place = 1; mx / place > 0; place *= 10)
        quickSort(arr, 0,n-1,place);
}

void radixsortUsingmerge(int arr[], int n) {
    int mx = getMax(arr,n);

    for (int place = 1; mx / place > 0; place *= 10)
        mergeSort(arr, 0,n-1,place);
}

void radixsortUsingselection(int arr[], int n) {
    int mx = getMax(arr,n);

    for (int place = 1; mx / place > 0; place *= 10)
        selectionSort(arr,n,place);
}

int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}
void randomArr(int arr[], int n, int low, int high){
    for (int i = 0; i < n; i++)
    {
        arr[i]=random(low,high);
    }
}


int main(){
    int N=10000;
    int arr[N];

    randomArr(arr,N,10000,99999);
    FILE* fp = freopen("in.txt","w",stdout);
    for(int i = 0; i < N; i++){
         cout<<arr[i]<<" ";
    }cout<<'\n';
    fclose(fp);

    FILE* fp2 = freopen("in.txt","r",stdin);
    FILE* fp3 = freopen("out.txt","w",stdout);
    
    int arr2[N];
    for(int i = 0; i < N; i++){
        cin>>arr2[i];
    }
    fclose(fp2);
   
    auto start = chrono::high_resolution_clock::now();
    radixsortUsingcounting(arr2,N);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds >(stop - start);
    cout << "Time taken by radix using counting: "<< duration.count() << " microseconds" << endl;

    for(int i = 0; i < N; i++){
        cout<<arr2[i]<<" ";
    }cout<<'\n';
    
    fp2 = freopen("in.txt","r",stdin);
    
    for(int i = 0; i < N; i++){
        cin>>arr2[i];
    }
    fclose(fp2);

    start = chrono::high_resolution_clock::now();
    radixsortUsingmerge(arr2,N);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds >(stop - start);
    cout << "Time taken by radix using merge: "<< duration.count() << " microseconds" << endl;
    for(int i = 0; i < N; i++){
        cout<<arr2[i]<<" ";
    }cout<<'\n';


    fp2 = freopen("in.txt","r",stdin);
    
    for(int i = 0; i < N; i++){
        cin>>arr2[i];
    }
    fclose(fp2);

    start = chrono::high_resolution_clock::now();
    radixsortUsingquick(arr2,N);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds >(stop - start);
    cout << "Time taken by radix using quick: "<< duration.count() << " microseconds" << endl;
    for(int i = 0; i < N; i++){
        cout<<arr2[i]<<" ";
    }cout<<'\n';


    fp2 = freopen("in.txt","r",stdin);
    
    for(int i = 0; i < N; i++){
        cin>>arr2[i];
    }
    fclose(fp2);

    start = chrono::high_resolution_clock::now();
    radixsortUsingselection(arr2,N);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds >(stop - start);
    cout << "Time taken by radix using selection: "<< duration.count() << " microseconds" << endl;
    for(int i = 0; i < N; i++){
        cout<<arr2[i]<<" ";
    }cout<<'\n';

    fclose(fp3);
    return 0;
}