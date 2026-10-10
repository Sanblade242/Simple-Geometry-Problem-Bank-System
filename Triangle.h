#pragma once
#include<string>
#include"Shape.h"
using namespace std;
class Triangle :public Shape{
private:
	double a, b, c;//三边
	double area;//面积
	int cc;//周长
	int score;//分值
public://构造函数三角形
	
	Triangle(double  s1 = 0, double s2 = 0, double s3 = 0);
	void set(double  s1, double s2, double s3);
	double getsidea() const { return a; }//get类返回函数
	double getsideb() const { return b; }
	double getsidec() const { return c; }
	bool isvalid() const;//判断是否成立
	double calcc();//计算周长
	double calare();//计算面积
	string gettype();//类型
	void flow();
};
	
