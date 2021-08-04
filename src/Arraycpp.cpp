//
// Created by zhaodejin on 2021/8/3.
//
#include "Array.h"
#include<iostream>
using namespace std;
template <typename T> const int Array<T>::MAXSIZE = 100;
template <typename T>
Array<T>::Array(){
    data = new T[MAXSIZE]{0};
    if(data == NULL)
    {
        cout<<"memory malloc is failed!"<<endl;
    }
    length = 0;
    cout<<"successful to create a liner sheet"<<endl;
}
template <typename T>
Array<T>::Array(const int& n) {
    data = new T[MAXSIZE]{0};
    if (data == NULL) {
        cout << "memory malloc is failed!" << endl;
    }
    for (int i = 0; i < n; i++)
        cin >> data[i];
    length = n;
}
template <typename T>
void Array<T>::ArrayInsert(const int& i, const T& temp)  //在线性表的指定位置插入一个元素
{
    if (length == MAXSIZE)
    {
        cout << "超过线性表的最大长度！指定位置插入元素失败！" << endl;
        return;
    }
    if (i < 1 || i > length + 1)
    {
        cout << "位置越界！无法在指定位置插入元素！" << endl;
        return;
    }
    for (int k = length - 1; k >= i - 1; k--)
    {
        data[k + 1] = data[k];
    }
    data[i - 1] = temp;
    length++;
    return;
}

template <typename T>
void Array<T>::ArrayErase(const int& i)  //在线性表的指定位置删除一个元素
{
    if (i < 1 || i > length)
    {
        cout << "位置越界！无法在指定位置删除元素！" << endl;
        return;
    }
    for (int j = i; j <= length - 1; j++)
        data[j - 1] = data[j];
    length--;
    return;
}

template <typename T>
T& Array<T>::ArrayGetItem(const int& i)const  //返回指定位置所对应的元素
{
    if (i < 1 || i > length)
    {
        cout << "位置越界！返回第一个元素！" << endl;
        return data[0];
    }
    return data[i - 1];
}

template <typename T>
T& Array<T>::ArrayFind(const T &num)const  //查找指定元素对应的位置
{
    for(int i = 0; i < length; i++)
    {
        if(data[i] == num)
            return data[i];
    }
    cout << "未找到元素！返回第一个元素！" << endl;
    return data[0];
}

template <typename T>
void Array<T>::ArrayShow()const
{
    if(length == 0)
    {
        cout << "没有元素！" << endl;
        return ;
    }
    for(int i = 0; i < length; i++)
        cout << data[i] << ' ';
    cout << endl;
}
template <typename T>
Array<T>::~Array(){

}
int main() {
    Array<int> L(6);
    cout << L.ArrayFind(2) << endl;
    cout << L.ArrayGetItem(4) << endl;
    L.ArrayInsert(3, 10);
    L.ArrayShow();
    L.ArrayErase(5);
    L.ArrayShow();
    return 0;
}