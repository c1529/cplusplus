#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){

    }
};

class ListStack{
private: ListNode* stackTop;  // 栈顶
    int stackSize;  // 栈的长度
public:
    // 初始化
    ListStack(){
        stackTop = nullptr;
        stackSize =0;
    }

    // 析构函数
    ~ListStack(){
        // 遍历栈，释放内存

    }

    // 获取栈的长度
    int size(){
        return stackSize;
    }

    // 判断栈是否为空
    bool empty(){
        return size()==0;
    }

    // 入栈
    void push(int num){
        ListNode* node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stackSize++;
    }

    // 出栈
    void pop(){
        //int num = top();
        ListNode* temp = stackTop;
        stackTop = stackTop->next;
        // 释放内存
        delete temp;
        stackSize--;
    }

    // 访问栈顶元素
    int top(){
        if(size()==0)
            throw out_of_range(" 栈为空 ");
        return stackTop->val;
    }

    void out(){
        ListNode* head = stackTop;
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
    }

};



int main()
{
    ListStack stack;
    for(int i=0;i<8;i++){
        stack.push(i);
    }
    stack.out();
    cout<<endl<<stack.top()<<endl;
    stack.pop();
    cout<<stack.top()<<endl;
    stack.out();
    return 0;
}
