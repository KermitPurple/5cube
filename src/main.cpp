#include<iostream>
#include<GL/glut.h>
#include<FiveCube.h>

FiveCube cube;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cube.project_points();
    cube.draw();
    cube.rotate(0.0003);
    glutSwapBuffers();
    // glRotatef(0.1, 0, 0, 1);
}

void kbin(unsigned char key, int x, int y){
    switch(key){
        case '\x1b':
            exit(0);
            break;
        case 'w':
            glRotatef(-1, 1, 0, 0);
            break;
        case 'a':
            glRotatef(-1, 0, 1, 0);
            break;
        case 's':
            glRotatef(1, 1, 0, 0);
            break;
        case 'd':
            glRotatef(1, 0, 1, 0);
            break;
        case 'q':
            glRotatef(1, 0, 0, 1);
            break;
        case 'e':
            glRotatef(-1, 0, 0, 1);
            break;
        case '-':
            cube.change_distance(1);
            break;
        case '+':
            cube.change_distance(-1);
            break;
    }
}

void print_controls(){
    std::cout << "esc : exit" << std::endl;
    std::cout << "w, a, s, d, q, e : rotate" << std::endl;
    std::cout << "- : decrease size" << std::endl;
    std::cout << "+ : increase size" << std::endl;
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(675, 675);
    glutCreateWindow("5D cube");
    glOrtho(-100, 100, -100, 100, -100, 100);
    glRotatef(45, 1, 1, 0);

    print_controls();

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(kbin);

    glutMainLoop();
	return 0;
}
