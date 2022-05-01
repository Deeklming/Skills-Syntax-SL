# hashing

hashing(해싱)은 컨테이너에 특정 원소가 있는지, 특정 키에 해당하는 값을 찾는 lookup(조회) 작업에 사용하면 좋다   
조회 작업에는 대규모 자료 찾기, 출입증 체크 등 많은 곳에서 쓰인다   

## cuckoo hashing
```c++
#include <iostream>
#include <vector>

using namespace std;

class hashMap{
    vector<int> d1;
    vector<int> d2;
    int size;
    int hash1(int k) const{ return k%size; }
    int hash2(int k) const{ return (k/size)%size; }
public:
    hashMap(int n):size(n){
        d1=vector<int>(size, -1);
        d2=vector<int>(size, -1);
    }
    vector<int>::iterator lookup(int key){
        auto hash_v1=hash1(key);
        if(d1[hash_v1]==key){
            cout<<"1 table "<<key<<" find."<<endl;
            return d1.begin()+hash_v1;
        }

        auto hash_v2=hash2(key);
        if(d2[hash_v2]==key){
            cout<<"2 table "<<key<<" find."<<endl;
            return d2.begin()+hash_v2;
        }
        return d2.end();
    }
    void erase(int key){
        auto p=lookup(key);
        if(p!=d2.end()){
            *p=-1;
            cout<<key<<" delete."<<endl;
        }else{
            cout<<key<<" not found."<<endl;
        }
    }
    void insert(int key){
        insert_impl(key, 0, 1);
    }
    void insert_impl(int key, int cnt, int table){
        if(cnt>=size){
            cout<<key<<" !You need rehashing."<<endl;
            return;
        }
        if(table==1){
            int hash=hash1(key);
            if(d1[hash]==-1){
                cout<<table<<" table "<<key<<" insert."<<endl;
                d1[hash]=key;
            }else{
                int old=d1[hash];
                d1[hash]=key;
                cout<<table<<" table "<<key<<" insert: "<<old<<" move-> ";
                insert_impl(old, cnt+1, 2);
            }
        }else{
            int hash=hash2(key);
            if(d2[hash]==-1){
                cout<<table<<" table "<<key<<" insert."<<endl;
                d2[hash]=key;
            }else{
                int old=d2[hash];
                d2[hash]=key;
                cout<<table<<" table "<<key<<" insert: "<<old<<" move-> ";
                insert_impl(old, cnt+1, 1);
            }
        }
    }
    void print(){
        cout<<"Index: ";
        for(int i=0; i<size; i++) cout<<i<<'\t';
        cout<<endl;

        cout<<"d1:\t";
        for(auto i: d1) cout<<i<<'\t';
        cout<<endl;

        cout<<"d2:\t";
        for(auto i: d2) cout<<i<<'\t';
        cout<<endl;
    }
};

int main(){
    hashMap map(7);
    map.print();
    cout<<endl;

    map.insert(13);
    map.insert(20);
    map.insert(30);
    cout<<endl;

    map.insert(105);
    map.insert(2);
    map.insert(31);
    map.insert(70);
    map.insert(19);
    map.insert(90);
    map.insert(7);
    cout<<endl;

    map.print();
    cout<<endl;
    map.insert(14);//무한루프 발생
}
```
cuckoo hashing(뻐꾸기 해싱)은 2개의 테이블을 사용하고 무한루프에 빠지려고 하면 재해싱을 수행해야 하고 높은 성능을 보장하려면 전체 원소 개수가 해시 테이블 크기의 절반보다 작아야 한다   

## hash table
```c++
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print(const unordered_set<int>& container){
    for(const auto& ele: container) cout<<ele<<" ";
    cout<<endl;
}
void print(const unordered_map<int, int>& container){
    for(const auto& ele: container) cout<<ele.first<<": "<<ele.second<<", ";
    cout<<endl;
}

void find(const unordered_set<int>& container, const int ele){
    if(container.find(ele)==container.end()) cout<<ele<<" find: fail"<<endl;
    else cout<<ele<<"find: success"<<endl;
}
void find(const unordered_map<int, int>& container, const int ele){
    auto it=container.find(ele);
    if(it==container.end()) cout<<ele<<" find: fail"<<endl;
    else cout<<ele<<"find: success, value="<<it->second<<endl;
}

int main(){
    cout<<"-unordered_set-"<<endl;
    unordered_set<int> s1 = {1,2,3,4,5};
    cout<<"s1 init: ";
    print(s1);

    s1.insert(2);
    cout<<"2 insert: ";
    print(s1);
    s1.insert(12);
    s1.insert(312);
    cout<<"12, 312 insert: ";
    print(s1);

    find(s1, 4);
    find(s1, 100);

    s1.erase(2);
    cout<<"2 delete: ";
    print(s1);
    find(s1, 2);

    cout<<"\n-unordered_map-"<<endl;
    unordered_map<int, int> m1;
    m1.insert({2,4});
    m1[3]=9;
    cout<<"2, 3 ^2 insert: ";
    print(m1);

    m1[20]=400;
    m1[30]=900;
    cout<<"20, 30 ^2 insert: ";
    print(m1);

    find(m1, 10);
    find(m1, 20);;
    cout<<"m1[3]="<<m1[3]<<endl;
    cout<<"m1[100]="<<m1[100]<<endl;
    print(m1);

    cout<<s1.bucket_count()<<endl;
    cout<<s1.max_bucket_count()<<endl;
    cout<<m1.load_factor()<<endl;
    m1.rehash(10);
}
```
hash table은 c++에서 unordered_map과 unordered_set을 이용해 기본적으로 제공하는 해시 함수이다   

## bloom filter
```c++
#include <iostream>
#include <vector>

using namespace std;

class bloom_filter{
    vector<bool> d;
    int nBits;
    int hash(int num, int key){
        switch(num){
            case 0: return key%nBits;
            case 1: return (key/7)%nBits;
            case 2: return (key/11)%nBits;
        }
        return 0;
    }
public:
    bloom_filter(int n): nBits(n){
        d=vector<bool>(nBits, false);
    }
    void lookup(int key){//필요한 모든 비트가 1인지 검사
        bool result=d[hash(0, key)] & d[hash(1, key)] & d[hash(2, key)];
        if(result) cout<<key<<": ok"<<endl;
        else cout<<key<<": never"<<endl;
    }
    void insert(int key){
        d[hash(0, key)]=true;
        d[hash(1, key)]=true;
        d[hash(2, key)]=true;
        cout<<key<<" insert.";

        for(auto a: d) cout<<a<<" ";
        cout<<endl;
    }
};

int main(){
    bloom_filter bf(7);
    bf.insert(100);
    bf.insert(30);
    bf.insert(16);
    
    bf.lookup(5);
    bf.lookup(50);
    bf.lookup(30);
    bf.lookup(54);
}
```
bloom filter(블룸 필터)는 해시 테이블에 비해 공간 효율이 높지만 부정확한 결과를 얻을 수 있다   
즉, 긍정적인 답변을 얻었으면 그 원소는 실제로 있을수도 있고 없을수도 있지만 부정적인 답변을 얻었으면 확실히 그 원소는 없다   
bloom filter는 실제 값을 저장하지 않으며 특정 값이 있는지 없는지에 대한 bool타입 배열을 사용한다   
bloom filter는 주로 이메일 중복 검사할 때 유용하게 쓰인다   
