
#include <iostream>

#include "Matrix3D.cpp"

using namespace  std;

int main() {

    Vector3D a = Vector3D(3,2,-2);
    Vector3D b = Vector3D(1,0,-5);


    Vector3D c = cross(a, b);
    cout << c.x << endl;
    cout << c.y << endl;
    cout << c.z << endl;


    return 0;
}
