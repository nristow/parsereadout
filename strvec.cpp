#include <string>
#include <iostream>
#include <sstream>
#include <vector>

int main()
{
  
  std::vector<std::string> test;

  test.push_back("test1");
  test.push_back("test2");

  std::cout << test[1].at(3) << "\n";
  std::cout << test[1].compare(3,1,"t") << "\n";

  return 0;
}
