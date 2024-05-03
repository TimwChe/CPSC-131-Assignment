#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Stack{

private:
vector<char> stack;

public:
Stack(){
    stack={};
}

void push(char data){
    stack.push_back(data);
}

int getSize(){
    return stack.size();
}

void pop(){
    int size = getSize();
    if(size==0){
        cout<<"Stack is empty"<<endl;
        return;
    }
    stack.pop_back();
}

void peek(){
    int size = getSize();
    if(size==0){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<stack[size-1]<<endl;
}

void isEmpty(){
    int size = getSize();
    if(size==0){
        cout<<"Stack is empty"<<endl;
    }
    return;
}
//Professor's code
string isBalanced(string para){
    //This will go through each character in the string para
    for(int n = 0; n < para.size(); n++) {
        //it will then check for a open round bracket and 
        //if found, it will push it to the stack.
        if(para[n] == '(') {
            push(para[n]);
        }
        //if it finds a closing round bracket,
        //then it will check if the stack is empty
        else if(para[n] == ')') {
            if(getSize() == 0) {
                 //if it is empty, then the expression is not balanced
                return "Not Balanced";
            }
            else {
                //if it is not empty, then it will
                //pop_back a open round bracket in the stack.
                pop();
            }
        }
    }
    //after it is done checking the string
    //then it will check the stack if it has any remaining open round bracket.
    //if it is empty, then the expression is balanced
    //if it is not, then the expression is not balanced.
    return getSize() == 0 ? "Balanced" : "Not Balanced";
}
};

int main(){
    Stack s;
    cout<<s.isBalanced("(())");
    return 0;
}