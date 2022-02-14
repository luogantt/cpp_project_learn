// string constructor
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  std::string s0 ("Initial string");  //根据已有字符串构造新的string实例

  // constructors used in the same order as described above:
  std::string s1;             //构造一个默认为空的string
  std::string s2 (s0);         //通过复制一个string构造一个新的string
  std::string s3 (s0, 8, 3);    //通过复制一个string的一部分来构造一个新的string。8为起始位置，3为偏移量。
  std::string s4 ("A character sequence");  //与s0构造方式相同。
  std::string s5 ("Another character sequence", 12);  //已知字符串，通过截取指定长度来创建一个string
  std::string s6a (10, 'x');  //指定string长度，与一个元素，则默认重复该元素创建string
  std::string s6b (10, 42);      // 42 is the ASCII code for '*'  //通过ASCII码来代替s6a中的指定元素。
  std::string s7 (s0.begin(), s0.begin()+7);  //通过迭代器来指定复制s0的一部分，来创建s7


  cout<<"s0:=  "<<s0<<endl;
  std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
  std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';
  return 0;
}

//Output:
//s1: 
//s2: Initial string
//s3: str
//s4: A character sequence
//s5: Another char
//s6a: xxxxxxxxxx
//s6b: **********
//s7: Initial
