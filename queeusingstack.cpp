#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class myqueue{
    public:
           void enque(int,stack<int> &st);
           int dequee(stack<int> &);
           void printqueue(stack<int> st);

};

void myqueue::enque(int val, stack<int> &st)
{
    st.push(val);
}

int myqueue::dequee(stack<int> &st)
{
    cout<<"Inside dequee"<<endl;
    if(st.empty()){
         cout<<"ooops...!! queue is empty"<<endl;
         exit(1);
    }

    stack<int> st2;
    while(! st.empty())
    {
        st2.push(st.top());
        st.pop();
    }

    cout<<"Popped Elemet = "<<st2.top()<<endl;
    st2.pop();

    while(!st2.empty())
    {
        st.push(st2.top());
        st2.pop();
    }
}    

void myqueue::printqueue(stack<int> st)
{
    cout<<"\nqueue state \n\n";
    while(st.size() != 0)
    {
        cout<<st.top()<<endl;
        st.pop();
    }

}

int main()
{
    int val, val2;
    stack<int> st;
    myqueue *mq = new myqueue();
    while(1) {
    cout<<" Queue implementation using stack"<<endl;
    cout<<"1 - push \n"
           "2 - pop \n"
           "3 - display \n"
           "4 - exit\n"<<endl;
    cin>>val;

    switch(val)
    {
        case 1:
                cout<<"Enter the val to push = ";
                cin>>val2;
                mq->enque(val2, st);
                break;
        case 2:
                mq->dequee(st);
                break;

        case 3:
                mq->printqueue(st);
                break;

        default:
                exit(1);         
    }    
    }
return 0;
}
