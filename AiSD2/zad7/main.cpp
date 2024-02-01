#include<iostream>
#include <algorithm>
#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "circleShape.h"


using namespace std;

int main() // nie dziala :(
{
    short int task;
    cin >> task;
    switch(task)
    {
        case(1):
        {
            int size;
            cin >> size;

            Circle* circles = new Circle[size];

            for (int i = 0; i < size; ++i) {
                circles[i].inputData();
            }

            sort(circles, circles + size,
                    [](const Circle& a, const Circle& b) {
                        return a.calculateCircumference() > b.calculateCircumference();
                    });

            for (int i = 0; i < size; ++i) {
                circles[i].displayAttributes();
            }

            delete[] circles;
            break;
        }   
        case(2):
        {
            int rows, columns;
            cin >> rows >> columns;

            Shape*** shapes = new Shape**[rows];

            for (int i = 0; i < rows; ++i) {
                shapes[i] = new Shape*[columns];
                for (int j = 0; j < columns; ++j) {
                    if (i % 2 == 0) {
                        shapes[i][j] = new CircleShape();
                    } else {
                        shapes[i][j] = new Rectangle();
                    }
                    shapes[i][j]->inputData();
                }
            }

            int selectedRow, selectedColumn;
            cin >> selectedRow >> selectedColumn;

            shapes[selectedRow][selectedColumn]->displayAttributes();

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    delete shapes[i][j];
                }
                delete[] shapes[i];
            }
            delete[] shapes;
            break;
        }
    }
        
    return 1;
}
