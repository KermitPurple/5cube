#include<iostream>
#include<GL/glut.h>
#include<FiveCube.h>
using namespace std;

FiveCube cube;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cube.project_points();
    cube.draw();
    cube.rotate(0.001);
    glutSwapBuffers();
    // glRotatef(0.1, 0, 0, 1);
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(675, 675);
    glutCreateWindow("5D cube");
    glOrtho(-100, 100, -100, 100, -100, 100);
    glRotatef(45, 1, 1, 0);

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
	return 0;
}
