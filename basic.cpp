#include <stdio.h>
#include <GL/glut.h>
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3ub(99, 45, 79);
  glBegin(GL_POLYGON);
  glVertex2d(1, 1);
  glVertex2d(1, 3);
  glVertex2d(2, 4);
  glVertex2d(2, 3);
  glVertex2d(3, 3);
  // glVertex2d(3,2);
  glVertex2d(4, 4);
  glVertex2d(4, 3);
  glVertex2d(5, 3);
  glVertex2d(5, 1);
  glEnd();

  glColor3ub(200, 45, 100);
  glPointSize(40);
  glBegin(GL_POINTS);
  glVertex2d(5, 5);
  glEnd();

  glPushMatrix();
  glColor3f(0.000, 1.000, .00);
  glScalef(1, 1, 0);
  // glutSolidCube(10);
  glutSolidSphere(2, 100, 100);
  glEnd();
  glPopMatrix();

  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  // glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

  // glutInitWindowPosition(100,100);
  glutInitWindowSize(800, 800);
  glutCreateWindow("window");

  // glClearColor(1.0, 0.0, 0.0, 0.0);         // black background

  // glMatrixMode(GL_PROJECTION);              // setup viewing projection
  // glLoadIdentity();                           // start with identity matrix

  glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0); // setup a 10x10x2 viewing world
  //   glOrtho(-50.0,50.0,-50.0,50.0,-1.0,1.0);

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
