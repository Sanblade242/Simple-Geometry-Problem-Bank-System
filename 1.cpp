#define _CRT_SECURE_NO_WARNINGS
#include "Triangle.h"  // 包含三角形头文件
#include <iostream>
#include<stdio.h>//生成伪随机
#include <string>
#include <vector>//存储
#include <cstdlib>//随机数函数
#include <ctime>//时间
#include <fstream>//文件读写，保存成绩
#include <iomanip>//格式化输出
#include <limits>//类型极限值
using namespace std;
   int random(int min, int max) {//全局辅助函数
        return min + rand() % (max - min + 1);
    }
Triangle gentri() {//生成随机三角形
    double a, b, c;
    do {
        a = random(1, 20);
        b = random(1, 20);
        double lower = fabs(a - b);//绝对值
        double upper = a + b;
        if (lower >= upper) continue;
        c = random(lower, upper);
    } while (c <= 0 || a + b <= c || b + c <= a || a + c <= b);
    return Triangle(a, b, c);
    }
void saveScore(const string& filename, int correct, int total) {//保存成绩
    ofstream file(filename, ios::app);//文件写入
    if (!file) {// 检查文件是否成功打开
        cout << "无法打开成绩文件！" << endl;
        return;
    }
    time_t now = time(nullptr);//获取当前时间戳
    file << "时间：" << ctime(&now);
    file << "正确：" << correct << "/" << total;
    file << "------------------------" << endl;
    file.close();                        // 关闭文件
    cout << "成绩已保存到文件 " << filename << endl;
}

int main() {
    srand((unsigned int)time(nullptr));
    int qc;//题目数量
    cout << "请输入练习题目数量";
    cin >> qc;

    vector<Shape*>questions;//题目
    for (int i = 0; i < qc; ++i) {
        Triangle tri = gentri();
        questions.push_back(new Triangle(tri));
    }
    vector<char> res(qc, false);//将qc初始设置为false
    int correctCount = 0;//总分

    cout << "\n========== 开始答题 ==========" << endl;
   
    for (int i = 0; i < qc; ++i) {
        //取出当前题目
        Shape* p = questions[i];
        Triangle* tri = static_cast<Triangle*>(p);//转型
        cout << "\n第 " << i + 1 << " 题：" << endl;
        cout << "三角形三边分别为："
            << tri->getsidea() << ", "
            << tri->getsideb() << ", "
            << tri->getsidec() << endl;

        //计算正确答案
        double cA= p->calare();//正确面积
        double cc = p->calcc();//正确周长
        string gt = p->gettype();

        // 获取用户输入的面积和周长,类型
        double userArea, userPerimeter;string userType;
        cout << "请输入该三角形的面积：";
        cin >> userArea;
        cout << "请输入该三角形的周长：";
        cin >> userPerimeter;
        cout << "请输入该三角形的类型：";
        cin >> userType;

        //判断对错（考虑浮点数误差，允许 0.01 以内的误差）
        const double EPSILON = 0.01;
        bool areaCorrect = fabs(userArea - cA) < EPSILON;
        bool perimeterCorrect = fabs(userPerimeter - cc) < EPSILON;
        bool typeCorrect = (userType == gt);

        if (areaCorrect && perimeterCorrect) {
            cout << "正确！" << endl;
            correctCount++; // 答对一题，分数加1
        }
        else {
            cout << "错误！" << endl;
            if (!areaCorrect)
                cout << "面积错误，正确答案为：" << cA << endl;
            if (!perimeterCorrect)
                cout << "周长错误，正确答案为：" << cc << endl;
            if(!typeCorrect)
                cout << "类型错误，正确答案为：" << gt << endl;
        }
    }

    // 输出最终成绩
    cout << "\n=== 答题结束 ===" << endl;
    cout << "答对题数：" << correctCount << " / " << qc << endl;
    cout << "总分：" << correctCount << " 分（每题1分）" << endl;


    return 0;
}
