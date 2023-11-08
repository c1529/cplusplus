// 手搓哈希，数字对应字符串
#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 键值对
struct Pair{
public:
    int key;
    string val;
    Pair(int key,string val){
        this->key = key;
        this->val = val;
    }
};
//基于数组实现的简易哈希表
class hasp{
private:
    vector<Pair *> buckets;
public:
    hasp(){
        // 初始化数组，包括100个桶
        buckets = vector<Pair *>(100);
    }
    // 析构函数
    ~hasp(){
     // 释放内存
     for(const auto &bucket:buckets){
         delete bucket;
     }
     buckets.clear();
    }
    // 哈希函数
    int hashFunc(int key){
        int index = key%100;
        return index;
    }

    // 查询操作
    string get(int key){
        int index = hashFunc(key);
        Pair *pair = buckets[index];
        // 如果为空
        if(pair==nullptr){
            return "";
        }

        return pair->val;
    }

    // 添加操作
    void put(int key,string val){
        Pair *pair = new Pair(key,val);
        int index = hashFunc(key);
        buckets[index] = pair;
    }

    // 删除操作
    void remove(int key){
        int index = hashFunc(key);
        // 释放内存并且重置nullptr
        delete buckets[index];
        buckets[index] = nullptr;
    }

    // 获得所有键值对
    vector<Pair *> pairSet(){
        vector<Pair *> pairSet;
        for(auto pair:buckets){
            if(pair){
                pairSet.push_back(pair);
            }
        }
        return pairSet;
    }

    // 获得所有键
    vector<int> keySet(){
        vector<int> keySet;
        for(auto pair:buckets){
            if(pair){
                keySet.push_back(pair->key);
            }
        }
        return keySet;
    }

    // 获得所有值
    vector<string> valueSet(){
        vector<string> valueSet;
        for(auto pair:buckets){
            if(pair){
                valueSet.push_back(pair->val);
            }
        }
        return valueSet;
    }

    // 打印哈希
    void print(){
        for(auto pair:pairSet()){
            cout<<"键是："<<pair->key<<"值是："<<pair->val<<endl;
        }
    }

};


int main()
{
    hasp map;
    map.put(1001,"你好");
    map.put(1009,"世界");
    //map.put(9,"世");
    map.print();
    return 0;
}
