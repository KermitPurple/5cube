#ifndef FIVE_CUBE_H
#define FIVE_CUBE_H

#include<Coord.h>

class FiveCube {
private:
    static const int arr_size = 32;
    double distance;
    Coord points[arr_size];
    Coord projected[arr_size];
public:
    FiveCube();
    void reset_points();
    void project_points();
};

#endif /* FIV_CUBE_H */
