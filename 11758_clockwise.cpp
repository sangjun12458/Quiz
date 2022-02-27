#include <iostream>

using namespace std;

pair<double, double> point[3];

int check_clockwise(double x1, double y1, double x2, double y2)
{
    if (x1 == 0)
    {
        if (x2 == 0)
            return 0;
        if (y1 * x1 > 0)
            return -1;
        return 1;
    }

    double l1 = y1 / x1;
    double l2 = y2 / x2;
    if (l1 == l2) return 0;

    double temp = x1 * (y2 - y1 - l1 * (x2 - x1));
    if (temp > 0) return 1;
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++)
        cin >> point[i].first >> point[i].second;

    double x1 = point[1].first - point[0].first;
    double y1 = point[1].second - point[0].second;
    double x2 = point[2].first - point[1].first;
    double y2 = point[2].second - point[1].second;

    cout << check_clockwise(x1, y1, x2, y2);

    return 0;
}
