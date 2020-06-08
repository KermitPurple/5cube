#ifndef FIVE_CUBE_H
#define FIVE_CUBE_H

#include<Coord.h>

class FiveCube {
private:
    static const int arr_size = 32;
    static const int cube_arr_size = 8;
    double distance;
    Coord points[arr_size];
    Coord projected[arr_size];
public:
    FiveCube();
    void reset_points();
    void project_points();
    void draw();
    static void draw_cube(Coord* p);
};

#endif /* FIV_CUBE_H */
