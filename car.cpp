
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1416

void display(){
    glClearColor(0.6,0.6,0.6,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0, .8, 1.0);
    glVertex2f(-0.7, 0.0);
    glVertex2f(0.6, 0.0);
    glVertex2f(0.6, -0.2);
    glVertex2f(-0.7, -0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.75, 0.75);
    glVertex2f(-0.2, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.5, 0.0);
    glVertex2f(-0.6, 0.0);
    glEnd();

    GLfloat x = -0.4f; GLfloat y = -0.2f; GLfloat radius = .1f;
    int triangleAmount = 40;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 87, 51);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount; i++){
        glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                   );
    }
    glEnd();

    x = 0.4f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(155, 87, 51);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount; i++){
        glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                   );
    }
    glEnd();

    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Jackson's Car");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

//    glScalef(2.0f, 2.0f, 2.0f);

