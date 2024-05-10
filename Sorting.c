void selectionSort(int arr[],int n){
        int i,j,min_index;
        for(i=0;i<n-1;i++){
            min_index=i;
            for(j=i+1;j<n;j++){
                if(arr[min_index]>arr[j]){
                    min_index=j;
                }
            }
            if(arr[min_index]!=i){
                swap(&arr[i],&arr[min_index]);
            }
        }
    }
void printArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\n%d",arr[i]);
    }
}

void insertionSort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&& key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}
int partition(int arr[], int low,int high){
    int pivot=arr[low];
    int start=low+1;
    int end=high;
    while(start<end){
        while(pivot>=arr[start]){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(end>start){
            swap(&arr[start],&arr[end]);
        }
        swap(&arr[low],&arr[end]);
        return end;
    }
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int loc=partition(arr,low,high);
        quickSort(arr,low,loc-1);
        quickSort(arr,loc+1,high);
    }
}

void merge(int arr[], int l,int m ,int r){
    int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1], R[n2];
    
    for(i=0;i<n1;i++)
    L[i]=arr[l+i];
    for(j=0;j<n2;j++)
    R[j]=arr[m+1+j];
    
    i=0;j=0;k=1;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
        arr[k]=R[j];
        j++;
    }
        k++;
        
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n1){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(r>l){
    int m=l+(r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    
    
}}
int main(){
    int arr[5]={1,43,23,45,4};
    //QuickSort(arr,5);
mergeSort(arr,0,4);
    printArray(arr,5);
}