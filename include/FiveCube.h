#ifndef FIVE_CUBE_H
#define FIVE_CUBE_H

#include<Coord.h>

class FiveCube {
private:
    static const int arr_size = 32;
    static const int cube_arr_size = 8;
    static constexpr double start_num = 30;
    float total = 0;
    double distance;
    Coord points[arr_size];
    Coord projected[arr_size];
public:
    FiveCube();
    void reset_points();
    void project_points();
    void draw();
    static void draw_cube(Coord* p);
    void rotateWV(double angle);
    void rotateZW(double angle);
};

#endif /* FIV_CUBE_H */
