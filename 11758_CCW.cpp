#include <iostream>

using namespace std;

struct Point
{
    private:
    public:
    int x;
    int y;
};

int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int direction = (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
    if (direction > 0) return 1;
    else if (direction < -1) return -1;
    return 0; 
}

int main()
{
    Point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    cout << CCW(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);

    return 0;
}
