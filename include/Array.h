//
// Created by zhaodejin on 2021/8/3.
//
#pragma once
#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H
#include<iostream>
using namespace std;
template <typename T>
class Array {
protected:
    static const int MAXSIZE;
    T *data;
    T length;
public:
    Array();
    Array(const int&);
    void ArrayInsert(const int&,const T&);
    void ArrayErase(const int&);
    T& ArrayGetItem(const int &) const;
    T& ArrayFind(const T&) const;
    void ArrayShow() const;
    ~Array();
};

#endif //ARRAY_ARRAY_H
