#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure
{
public:
    Figure(const string& name_) : name(name_) {}

    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;

protected:
    const string name;
};

class Triangle : public Figure
{
public:
    Triangle(double _a, double _b, double _c) : Figure("TRIANGLE"), a(_a), b(_b), c(_c) {}

    string Name() override
    {
        return name;
    }

    double Perimeter() override
    {
        return a + b + c;
    }

    double Area() override
    {
        auto p = Perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

private:
    double a, b, c;
};

class Rect : public Figure
{
public:
    Rect(double _a, double _b) : Figure("RECT"), a(_a), b(_b) {}

    string Name() override
    {
        return name;
    }

    double Perimeter() override
    {
        return 2 * (a + b);
    }

    double Area() override
    {
        return  a * b;
    }

private:
    double a, b;
};

class Circle : public Figure
{
public:
    Circle(double _r) : Figure("CIRCLE"), r(_r) {}

    string Name() override
    {
        return name;
    }

    double Perimeter() override
    {
        return 3.14 * 2 * r;
    }

    double Area() override
    {
        return  3.14 * r * r;
    }

private:
    double r;
};

shared_ptr<Figure> CreateFigure(istringstream& is)
{
    string name;
    is >> name;
    if (name == "CIRCLE")
    {
        int r;
        is >> r;
        return make_shared<Circle>(r);
    }
    else if (name == "RECT")
    {
        int a, b;
        is >> a >> b;
        return make_shared<Rect>(a, b);
    }
    else if (name == "TRIANGLE")
    {
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    return 0;
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}
