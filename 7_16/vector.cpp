

#include <bits/stdc++.h>
using namespace std;

void test_01()
{
  // 初始化
  int x = 1;
  int n = 5;
  int y = 10;
  // vector<int> v; //为空
  // vector<int> v(n); //初始化 n个0
  vector<int> v(n, x); // n个x

  // 遍历
  //  for(int i =0; i < v.size(); i ++)
  //  {
  //      cout << v[i] << '\n';
  //  }

  // for(auto i : v)
  // {
  //   cout << i << " ";
  // }

  //     for(auto& i :v)
  //     {
  //       cout << i << "";
  //     }
  // 插入
  // // v.push_back(y);
  // int i = 1;
  // v[i] = v.at(i);
  // v.front() = v[0];
  // 确保v.size()> 0
  // v.back() = v[size()-1];
}

void output(vector<int> &v)
{
  cout << "v.size() = " << v.size() << " :";
  // cout << '\n';
  for (auto &i : v)
  {
    cout << i << " ";
  }
  cout << "\n";
}

int main()
{

  vector<int> v;
  output(v);
  v.push_back(1);
  output(v);
  v = vector<int>(5);
  output(v);
  v = vector<int>(3, 2);
  output(v);
  for (int i = 1; i < 10; i++)
    v.push_back(10 - i);
  output(v);
  sort(v.begin(), v.end());
  output(v);
  cout << lower_bound(v.begin(),v.end(),5) - v.begin() << '\n';
  //返回去重后第一个无效的迭代器
  unique(v.begin(), v.end()); 
  output(v);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  output(v);
  return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std;

//void output(vector<int> &v)
//{
//	cout << "v.size()= " << v.size() << " : ";
//	for (auto& i : v)
//	{
//		cout << i << " ";
//	}
//	cout << '\n';
//}

void test_vector01()
{
	/*vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);

	vector<double> v2;
	v2.push_back(1.1);
	v2.push_back(1.2);
	v2.push_back(2.2);
	v2.push_back(3.3);*/

	vector<string> v3;
	v3.push_back("赵志豪");
	v3.push_back("杨延辉");
	v3.push_back("李根");
	v3.push_back("关宏昌");

	vector<int> v4(10, 5);

	vector<string> v5(v3.begin(), v3.end());

	string s = "hello world";
	vector<char> v6(s.begin(), s.end());


}

void test_vector02()
{
	//遍历
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 1[[.下标+[]
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] += 1;
		cout << v[i] << " ";
	}
	cout << '\n';

	// 2.迭代器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << '\n';

	//3. 范围for
	for (auto &i : v)
	{
		cout << i << " ";

	}
 }

signed main()
{
	/*vector<int> v;
	output(v);
	v.push_back(1);
	output(v);
	v = vector<int> (5);
	output(v);
	v = vector<int>(2, 3);
	output(v);
	for (int i = 1; i < 10; i++) v.push_back(10 - i);
	output(v);
	sort(v.begin(), v.end());
	output(v);
	union
	lower_bound()*/

	test_vector01();
	test_vector02();
	return 0;
}