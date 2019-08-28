// 1. 两行输入
// 格式为
// 第一行：n, m
// 第二行：m个数合成数组mm
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits.h>
using namespace std;
int main(){
    int n, m;
    vector<int> vec(m);

    cin >> n >> m;
    for (int i=0;i<m;++i) {
        cin>>vec[i];
        //
    }
    
    //   
    return 0;
}


// 2. 1+n行输入或2行输入
// 格式为
// 第一行：n ,m
// 第二行：n*m个数，存为[n x m]的矩阵
// #第二行之后，也可以用换行符隔开输入，没必要整行输入矩阵#
#include "stdlib.h"
#include <iostream>
#include<vector>
#include <iomanip>
using namespace std;
int main()
{
    int m, n;
    //cout << "请输入行和列：";
    cin >> m >> n;

    //注意下面这一行：vector <int后两个 "> "之间最好要有空格，部分编译器会被认为是重载 "> > "。   
    vector<vector<int> > p(m, vector<int>(n));

    //cout << "请输入数据：";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];

    //cout << "输出数据：" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(3) << p[i][j];
        cout << endl;
    }
    system("pause");
    return 0;
}

// 3.
// 格式为
// 第一行：动态长度的数组
// 输出动态长度的数字，空格间隔，回车完成输入
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> numbers;
    while (1)
    {
        int temp;
        cin >> temp;
        // scanf("%d", &temp);
        numbers.push_back(temp);
        char s = cin.get(); //s用来接收是否是回车
        // s = getchar(); //s用来接收是否是回车
        if (s == '\n')
        {
            break;
        }
    }
    //打印
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    return 0;
}



// 4.
// 格式为
// 多行输入，每行2个数，直到遇见EOF才结束
// Windows下EOF为Ctrl+z，Unix/Linux下为Ctrl+d
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    vector<double> test;
    while (cin>>n>>m)//循环多行输入，回车换行，Ctrl+Z可结束循环
    {
        test.push_back(n+m);
    }
    for (int i = 0; i < test.size(); ++i)
    {
        cout << fixed << setprecision(2) << test[i] << endl;
    }
    return 0;
}



// 5.
// 字符串输入
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    for (int i = 0; i < T; ++ i)
    {
        int n, m;
        cin >> n >> m;
        int q[n];
        //vector<int> q;
        for (int j = 0; j<n; ++j)    scanf("%d", &q[j]);
        
        for (int k = 0; k<m; ++k)
        {
            int l, r;
            cin >> l >> r;
            cin.get();         //跳过回车
            string str;
            getline(cin, str); //整行读入
            //operation
            
        }
        
        
        
    }
    
    
    return 0;
}



// 6.
// 按行输入数组vector<int> num 不执行中断
string s;
while (getline(cin, s)) //屈一整行
{
    vector<int> num;
    int start_index = 0;
    for (int i = 0; i != s.size(); ++i) 
    {
        if (s[i] == ' ') //空格区分
        {
            num.push_back(stoi(s.substr(start_index, i - start_index)));//子串转换为整数
            start_index = i + 1;
        }
    }
    num.push_back(stoi(s.substr(start_index, s.size() - start_index)));
}
