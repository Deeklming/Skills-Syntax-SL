#include <iostream>
#include <vector>
using namespace std;

class BinarySearch{
    vector<char> arr;
    int left, mid, right, count;

public:
    BinarySearch(int size){
        for(int i=1; i<=size; ++i)
            arr.push_back(i);
        count=left=mid=0;
        right=size-1;
    }
    int find(int value){
        int tmp=right;
        while(left<=right){
            ++count;
            mid=left+(right-left)/2;
            if(arr[mid]==value){
                cout<<"ok, count: "<<count<<", ";
                count=left=0;
                right=tmp;
                return mid;
            }else if(arr[mid]<value) left=mid+1;
            else right=mid-1;
        }
        cout<<"fail, count: "<<count<<", ";
        return -1;
    }
};

int main(){
    BinarySearch a(10);
    for(int i=1; i<11; ++i){
        cout<<"value("<< i <<") index: "<<a.find(i)<<endl;
    }
    return 0;
}
