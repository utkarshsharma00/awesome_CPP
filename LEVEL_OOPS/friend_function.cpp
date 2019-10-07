#include <iostream>

using namespace std;

class Box
{
private:
  double width;

public:
  friend void printWidth(Box box);
  void setWidth(double wid);
};

int main(int argc, char**argv)
{
  Box box;

  box.setWidth(10.0);

  printWidth(box);

  return 0;
}
