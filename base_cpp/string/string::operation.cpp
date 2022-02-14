// string assigning
#include <iostream>
#include <string>

int main ()
{
  std::string str1, str2, str3;
  str1 = "Test string: ";   // c-string       //通过=运算符来给已创建的string“赋值”
  str2 = 'x';               // single character
  str3 = str1 + str2;       // string         
  //注意这里重载了"+",string类的"+"可以理解为胶水，将两个string类型连接起来了

  std::cout << str3  << '\n';
  return 0;
}
//Output:
//Test string: x
