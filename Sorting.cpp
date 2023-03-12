#include<iostream>
using namespace std;

int BubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
        if(arr[j]<arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}

int SelectionSort(int arr[],int n){
    
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    
    return 0;
}

void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current = arr[i];
        int j = i-1;

        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }


    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }cout<<endl;

}



int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    InsertionSort(arr,n);
    //SelectionSort(arr,n);

}