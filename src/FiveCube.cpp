#include <iostream>
#include<FiveCube.h>

FiveCube::FiveCube(){
    distance = 100;
    reset_points();
};

void FiveCube::reset_points(){
	points[0] = {50, 50, 50, 50, 50};
	points[1] = {-50, 50, 50, 50, 50};
	points[2] = {-50, -50, 50, 50, 50};
	points[3] = {50, -50, 50, 50, 50};
	points[4] = {50, 50, -50, 50, 50};
	points[5] = {-50, 50, -50, 50, 50};
	points[6] = {-50, -50, -50, 50, 50};
	points[7] = {50, -50, -50, 50, 50};
	points[8] = {50, 50, 50, -50, 50};
	points[9] = {-50, 50, 50, -50, 50};
	points[10] = {-50, -50, 50, -50, 50};
	points[11] = {50, -50, 50, -50, 50};
	points[12] = {50, 50, -50, -50, 50};
	points[13] = {-50, 50, -50, -50, 50};
	points[14] = {-50, -50, -50, -50, 50};
	points[15] = {50, -50, -50, -50, 50};
	points[16] = {50, 50, 50, 50, -50};
	points[17] = {-50, 50, 50, 50, -50};
	points[18] = {-50, -50, 50, 50, -50};
	points[19] = {50, -50, 50, 50, -50};
	points[20] = {50, 50, -50, 50, -50};
	points[21] = {-50, 50, -50, 50, -50};
	points[22] = {-50, -50, -50, 50, -50};
	points[23] = {50, -50, -50, 50, -50};
	points[24] = {50, 50, 50, -50, -50};
	points[25] = {-50, 50, 50, -50, -50};
	points[26] = {-50, -50, 50, -50, -50};
	points[27] = {50, -50, 50, -50, -50};
	points[28] = {50, 50, -50, -50, -50};
	points[29] = {-50, 50, -50, -50, -50};
	points[30] = {-50, -50, -50, -50, -50};
	points[31] = {50, -50, -50, -50, -50};
}

void FiveCube::project_points(){
    for(int i = 0; i < arr_size; i++){
        std::cout << points[i].x << ", " << points[i].z << ", " << points[i].z << ", " << points[i].w << ", " << points[i].v << std::endl;
        // convert from fifth dimension to fourth
        double multiplier = distance * 0.75 / (distance - points[i].v);
        projected[i].x = points[i].x * multiplier;
        projected[i].y = points[i].y * multiplier;
        projected[i].z = points[i].z * multiplier;
        projected[i].w = points[i].w * multiplier;
        std::cout << projected[i].x << ", " << projected[i].z << ", " << projected[i].z << ", " << projected[i].w << std::endl;
        // convert from fourth dimension to third
        multiplier = distance * 0.75 / (distance - points[i].w);
        projected[i].x = projected[i].x * multiplier;
        projected[i].y = projected[i].y * multiplier;
        projected[i].z = projected[i].z * multiplier;
        std::cout << projected[i].x << ", " << projected[i].z << ", " << projected[i].z << std::endl << std::endl;
    }
}
