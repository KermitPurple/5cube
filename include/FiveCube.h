#ifndef FIVE_CUBE_H
#define FIVE_CUBE_H

#include<Coord.h>

class FiveCube {
private:
    Coord points[32];
public:
    FiveCube();
    void reset_points();
};

#endif /* FIV_CUBE_H */
