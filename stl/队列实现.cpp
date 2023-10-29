#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

class ListQueue{
private:
    ListNode *front,*rear; // 头节点front,尾节点rear
    int queSize;
public:
    ListQueue(){
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }
    ~ListQueue(){
        // 遍历链表删除节点，释放内存
//        ListNode* node = front;
//        while(node){
//            ListNode* temp = node->next;
//            delete node;
//            node = temp;
//        }
    }
    int size(){
        return queSize;
    }
    bool empty(){
        return queSize==0;
    }
    // 入队
    void push(int num){
        ListNode* node = new ListNode(num);
        // 两种情况
        // 如果队列为空，首尾都指向该节点
        if(front==nullptr){
            front = node;
            rear = node;
        }
        // 如果不为空，尾节点指向该节点
        else {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }

    // 出队
    void pop(){
        ListNode* node = front;
        front = front->next;
        delete node;
        queSize--;
    }

    // 获取对首元素
    int peek(){
        if(size()==0)
            throw out_of_range(" 队为空 ");
        return front->val;
    }

    void out(){
        ListNode* head = front;
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
};

int main()
{
    ListQueue queue;
    for(int i=0;i<9;i++){
        queue.push(i*i);
    }
    queue.out();
    cout<<endl<<"队首元素："<<queue.peek()<<endl;
    queue.pop();
    cout<<endl<<"队首元素："<<queue.peek()<<endl;
    queue.out();
    return 0;
}
