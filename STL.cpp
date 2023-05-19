#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<forward_list>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

// TEMPLATES
template <typename T>
T myMax(T x,T y){
    return (x>y) ? x :y;
}

// Class Template
template <typename T>
struct Pair{
    T x,y;
    Pair(T i, T j) {x=i;y=j;};
    T getFirst() {return x;};
    T getSecond() {return y;};
};

int main(){

    // ITERATORS

    vector<int> v = {10,20,30,40,50};
    vector<int>::iterator it = v.begin();
    // or
    // auto it = v.begin();    // this will also make iterator
    cout<<*it<<endl;
    it++;                      // it is like pointer only hence we can change its location
    // it = next(it); -> for +1               it = next(it,3) -> we can mention how many steps we want to move
    // it = prev(it);
    cout<<*it<<endl;
    it = v.end();              // v.end() will point to location one ahead of the last element hence it will have garbage value


    // function template
    cout<<myMax<int>(5,7)<<endl;
    cout<<myMax<char>('a','b')<<endl;

    // class template
    Pair<int> pr1(10,20);
    cout<<pr1.getFirst()<<endl;



    // pair
    pair<int ,int> p1(20,30);
    pair<int,string> p2;
    p2={10,"tushar"};
    cout<<p1.first<<endl<<p2.second<<endl;
    // all the comparisons are done using first element of pair only.

    // sort one array according to other
    int a[] = {3,1,2};
    char b[] = {'g','e','k'};
    pair<int,char> pa[3];    
    for (int i = 0; i<3; i++){
        pa[i] = {a[i],b[i]};
    }
    sort(pa,pa+3);
    for(int i  = 0; i<3; i++){
        cout<<pa[i].second<<" ";
    }



    // Vector
    vector<int> vec{10,20,30};
    vec.push_back(40);
    for(int x:vec){         // this method will not change elements in the vector
        cout<<endl<<x<<endl;
    }
    // to change elements in the vector
    for(int &x: vec){   // either pass it by reference or by normally in loop
        x = 5;
    }
    for (auto i=vec.rbegin(); i!=vec.rend(); i++){          // rbegin will run begin() in reverse hence we will will get elements in reverse order also here i is an iterator
        cout<<*i<<endl;
    }

    // functions of vectors
    // pop_back -> pops element from last
    // front , back
    // insert -> v.insert(pos,no.of times,element)
    // erase -> v.erase(pos,upto)  if upto is not mentioned then only pos will be erased
    // clear -> clears whole vecor
    // empty -> check if vector is empty or not
    // resize -> resize to given length





    // Forward List    -> singly lisnked list
    forward_list<int> fl,fl2;
    fl.assign({40,50});     // it should be used only in start else it would remove all elements and make it new one 
    fl.push_front(10);
    fl.push_front(20);
    fl.push_front(30);
    fl.emplace_after(fl.begin(),15);    // emplace is optimized way for insert_after
    fl.remove(20);
    for(int x:fl){
        cout<<x<<" ";
    }
    cout<<endl;
    fl2.assign(fl.begin(),fl.end());    // another usage of assign is to copy one ll to another
    for(int x:fl2){
        cout<<x<<" ";
    }
    cout<<endl;
    fl.reverse();
    fl.merge(fl2);
    fl.sort();
    for(int x:fl){
        cout<<x<<" ";
    }
    cout<<endl;



    // list
    list<int> l = {30,40,50};
    l.push_back(10);
    l.push_front(20);
    l.push_front(20);
    l.pop_back();
    l.insert(l.begin(),25);
    l.unique();         // removes duplicates
    for(int x:l){
        cout<<x<<" ";
    }
    cout<<endl;
    // all other operations of forward list also applicable on list







    // Deque  -> elements can be inserted and deleted from both front and back
    deque<int> d = {10,20,30};
    d.push_back(5);
    d.push_front(10);
    d.pop_back();
    d.insert(d.begin(),25);





    // Stack
    stack<int> st;
    st.push(20);
    st.push(30);
    st.pop();
    cout<<st.top()<<endl;






    cout<<"PRIORITY QUEUE"<<endl;
    // Priority Queue       -> it arranges all elements in descending order 
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(5);
    pq.pop();
    cout<<pq.top()<<endl;

    // to arrange all elements in ascending order
    priority_queue<int ,vector<int> ,greater<int>> prq;
    prq.push(10);
    prq.push(30);
    prq.push(5);
    prq.push(2);
    prq.pop();
    cout<<prq.top()<<endl;

    // we can also create pq using existing array
    int arr_qu[] = {10,5,20};
    priority_queue<int> prqu(arr_qu,arr_qu+3);
    cout<<prqu.top()<<endl;





    cout<<"SET"<<endl;
    // Set   -> arranges in ascending order,removes duplicates
    set<int> st_;
    st_.insert(10);
    st_.insert(20);
    st_.insert(30);
    st_.insert(10);      // duplicate not included
    st_.insert(30);      // duplicate not included
    st_.find(10);    //true
    st_.erase(10);   // to remove all corresponding elements
    for(int x:st_){
        cout<<x<<" ";
    }
    cout<<endl;
    // to reverse order use set<int,greater<int>> 
    // in multiset it doesnot remove duplicates -> also erase function removes all the same elements
    // unordered_set is same as set but there is no order in which elements are arranged it is implemented by hashing and all operations can be done in O(1) time.

    // (s.find(arr[i]) != s.end())            
    // s.find() gives address of that element we can check whether by equting the s.find() != s.end() 
    // it means that if element is gound then its address would be not at s.end() i.e not in that set as s.end() returns the address just after the end of set.
    //  hence if s.find() == s.end() it means that after traversal of set element is not found.








    cout<<"MAP"<<endl;
    // Map -> same as set but takes key value pair , removes duplicate key
    map<int,int> mp;
    mp.insert({1,20});
    mp[2] = 40;
    mp.insert({1,30});  // ignored
    mp[1] = 60;         // this will not be ignored but update the value
    mp.at(1) = 80;      // this updates the key
    // diffrence bw mp[1] , mp.at(1) is mp[1] create a key with value 0 if it is not present but mp.at will throw error
    for(auto x:mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
    // multimap can have same key with different value hence it cannot have []bracket implementation allowed
}

