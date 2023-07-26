#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<double> v2;
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);

	vector<string> v3;
	v3.push_back("李白");
	v3.push_back("杜甫");
	v3.push_back("苏轼");
	v3.push_back("白居易");

	vector<int> v4(10, 5);

	vector<string> v5(++v3.begin(), --v3.end());
	string s = "hello world";

	vector<char> v6(s.begin(), s.end());
}

void test_vector2()
{
	// 遍历
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 1、下表+[]
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] += 1;
		cout << v[i] << " ";
	}
	cout << endl;

	// 2.迭代器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 3.范围for
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	//vector<char> v;
	//cout << v.max_size() << endl;
	size_t sz;
	std::vector<int> foo;
	foo.reserve(100);
	//foo.resize(100);
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	//vector<int> countV;
	//countV.resize(100, 1);
	//countV.resize(10);

	// string vector等都有一个特点，删除数据，一般是不会主动缩容
	foo.resize(10);
	cout << foo.size() << endl;
	cout << foo.capacity() << endl;

	// 慎用、少用
	foo.shrink_to_fit();
	cout << foo.size() << endl;
	cout << foo.capacity() << endl;
}

void test_vector4()
{
	// 遍历
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.insert(v.begin(), -1);
	v.insert(v.begin(), -2);
	v.insert(v.begin(), -3);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin() + 7, 300);
	//v.insert(v.begin()+8, 300);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.erase(v.begin());
	v.erase(v.begin());

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector5()
{
	// 遍历
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		cout << "找到了" << endl;
		v.erase(pos);
	}
	else
	{
		cout << "没有找到" << endl;
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.push_back(0);
	v.push_back(9);
	v.push_back(3);
	v.push_back(1);

	// 默认是升序
	//sort(v.begin(), v.end());   // <

	// 排降序，仿函数
	// 关于仿函数，大家先记住这个用法，具体我们后面讲队列再详细讲
	// sort(v.begin(), v.end(), greater<int>());  // >

	greater<int> g;
	sort(v.begin(), v.end(), g);  // >

	for (int i = 0; i < 5; i++)
	{
		cout << v[i] << ' ';
	}
}

int main()
{
	test_vector5();

	return 0;
}