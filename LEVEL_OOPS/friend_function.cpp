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
