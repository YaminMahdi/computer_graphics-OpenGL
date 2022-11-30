#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(255, 234, 35);
    glBegin(GL_POLYGON);
    glVertex2d(-22, 0);
    glVertex2d(0, 15);
    glVertex2d(22, 0);
    glVertex2d(0, -15);
    glEnd();

    glPushMatrix();
    glColor3ub(6, 0, 117);
    glScalef(1, 1, 0);
    glutSolidSphere(10, 100, 100);
    glEnd();
    glPopMatrix();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(-9, 4.5);
    glVertex2d(-8, 6.1);
    glVertex2d(9, -4.5);
    glVertex2d(8, -6.1);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1300, 800);
    glutCreateWindow("Lab  Final- Brazil Flag");
    glClearColor(0, 0.67, 0.25, 1);
    glOrtho(-30, 30, -18, 18, -1, 1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
