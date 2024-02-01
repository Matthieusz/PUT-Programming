#include <iostream>
#include <list>
#include <string>

using namespace std;

//zrobione na skroty

class Point {
private:
    string name;
    double x, y;

public:
    Point(const string& n, double xCoord, double yCoord) : name(n), x(xCoord), y(yCoord) {}

    double sumCoordinates() const {
        return x + y;
    }

    bool operator<(const Point& other) const {
    if (this->sumCoordinates() != other.sumCoordinates()) {
        return this->sumCoordinates() < other.sumCoordinates();
    }
        return this->name < other.name;
    }

    friend ostream& operator<<(ostream& os, const Point& point) {
        return os << point.name << " " << point.x << " " << point.y;
    }
};

template<typename T>
class LinkedList {
private:
    list<T> data;

public:
    void insertSorted(const T& element) {
        auto it = data.begin();
        while (it != data.end() && element.sumCoordinates() > it->sumCoordinates()) {
            ++it;
        }
        while (it != data.end() && element.sumCoordinates() == it->sumCoordinates() && element < *it) {
            ++it;
        }
        data.insert(it, element);
    }

    void removeBySum(double targetSum) {
        data.remove_if([targetSum](const T& element) {
            return element.sumCoordinates() == targetSum;
        });
    }

    friend ostream& operator<<(ostream& os, const LinkedList& list) {
        for (const auto& element : list.data) {
            os << element << " ";
        }
        return os;
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList<Point> pointList;

    for (int i = 0; i < n; ++i) {
        string name;
        double x, y;
        cin >> name >> x >> y;
        Point point(name, x, y);
        pointList.insertSorted(point);
    }

    double targetSum;
    cin >> targetSum;

    pointList.removeBySum(targetSum);

    cout << pointList << endl;

    return 0;
}
