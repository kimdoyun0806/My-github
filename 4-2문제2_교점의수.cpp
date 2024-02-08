#include <iostream>
#include <cmath>

class Point
{
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int pos_x, int pos_y)
    {
        x = pos_x;
        y = pos_y;
    }
    int GetX();
    int GetY();
    double GetDistance(Point point);

private:
    int x, y;
};

class Geometry
{
public:
    Geometry()
    {
        num_points = 0;
    }

    void AddPoint(Point point);
    void PrintDistance();
    void PrintNumMeets();
    void PrintPoints();

private:
    Point* point_array[100];
    int num_points;
};

int Point::GetX()
{
    return x;
}

int Point::GetY()
{
    return y;
}

double Point::GetDistance(Point point)
{
    return sqrt(pow(point.x - x, 2.0) + pow(point.y - y, 2.0));
}


void Geometry::AddPoint(Point point)
{
    point_array[num_points++] = new Point(point.GetX(), point.GetY());
}

void Geometry::PrintDistance()
{
    for (int i = 0; i < num_points - 1; ++i)
    {
        for (int j = i + 1; j < num_points; ++j)
        {
            std::cout << "Distance between point " << i + 1 << " and " << j + 1 << ": " << point_array[i]->GetDistance(*point_array[j]) << std::endl;;
        }
    }
}

void Geometry::PrintNumMeets()
{
    int cross = num_points;
    for (int i = 0; i < num_points - 1; ++i)
    {
        for (int j = i + 1; j < num_points; ++j)
        {
            int a = point_array[j]->GetY() - point_array[i]->GetY();
            int b = point_array[i]->GetX() - point_array[j]->GetX();
            int c = -(a * point_array[i]->GetX() + b * point_array[j]->GetY());
            for (int k = 0; k < num_points - 1; ++k)
            {
                if (k == i) continue;
                for (int l = k + 1; l < num_points; ++l)
                {
                    if (l == j) continue;
                    if ((a * point_array[k]->GetX() + b * point_array[k]->GetY() + c) * (a * point_array[l]->GetX() + b * point_array[l]->GetY() + c) <= 0) ++cross;
                }
            }
        }
    }
    std::cout << "Total cross points: " << cross << std::endl;
}

void Geometry::PrintPoints()
{
    for (int i = 0; i < num_points; ++i)
        std::cout << "Point [" << i + 1 << "]-X: " << point_array[i]->GetX() << "\t\tY: " << point_array[i]->GetY() << std::endl;
}


int main()
{
    Geometry geo;
    while (true)
    {
        int operation;
        std::cout << "Choose operation(0-Terminate, 1-AddPoint, 2-PrintDistance, 3-PrintNumMeets, 4-PrintPoints): ";
        std::cin >> operation;
        switch (operation)
        {
        case 0:
            return 0;
        case 1:
        {
            int a, b;
            std::cout << "Input X and Y: ";
            std::cin >> a >> b;
            Point point(a, b);
            geo.AddPoint(point);
            break;
        }
        case 2:
            geo.PrintDistance();
            break;
        case 3:
            geo.PrintNumMeets();
            break;
        case 4:
            geo.PrintPoints();
            break;
        default:
            std::cout << "Wrong input. Try again." << std::endl;
        }
    }
}