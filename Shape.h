#pragma once
#include<string>
using namespace std;

class Shape
{
public:
	virtual double calcc()=0;//计算周长
	virtual double calare()=0;//计算面积
	virtual string gettype()=0;//类型
	virtual void flow()=0;//流程封装
};

