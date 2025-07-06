/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort() {
    // Your code here
    multiset<int>st;
    while(!s.empty()){
        st.insert(s.top());
        s.pop();
    }
    while(!st.empty()){
        auto it=st.begin();
        s.push(*it);
        st.erase(st.find(*it));
    }
}