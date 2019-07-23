// 格式为
// 第一行：n, m
// 第二行：m个数组成数组mm
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


// 格式为
// 第一行：n ,m
// 第二行：n*m个数，存为[n x m]的矩阵
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


// 设置精度案例
// setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
using namespace std;

int main () {
  double f =3.14159;
  cout << setprecision(5) << f << '\n'; //3.1416
  cout << setprecision(9) << f << '\n'; //3.14159
  cout << fixed << f;                   //3.14159
  cout << setprecision(4) << f << '\n'; //3.1415
  cout << setprecision(9) << f << '\n'; //3.141590000
  return 0;
}
