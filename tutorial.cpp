#include<iostream>
#include<math.h>
#include<string>

#include <bits/stdc++.h>

// instead of all the above includes, we can just use
// #include<bits/stdc++.h>  // this includes all the libraries

// int main(){

//     std::cout <<"HELLO\n\n";

//     return 0;
// } goes to

using namespace std;


// void explainpair(){
//     pair <int,int> p={1,3};
//     cout << p.first;
//     pair<int , pair<int,int>> p1;
//     p1.first=1;
//     p1.second.first=2;
//     p1.second.second=3;
//     cout << p1.first << " " << p1.second.first << " " << p1.second.second;

//     pair <int,int>arr[]={{1,2},{3,4},{5,6}};

// }

void explainvector(){
    // vector <int> v;
    // vector<int>v(5,100);
    // v.push_back(1);
    // v.push_back(2);
    // // cout << v[0]<<v[1];
    // v.emplace_back(3);
    // v.emplace_back(4);
    // // cout << v[2]<<v[3];

    // vector<int>vbar(v);
    
    // // cout << v[0]<<v[1]<<v[2]<<v[3]<<v[4]<< v[5]<<v[6]<<v[7]<<v[8];
    // cout << vbar[0]<<vbar[1]<<vbar[2]<<vbar[3]<<vbar[4]<< vbar[5]<<vbar[6]<<vbar[7]<<vbar[8];

    // vector<int>v={10,20,30,40,50};
    // vector<int>::iterator it=v.begin();
    // cout << *it << " ";
    // it++;
    // cout << *it<< " ";
    // it++;
    // cout << *it<< " ";

    // vector<int>::iterator it=v.end();
    // it--;
    // cout << *it << " ";
    // it--;
    // cout << *it<< " ";
    // it--;
    // cout << *it<< " ";

    // cout<<v[0]<< " "<< v.at(1) << " "<< v.back();

    // for (vector<int>::iterator it=v.begin(); it<v.end();it++){
    //   cout << *it<< " ";
    // }
    
    // auto it =5 sets value  to integer 5
    // for(auto it=v.begin();it<v.end();it++)
    //   cout << *it<< " ";

    vector<int>v={10,20,30,40,50};

    // for (auto it:v)
    //   cout<< it<< " ";
    
    // v.erase(v.begin()+1,v.begin()+3);
    // for (auto it:v)
    //   cout<< it<< " ";

    // v.insert(v.begin()+1,100);
    // v.insert(v.begin()+1,2,100);
    // for (auto it:v)
    //   cout<< it<< " ";

    // vector<int>copy(2,50);
    // v.insert(v.begin()+1,copy.begin(),copy.end());
    // for (auto it:v)
    //   cout<< it<< " ";
    // cout <<v.size();
    v.pop_back();
    for (auto it:v)
      cout<< it<< " ";
    // v1.swap(v2) swaps the values of v1 and v2
    // v.clear() clears the vector
    // v.empty() checks if the vector is empty

}


// vector singly linked list
// list is a doubly linked list

void explainlist(){
  // deque<int>ls; // same functions 
  list <int>ls;
  ls.push_back(2);
  ls.emplace_back(3);
  ls.push_front(1);
  ls.emplace_front(0);
  ls.pop_back();
  for(auto it:ls)
    cout << it << " ";

  // rest functions are same as vector

}

void explainstack(){
  stack<int>st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(3);
  
  cout << st.top();
  st.pop();
  // cout << st.size(), st.empty();
  stack <int>st1,st2;
  st1.swap(st2);
}

void explainqueue(){
  queue<int>q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  
  q.back()+=5;
  cout << q.back() << " " << q.front();
  q.pop();
  cout<< q.front();
}

void explainpq(){
  // max heap
  priority_queue<int>pq;
  pq.push(5);
  pq.push(8);
  pq.push(3);
  pq.push(10);

  cout <<pq.top()<< " ";

  pq.pop(); 
  cout << pq.top() << " ";

  //min heap
  priority_queue<int,vector<int>,greater<int>>pqmin;
  pqmin.push(5);
  pqmin.push(8);
  pqmin.push(3);
  pqmin.push(10);

  cout <<pqmin.top()<< " ";

  pqmin.pop(); 
  cout << pqmin.top() << " ";

}

void explainset(){
  // sorted unique
  set<int>s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);

  auto it=s.find(3);
  cout << *it << " ";
  // it is an iterator, so we can use it to access the elements

  auto it1=s.find(6); // if element is not there it will return s.end()
  cout << s.count(3)<< " "; // returns 1 if element is present, 0 if not present
  s.erase(3);
  cout << s.count(3);
  // can also use st.erase(it) to erase the element at the iterator position
  auto its=s.find(2);
  auto ite=s.find(4);
  s.erase(its,ite); // erases 2 and 3

  auto itl=s.lower_bound(2); // returns the first element that is greater than or equal to 2
  auto itu=s.upper_bound(2); // returns the first element that is greater than 2 

}

void explainmultiset(){
  // sorted not unique
  multiset<int>m;
  m.insert(1);
  m.insert(1);
  m.insert(1);

  m.erase(1); //erases all the elements with value 1
  m.count(1); // returns the count of elements with value 1
  m.erase(m.find(1)); // erases the first occurrence of 1

}

void explainunorderedset(){
  // not sorted unique
  unordered_set<int>u;
  // all set operations except for lower_bound and upper_bound are same as set
  // most operations in unordered_set are O(1) on average worst case O(n)  
}

void explainmap(){
  // stores unique keys in sorted order 
  map <int,int>mpp; //{1,2}
  map<int,pair<int,int>>mpq;//{3,{1,2}}  

  // mpq [10]={2,3};
  mpp.insert({3,1});
  mpq.insert({1,{2,3}}); // can use emplace or insert

  for (auto it:mpp)
    cout << it.first;

    auto it= mpp.find(3);
    cout << (*it).second;

    // if we dont get a result from find, it returns mpp.end()
    // also has lower and upper boumnd funcitons 

    // multimap and unordered map are same as set multiset unordered set 
}

int main(){
  // explainpair();
  explainpq();
}
// int main(){
//     cout<<"HELOO\n\n";

//     // int x,y;
//     // cin >> x >>y;
//     // cout <<"The value of x is: " << x << " and y is: "<< y;

//     // string s;
//     // getline(cin,s);
//     // cout << s;

//     // if(1==2){
//     //     cout << "Hello";
//     // }
//     // else if(3==3){
//     //     cout << "Hola";
//     // }
//     // else{
//     //     cout << "Bonjour";
//     // }


//     // int day;
//     // cin >> day;
    
//     // switch (day){

//     //     case 1:
//     //         cout << 1;
//     //         break;
//     //     case 2:
//     //         cout << 2;
//     //         break;
//     //     case 3:
//     //         cout << 3;
//     //         break;
//     //     default:
//     //         cout << "Invalid day";
//     //         break;
//     // }

//     // int arr[5];
//     // for(int i=0;i<5;i++)
//     //     cin >> arr[i];
//     // int i=4;
//     // while(i>=0){    
//     //     cout << arr[i];
//     //     i--;
//     // }

//     // do while alse allowed


//     return 0;

// }

// int add(int *a, int b){
//     return *a+b;
// }

// int main(){

//     int a;
//     a=9;
//     // cout << *a << a;
//     cout << add(&a,9);

      // std::string str = "Hello";
      
      // // Option 1: using +=
      // str += " World";

      // // Option 2: using append()
      // str.append("!");

      // std::cout << str << std::endl;  // Output: Hello World!
      // return 0;
// }