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
#include<numeric>   // for accumulate()
#include<tuple>
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

struct Point{
    int x,y;
    Point(int i,int j) {x=i;y=j;}
};

bool myCmp(Point p1,Point p2){
    return (p1.x<p2.x);
}

int myFunc(int x,int y){
    return x*y;
}

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





    // Forward List    -> singly linked list
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








    vector<int> vect = {3,5,6,7,20};

    // find()       -> (from,to,element) -> if found it returns address of that element
    auto iter = find(vect.begin(), vect.end(),7);
    if(iter == vect.end())
        cout<<"Not found";
    else{
        cout<<"found at :"<<iter-vect.begin()<<endl;
    }
    // we should use find functions of map,set,string given by that containers itself as they are optimized for that particular container

    // lower_bound() -> (from,to,element) -> returns an it having address of element greater than or equal to given value in a sorted array
    auto iter_lowerBound = lower_bound(vect.begin(),vect.end(),7);
    cout<<*iter_lowerBound<<endl;  // 7
    auto iter_lowerBound_2 = lower_bound(vect.begin(),vect.end(),4);
    cout<<*iter_lowerBound_2<<endl;  // 5

    // upper_bound() -> returns element greater to the first greater element
    auto iter_upperBound = upper_bound(vect.begin(),vect.end(),7);
    cout<<*iter_upperBound<<endl;  // 20
    auto iter_upperBound_2 = upper_bound(vect.begin(),vect.end(),4);
    cout<<*iter_upperBound_2<<endl;  // 5

    // is_permutation() -> (from_first_array,to_first_array,from_second_array) -> return true if both have same elements order doe not matter
    vector<int> vect2 = {6,7,5,20,3};
    if(is_permutation(vect.begin(),vect.end(),vect2.begin()))
        cout<<"These have same elements"<<endl;
    else
        cout<<"These do not have same elements"<<endl;

    // max_element() and min_element() -> (from,to,*comparison function)
    vector<Point> vect3 = {{10,20},{20,30},{30,40}};
    auto iter_max = max_element(vect3.begin(),vect3.end(),myCmp);
    cout<<((*iter_max).x)<<" "<<((*iter_max).y)<<endl;

    // count() -> (from,to,element) -> count of element
    // binary_search() -> (from,to,element) -> same as find but here element should be in sorted order and time complexity is O(log n) where as in find it is O(n)
    // fill() -> (from,to,element) -> replace all elements with given element

    //rotate() -> (from,mid,to) -> it makes mid as first element and place elements in from - mid at last
    rotate(vect.begin(),vect.begin()+3,vect.end());
    for(int x:vect)
        cout<<x<<" ";       // 7 20 3 5 6
    cout<<endl;

    // accumulate() -> (from,to,inital value,*function) -> it perform function on every element of array if funtion is not provided then it adds all elements
    int init_res = 0;
    cout<<accumulate(vect.begin(),vect.end(),init_res)<<endl;
    int init_res_3 = 1;
    cout<<accumulate(vect.begin(),vect.end(),init_res_3,myFunc)<<endl;

    // make_heap() -> (from,to) -> make heap (max element at top by default)
    make_heap(vect.begin(),vect.end());
    cout<<vect.front()<<endl;       // max element
    pop_heap(vect.begin(),vect.end());  // it just pops the element on front (max element) and put it at last (it does not remove it from array)
    cout<<vect.front()<<endl;       
    vect[4] = 50;               // replacing poped element
    push_heap(vect.begin(),vect.end());     // it push new element to heap
    cout<<vect.front()<<endl;

    //merge() -> (from_first_array,to_first_array,from_second_array,to_second_array,new_array of added size) -> both arrays should be sorted first then only merge() works
    int arr_1[] = {10,20,30};
    int arr_2[] = {15,25,35};
    int arr_3[6];
    merge(arr_1,arr_1+3, arr_2,arr_2+3, arr_3);
    for(int x:arr_3)
        cout<<x<<" ";
    cout<<endl;

    // reverse() -> (from,to) -> reverse the order
    // (pos!=string::npos)      // we use string::npos it means that position of element is -1 i.e it is not present in whole string
    // str.find("geeks",pos+1);  // find can take two parameters (element,from where to start)






    // tuple
    tuple<int,string,int> tp = make_tuple(10,"tushar",20);
    cout<<get<0>(tp)<<" "<<get<1>(tp)<<" "<<get<2>(tp)<<endl;
    get<0>(tp) = 14;
    cout<<get<0>(tp)<<endl;
    cout<<tuple_size<decltype(tp)>::value<<endl;
    string s;
    int x,y;
    tie(x,s,y) = tp;
    cout<<x<<" "<<y<<" "<<s<<endl;
    tuple<int,string,int> tp2 = make_tuple(10,"tushar",20);
    auto tp3 = tuple_cat(tp,tp2);
}

