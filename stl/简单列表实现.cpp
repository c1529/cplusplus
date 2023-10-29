#include<iostream>
using namespace std;

// 列表类的简易实现
class MyList {
private:
    int *nums;   // 数组（存储元素）
    int numsCapacity = 10; //列表容量，默认10
    int numsSize = 0; // 列表长度（即当前元素数量）
    int extendRatio = 2;   // 每次列表扩容的倍数
public:
    // 构造方法
    MyList(){
        nums = new int[numsCapacity];
    }
    // 析构函数
    ~MyList(){
        delete[] nums;
    }
    // 获得数组长度
    int size(){
        return numsSize;
    }
    // 获得列表容量
    int capacity(){
        return numsCapacity;
    }
    // 访问元素
    int get(int index){
        // 如果索引越界则抛出异常
        if(index<0||index>=size())
            throw out_of_range(" 索引越出界 ");
        return nums[index];
    }

    // 更新元素
    void set(int index,int num){
         if(index<0||index>=size())
             throw out_of_range(" 索引越出界 ");
         nums[index] = num;
    }

    // 列表扩容,只有在加入元素时候才会扩容，因此size数据需要在加入元素的时候更新
    void extendCapacity(){
        // 新建一个长度为原数组 extendRatio 倍的新数组
        int newCapacity = capacity()*extendRatio;
        int *temp = nums;
        nums = new int[newCapacity];
        // 将原来的数组中的元素赋值给新数组
        for(int i=0;i<size();i++){
            nums[i] = temp[i];
        }
        // 释放内存
        delete[] temp;
        numsCapacity = newCapacity;
    }



    // 尾部添加元素
    void add(int num){
        // 元素数量超出容量，进行扩容
        if(size()==capacity())
            extendCapacity();
        nums[size()] = num;
        // 更新size
        numsSize++;
    }

    // 中间插入元素
    void insert(int index,int num){
        if(index<0||index>=size()){
            throw out_of_range(" 索引越界 ");
        }
        if(size()==capacity())
            extendCapacity();
        // 将index以及以后元素向后移动一位
        for(int j = size()-1;j>=index;j--){
            nums[j+1] = nums[j];
        }
        nums[index] = num;
        numsSize++;
    }
    // 删除元素
    int remove(int index){
        if(index<0||index>=size()){
            throw out_of_range(" 索引越界 ");
        }
        int num = nums[index];
        // 索引后的元素都向前移动一位
        for(int j = index;j<size()-1;j++){
            nums[j] = nums[j+1];
        }
        numsSize--;
        return num;
    }

    // 打印列表
    void out(){
        for(int j=0;j<size();j++){
            cout<<nums[j]<<" ";
        }
        cout<<size();
    }

};



int main()
{
    MyList mylist;
    cout<<mylist.size()<<endl;
    for(int i=0;i<4;i++){
        mylist.add(i*i);
    }
    mylist.out();
    cout<<endl;
    cout<<mylist.get(2);
    return 0;
}
