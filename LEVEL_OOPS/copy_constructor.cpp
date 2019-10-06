#include <iostream>

using namespace std;

class Point
{
private:
  int x, y;

public:
  Point(int x1, int y1)
  {
    x = x1;
    y = y1;
  }
  
  Point(const Point &p2) // Copy constructor
  {
    x = p2.x;
    y = p2.y;
  }

  int getX() 
  { 
    return x; 
  }

  int getY() 
  { 
    return y; 
  }
};

int main(int argc, char** argv)
{
  
}
