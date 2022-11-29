#include <GL/glut.h>
#include <iostream>
#include<math.h>

int step=10;
using namespace std;

void display()
{
	glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	int m0=5,n0=6,m1=8,n1=12;
    cout<<"(x0,y0): ";
    cin>>m0>>n0;
    cout<<"(x1,y1): ";
    cin>>m1>>n1;
    int x0=m0,y0=n0,x1=m1,y1=n1;
    double dx=x1-x0,
        dy=y1-y0;
    double m=dy / dx;
    int step=dx;
    if(dy>step)
        step=dy;

    glColor3f(0.14, 0.76, 0.11);
    glPointSize(8.0f);
    glBegin(GL_POINTS);
    for(int i=1;i<=step;i++)
    {
        if(m<1.0){
            x0++;
            y0+=round(m);
        }
        else if(m>1.0){
            x0+=round(1/m);
            y0++;
        }
        else{
            x0++;
            y0++;
        }
        cout<<"("<<x0<<", "<<y0<<")"<<endl;
        glVertex2f(x0, y0);
        dx=x1-x0;
        dy=y1-y0;
        m=dy / dx;
    }
    glEnd();

    x0=m0,y0=n0,x1=m1,y1=n1;
    dx=x1-x0,
    dy=y1-y0;
    m=dy / dx;
    step=dx;
    if(dy>step)
        step=dy;

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    for(int i=1;i<=step;i++)
    {
        if(m<1.0){
            x0++;
            y0+=round(m);
        }
        else if(m>1.0){
            x0+=round(1/m);
            y0++;
        }
        else{
            x0++;
            y0++;
        }
        glVertex2f(x0, y0);
        dx=x1-x0;
        dy=y1-y0;
        m=dy / dx;
    }
    cout<<endl;
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
	printf("DDA ALGO. (ID: 193-15-1071)\n");
	glutInit(&argc, argv);
	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(400,250);
	glutInitWindowSize(700,700);
	glutCreateWindow ("LAB1");
	glMatrixMode(GL_PROJECTION);
	glOrtho(-0.0, 15.0,-0.0, 15.0, -0.0, 15.0);
    glClearColor(1, 1, 1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

