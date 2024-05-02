#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Stack{
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

string isBalanced(string para){
    //This will go through each character in the string para
    for(int n=0; n < para.length(); n++){
        //it will then check for a open round bracket and 
        //if found, it will push it to the stack.
        cout<<para.find("(");
        if(para.find("(")){
            cout<<"vow";
            int position = para.find("(");
            cout<<position;
            push(para[position]);
            //This part will change the string by getting rid
            //of the open parathesis that has been pushed and then
            //lower the iteration number down by 1.
            para.erase(position-1, 1);
            n--;
            }else{
            //if it finds a closing round bracket,
            //then it will check if the stack is empty
            cout<<"ron";
            if(para.find(")")){
                if(stack.empty()){
                    //if it is empty, then the expression is not balanced
                    return "hello"; //"Not Balanced";
                }
                else{
                    //if it is not empty, then it will
                    //pop_back a open round bracket in the stack.
                    pop();
                }
            }
        }
    }
    //after it is done checking the string, 
    //then it will check the stack if it has any remaining open round bracket.
    if(stack.empty()){
        //if it is empty, then the expression is balanced
    return "Balanced";
    }
    else{
        //if it is not, then the expression is not balanced.
        return "Not Balanced";
    }
}

private:
vector<char> stack;
};

int main(){
    Stack s;
    cout<<s.isBalanced("()");
    return 0;
}