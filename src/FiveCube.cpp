#include<iostream>
#include<FiveCube.h>
#include<GL/glut.h>

FiveCube::FiveCube(){
    distance = 100;
    reset_points();
};

void FiveCube::reset_points(){
	points[0] = {30, 30, 30, 30, 30};
	points[1] = {-30, 30, 30, 30, 30};
	points[2] = {-30, -30, 30, 30, 30};
	points[3] = {30, -30, 30, 30, 30};
	points[4] = {30, 30, -30, 30, 30};
	points[5] = {-30, 30, -30, 30, 30};
	points[6] = {-30, -30, -30, 30, 30};
	points[7] = {30, -30, -30, 30, 30};
	points[8] = {30, 30, 30, -30, 30};
	points[9] = {-30, 30, 30, -30, 30};
	points[10] = {-30, -30, 30, -30, 30};
	points[11] = {30, -30, 30, -30, 30};
	points[12] = {30, 30, -30, -30, 30};
	points[13] = {-30, 30, -30, -30, 30};
	points[14] = {-30, -30, -30, -30, 30};
	points[15] = {30, -30, -30, -30, 30};
	points[16] = {30, 30, 30, 30, -30};
	points[17] = {-30, 30, 30, 30, -30};
	points[18] = {-30, -30, 30, 30, -30};
	points[19] = {30, -30, 30, 30, -30};
	points[20] = {30, 30, -30, 30, -30};
	points[21] = {-30, 30, -30, 30, -30};
	points[22] = {-30, -30, -30, 30, -30};
	points[23] = {30, -30, -30, 30, -30};
	points[24] = {30, 30, 30, -30, -30};
	points[25] = {-30, 30, 30, -30, -30};
	points[26] = {-30, -30, 30, -30, -30};
	points[27] = {30, -30, 30, -30, -30};
	points[28] = {30, 30, -30, -30, -30};
	points[29] = {-30, 30, -30, -30, -30};
	points[30] = {-30, -30, -30, -30, -30};
	points[31] = {30, -30, -30, -30, -30};
}

void FiveCube::project_points(){
    for(int i = 0; i < arr_size; i++){
        // std::cout << points[i].x << ", " << points[i].z << ", " << points[i].z << ", " << points[i].w << ", " << points[i].v << std::endl;
        // convert from fifth dimension to fourth
        double multiplier = distance * 0.75 / (distance - points[i].v);
        projected[i].x = points[i].x * multiplier;
        projected[i].y = points[i].y * multiplier;
        projected[i].z = points[i].z * multiplier;
        projected[i].w = points[i].w * multiplier;
        // std::cout << projected[i].x << ", " << projected[i].z << ", " << projected[i].z << ", " << projected[i].w << std::endl;
        // convert from fourth dimension to third
        multiplier = distance * 0.75 / (distance - points[i].w);
        projected[i].x = projected[i].x * multiplier;
        projected[i].y = projected[i].y * multiplier;
        projected[i].z = projected[i].z * multiplier;
        // std::cout << projected[i].x << ", " << projected[i].z << ", " << projected[i].z << std::endl << std::endl;
    }
}

void FiveCube::draw(){
    glBegin(GL_POINTS);
    for(int i = 0; i < arr_size; i++){
        glVertex3f(projected[i].x, projected[i].y, projected[i].z);
    }
    glEnd();
    draw_cube(projected);
    // draw_cube(projected + cube_arr_size);
    // draw_cube(projected + cube_arr_size * 2);
    // draw_cube(projected + cube_arr_size * 3);
}

void FiveCube::draw_cube(Coord* p){
    for(int i = 0; i < cube_arr_size; i++){
        glBegin(GL_LINES);
            glVertex3f(p[i].x, p[i].y, p[i].z);
            glVertex3f(p[(i+1)%4].x, p[(i+1)%4].y, p[(i+1)%4].z);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(p[i+4].x, p[i+4].y, p[i+4].z);
            glVertex3f(p[((i+1)%4)+4].x, p[((i+1)%4)+4].y, p[((i+1)%4)+4].z);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(p[i].x, p[i].y, p[i].z);
            glVertex3f(p[i + 4].x, p[i + 4].y, p[i + 4].z);
        glEnd();
    }
}
