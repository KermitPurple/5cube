#include<iostream>
#include<FiveCube.h>
#include<GL/glut.h>

FiveCube::FiveCube(){
    distance = 100;
    reset_points();
};

void FiveCube::reset_points(){
	points[0] = {start_num, start_num, start_num, start_num, start_num};
	points[1] = {-start_num, start_num, start_num, start_num, start_num};
	points[2] = {-start_num, -start_num, start_num, start_num, start_num};
	points[3] = {start_num, -start_num, start_num, start_num, start_num};
	points[4] = {start_num, start_num, -start_num, start_num, start_num};
	points[5] = {-start_num, start_num, -start_num, start_num, start_num};
	points[6] = {-start_num, -start_num, -start_num, start_num, start_num};
	points[7] = {start_num, -start_num, -start_num, start_num, start_num};
	points[8] = {start_num, start_num, start_num, -start_num, start_num};
	points[9] = {-start_num, start_num, start_num, -start_num, start_num};
	points[10] = {-start_num, -start_num, start_num, -start_num, start_num};
	points[11] = {start_num, -start_num, start_num, -start_num, start_num};
	points[12] = {start_num, start_num, -start_num, -start_num, start_num};
	points[13] = {-start_num, start_num, -start_num, -start_num, start_num};
	points[14] = {-start_num, -start_num, -start_num, -start_num, start_num};
	points[15] = {start_num, -start_num, -start_num, -start_num, start_num};
	points[16] = {start_num, start_num, start_num, start_num, -start_num};
	points[17] = {-start_num, start_num, start_num, start_num, -start_num};
	points[18] = {-start_num, -start_num, start_num, start_num, -start_num};
	points[19] = {start_num, -start_num, start_num, start_num, -start_num};
	points[20] = {start_num, start_num, -start_num, start_num, -start_num};
	points[21] = {-start_num, start_num, -start_num, start_num, -start_num};
	points[22] = {-start_num, -start_num, -start_num, start_num, -start_num};
	points[23] = {start_num, -start_num, -start_num, start_num, -start_num};
	points[24] = {start_num, start_num, start_num, -start_num, -start_num};
	points[25] = {-start_num, start_num, start_num, -start_num, -start_num};
	points[26] = {-start_num, -start_num, start_num, -start_num, -start_num};
	points[27] = {start_num, -start_num, start_num, -start_num, -start_num};
	points[28] = {start_num, start_num, -start_num, -start_num, -start_num};
	points[29] = {-start_num, start_num, -start_num, -start_num, -start_num};
	points[30] = {-start_num, -start_num, -start_num, -start_num, -start_num};
	points[31] = {start_num, -start_num, -start_num, -start_num, -start_num};
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
    glPointSize(4);
    glBegin(GL_POINTS);
    for(int i = 0; i < arr_size; i++){
        glVertex3f(projected[i].x, projected[i].y, projected[i].z);
    }
    glEnd();
    draw_cube(projected);
    draw_cube(projected + cube_arr_size);
    draw_cube(projected + cube_arr_size * 2);
    draw_cube(projected + cube_arr_size * 3);
}

void FiveCube::draw_cube(Coord* p){
    for(int i = 0; i < 4; i++){
        //draw top
        glBegin(GL_LINES);
            glVertex3f(p[i].x, p[i].y, p[i].z);
            glVertex3f(p[(i+1)%4].x, p[(i+1)%4].y, p[(i+1)%4].z);
        glEnd();
        //draw bottom
        glBegin(GL_LINES);
            glVertex3f(p[i+4].x, p[i+4].y, p[i+4].z);
            glVertex3f(p[((i+1)%4)+4].x, p[((i+1)%4)+4].y, p[((i+1)%4)+4].z);
        glEnd();
        //connect
        glBegin(GL_LINES);
            glVertex3f(p[i].x, p[i].y, p[i].z);
            glVertex3f(p[i + 4].x, p[i + 4].y, p[i + 4].z);
        glEnd();
    }
}
