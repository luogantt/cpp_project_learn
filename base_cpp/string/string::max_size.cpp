// comparing size, length, capacity and max_size
#include <iostream>
#include <string>

int main ()
{
  std::string str ("Test string");
  std::cout << "size: " << str.size() << "\n";
  std::cout << "length: " << str.length() << "\n";
  std::cout << "capacity: " << str.capacity() << "\n";
  std::cout << "max_size: " << str.max_size() << "\n";
  return 0;
}

//A possible output for this program could be:
//size: 11
//length: 11
//capacity: 15
//max_size: 4294967291
