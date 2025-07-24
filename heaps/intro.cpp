#include <iostream>
using namespace std;

class maxHeap{
    public:
        int arr[100];
        int size=0;


        void insert(int val){
            size+=1;
            int index=size;
            arr[index]=val;

            while(index>1){
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else{
                    return ;
                }
            }

        }

        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;

        }

        void deleteFromHeap(){

            if(size==0){
                cout<<"Nothing to delete"<<endl;
                return ;
            }


            swap(arr[1],arr[size]);

            arr[size]=-1;
            size-=1;
            int index=1;


            while(index<size){
                int c1=2*index;
                int c2=2*index+1;
                if(c1<size && arr[c1]>arr[index]){
                    swap(arr[c1],arr[index]);
                    index=c1;
                }
                else if(c2<size && arr[c2]>arr[index]){
                    swap(arr[c2],arr[index]);
                    index=c2;
                }
                else{
                    return ;
                }
            }



        }

};


// takes a node at index i at its correct position for the tree below it
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest); //as the largest index will be having the element coming from the root
    }


}


void heapSort(int arr[],int size){
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);

    }

}




int main() {

    // maxHeap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(54);
    // h.insert(53);
    // h.insert(52);
    // h.print();


    // h.deleteFromHeap();
    // h.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"printing the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);  //converting maxHeap to minHeap   

    cout<<"printing the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
