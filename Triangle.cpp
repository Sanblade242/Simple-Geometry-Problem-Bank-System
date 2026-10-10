#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;
Triangle:: Triangle(double  s1, double s2, double s3) : a(s1), b(s2), c(s3) {
	if (!isvalid()) {
		a = b = c = 0;
		cout << "边长不符合，已重置为0" << endl;
	}
}
bool Triangle::isvalid() const {//判断三边是否成立
	return (a > 0 && b > 0 && c > 0 &&
		a + b > c && a + c > b && b + c > a);
}
void Triangle:: set(double  s1, double s2, double s3) {//set类修改函数
	a = s1;
	b = s2;
	c = s3;
	if (!isvalid()) {
		a = b = c = 0;
		cout << "边长不符合，已重置为0" << endl;
	}
}
double Triangle:: calcc() {//计算周长
	if (!isvalid()) { return 0.0; }
	return a + b + c;
}
double Triangle::calare() {//计算面积
	if (!isvalid()) { return 0.0; }
	double p = (a + b + c) / 2;
	return floor(sqrt(p * (p - a) * (p - b) * (p - c))+0.5);
}
string Triangle::gettype() {//三角形类型
	
	if (a == b && a == c && b == c) {
		return "等边三角形";
	}
	if (a == b|| a == c || b == c) {
		return "等腰三角形";
	}
	if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
		return "直角三角形";
	}
	else{
		return "普通三角形"; 
	}
	
}
void Triangle::flow() {//流程封装
	double s1, s2, s3;
	cout << "请输入三角形的三条边: ";
	cin >> s1 >> s2 >> s3;

	set(s1, s2, s3);

	if (!isvalid()) {
		cout << "无法构成三角形，不能做题。" << endl;
		return;
	}
	
	cout << "构成三角形，开始做题：" << endl;
	cout << "面积: " << calare() << endl;	
	cout << "周长: " << calcc() << endl;
	cout << "类型: " << gettype() << endl;
}