#include<iostream>
#include<GL/glut.h>
#include<FiveCube.h>
using namespace std;

FiveCube cube;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char* argv[]){
    cube.project_points();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(675, 675);
    glutCreateWindow("5D cube");
    glOrtho(-100, 100, -100, 100, -100, 100);

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
	return 0;
}
