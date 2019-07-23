// 设置精度案例
// setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
using namespace std;
int main () {
  double f =3.14159;
  cout << setprecision(4) << f << '\n'; //3.142
  cout << setprecision(9) << f << '\n'; //3.14159
  //fixed与setprecision操作符一起使用时
  //setprecision将指定浮点数字的小数点后要显示的位数
  //而不是要显示的总有效数位数
  cout << fixed << f << '\n';           //3.141590000
  cout << setprecision(4) << f << '\n'; //3.1416
  cout << setprecision(9) << f << '\n'; //3.141590000
  return 0;
}
