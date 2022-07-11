#include <iostream>
#include <unordered_map>

std:map<int,string> mapStudent;  //创建了一个key是int，value是string

using namespace std;
//插入元素：
//三种方法

//第一种，用insert函数插入pair
mapStudent.insert(pair<int,string>(000,”student_zero”));

// 第二种 用insert函数插入value_type数据
mapStudent.insert(map<int, string>::value_type(001, "student_one"));

// 第三种 用"array"方式插入
mapStudent[123] = "student_first";
mapStudent[456] = "student_second";
