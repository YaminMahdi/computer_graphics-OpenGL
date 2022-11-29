#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <random>
#include <math.h>
#define PI 3.1416
using namespace std;
float xr = 120, yr = 120,infinity=0,  xMin=-40,xMax=40,   yMin=-40,yMax=40;
float x_position = 0, flyObj=0, _angle=0;
int state = 1, kill=0;
int r[]= {255,0,0,0,255,103,0,118,255,0},
         g[]= {0,0,171,255,0,103,255,131,102,204},
              b[]= {0,255,65,255,127,154,127,226,0,255}; //80, 140, 74   103, 103, 154

vector<int> birdReverse= {-52,-110,-100,-114,-116,-104,90,44,28,36};

int range = 200 + 100 + 1,randCol=0;  //max min
//int num = rand() % range - 100;  //min

void specialkey(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        yr+=15;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        yr-=15;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        xr-=15;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        xr+=15;
        glutPostRedisplay();
        break;
    }
}
void NormalKeyHandler (unsigned char key, int x, int y)
{
    if (key == ' ')
    {
        if( xr>=xMin && xr+10<=xMax  &&  yr>=yMin && yr+10<=yMax)
        {
            //infinity=2000;
            flyObj=rand() % 301 - 100;
            xMin=flyObj-40,xMax=flyObj+40,yMin=flyObj-40,yMax=flyObj+40;
            randCol++;
            if(randCol==10)
                randCol=0;
            cout << "\x1B[2J\x1B[H";
            cout<<"Kill Count: "<<++kill<<endl;
            x_position=0;
            glutPostRedisplay();
        }
    }
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(90 / 60, timer, 0);

    _angle += 2.0f;
    if (_angle > 360)
    {
        _angle -= 360;
    }
    switch (state)
    {
    case 1:
        if (x_position+flyObj < 350)
        {
            xMin += 0.5;
            xMax += 0.5;
            x_position += 0.5;
            //cout<<"pos "<<xr<<" "<<yr<<", xm "<<xMin<<endl;
        }

        else
        {
            state = -1;
            birdReverse= {0,0,0,0,0,0,0,0,0,0};
        }

        break;
    case -1:
        if (x_position+flyObj > -350)
        {
            xMin -= 0.5;
            xMax -= 0.5;
            x_position -= 0.5;
            //cout<<"pos "<<xr<<" "<<yr<<", xm "<<xMin<<endl;
        }
        else
        {
            state = 1;
            birdReverse= {-52,-110,-100,-114,-116,-104,90,44,28,36};
        }
        break;
    }
}

void drawSun(int xPos, int yPos) {
	int i;
	glColor3f(1,1,0);
	for (i = 0; i < 200; i++) {
        glTranslatef(xPos, yPos, 0);
		glRotatef( 360 / 13, 0, 0, 1 );
        glTranslatef(-xPos, -yPos, 0);
		glBegin(GL_LINES);
		glVertex2f(xPos+0, yPos+0);
		glVertex2f(xPos+75, yPos+0);
		glEnd();
	}
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( xPos+50*cos(angle), yPos+50*sin(angle));
	}
	glEnd();
	glColor3f(0,0,0);
}

void Bird()
{

    //Feather 1
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(flyObj+x_position+26+birdReverse[0], flyObj+15);//left
    glVertex2f(flyObj+x_position+55+birdReverse[1], flyObj+20);//bottom
    glVertex2f(flyObj+x_position+50+birdReverse[2], flyObj+34);//top
    glEnd();

    //Feather 2
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(flyObj+x_position+26+birdReverse[0], flyObj+5);
    glVertex2f(flyObj+x_position+57+birdReverse[3], flyObj+15);//t
    glVertex2f(flyObj+x_position+58+birdReverse[4], flyObj+3);//b
    glEnd();

    //Feather 3
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(flyObj+x_position+26+birdReverse[0], flyObj-1);
    glVertex2f(flyObj+x_position+58+birdReverse[4], flyObj-3);
    glVertex2f(flyObj+x_position+54+birdReverse[5], flyObj-17);//b
    glEnd();

    //Body
    int i;
    GLfloat x = flyObj+x_position+0.0f;
    GLfloat y = flyObj+0.0f;
    GLfloat radius = 40.0f;
    int triangleAmount = 100;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r[randCol], g[randCol], b[randCol]);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Lip
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(flyObj+x_position-45+birdReverse[6], flyObj-35);
    glVertex2f(flyObj+x_position-22+birdReverse[7], flyObj-12);
    glVertex2f(flyObj+x_position-14+birdReverse[8], flyObj-22);//bot
    glEnd();

    //Eye 1
    x = flyObj+x_position-18.0f+birdReverse[9];
    y = flyObj+16.0f;
    radius = 4.5f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //Eye 2
    x = flyObj+x_position+0.0f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}

void treeBG(int positionY)
{
    glBegin(GL_POLYGON);
    glColor3ub(193, 163, 157);
    glVertex2d(-400, positionY-300);
    glVertex2d(-400, positionY-100);
    glVertex2d(400, positionY-100);
    glVertex2d(400, positionY-300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(49, 157, 82);//172, 120, 90
    glVertex2d(-400, positionY-100);
    glVertex2d(-400, positionY-40);
    glVertex2d(-380, positionY-37);
    glVertex2d(-360, positionY-24);
    glVertex2d(-340, positionY-5);
    glVertex2d(-320, positionY+5);
    glVertex2d(-300, positionY+11);
    glVertex2d(-280, positionY+18);
    glVertex2d(-260, positionY+20);
    glVertex2d(-240, positionY+20);
    glVertex2d(-220, positionY+15);
    glVertex2d(-200, positionY+10);
    glVertex2d(-180, positionY+3);
    glVertex2d(-160, positionY-9);
    glVertex2d(-140, positionY-18);
    glVertex2d(-120, positionY-25);
    glVertex2d(-100, positionY-30);
    glVertex2d(-100, positionY-100);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-100, positionY-100);
    glVertex2d(-100, positionY-30);
    glVertex2d(-80, positionY-30);
    glVertex2d(-60, positionY-27);
    glVertex2d(-40, positionY-21);
    glVertex2d(-20, positionY-15);
    glVertex2d(0, positionY-9);
    glVertex2d(20, positionY+1);
    glVertex2d(40, positionY+10);
    glVertex2d(60, positionY+18);
    glVertex2d(80, positionY+21);
    glVertex2d(100, positionY+23);
    glVertex2d(120, positionY+21);
    glVertex2d(140, positionY+18);
    glVertex2d(160, positionY+10);
    glVertex2d(180, positionY+0);
    glVertex2d(200, positionY-10);
    glVertex2d(220, positionY-18);
    glVertex2d(240, positionY-27);
    glVertex2d(260, positionY-29);
    glVertex2d(260, positionY-100);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(260, positionY-100);
    glVertex2d(260, positionY-29);
    glVertex2d(280, positionY-25);
    glVertex2d(300, positionY-12);
    glVertex2d(320, positionY);
    glVertex2d(340, positionY+8);
    glVertex2d(360, positionY+12);
    glVertex2d(380, positionY+16);
    glVertex2d(390, positionY+17);
    glVertex2d(400, positionY+18);
    glVertex2d(400, positionY-100);

    glEnd();
}
void windmill(int xPos, int yPos)
{
    glColor3ub(85, 85, 127);
    glBegin(GL_POLYGON);
    glVertex2d(xPos-5, yPos);
    glVertex2d(xPos-5, yPos-140);
    glVertex2d(xPos+5, yPos-140);
    glVertex2d(xPos+5, yPos);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(xPos-20, yPos-150);
    glVertex2d(xPos+20, yPos-150);
    glVertex2d(xPos, yPos-135);

    glEnd();


    glColor3ub(231, 231, 231);

    glPushMatrix();
    glTranslatef(xPos, yPos, 0);
    glRotatef(_angle, 0, 0, -1);
    glTranslatef(-xPos, -yPos, 0);

    glBegin(GL_POLYGON);
    glVertex2d(xPos-4, yPos+10);
    glVertex2f(xPos+33.33, yPos+50);
    glVertex2d(xPos+10, yPos);
    glVertex2d(xPos+33.33, yPos-50);
    glVertex2d(xPos-4, yPos-10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(xPos-58, yPos);
    glVertex2d(xPos-4, yPos+9);
    glVertex2d(xPos-4, yPos-9);
    glEnd();

    glPopMatrix();
}

void home(int xPos, int yPos)
{

    glColor3ub(85, 85, 127);
    glBegin(GL_POLYGON);
    glVertex2f(xPos+0,yPos+120);
    glVertex2f(xPos-90,yPos+80);
    glVertex2f(xPos+90,yPos+80);
    glEnd();

    glColor3ub(64, 115, 232);
    glBegin(GL_POLYGON);
    glVertex2f(xPos-70,yPos+5);
    glVertex2f(xPos-70,yPos+80);
    glVertex2f(xPos+70,yPos+80);
    glVertex2f(xPos+70,yPos+5);
    glEnd();

    glColor3ub(128, 168, 232);
    glBegin(GL_POLYGON);
    glVertex2f(xPos-1,yPos);
    glVertex2f(xPos-30,yPos);
    glVertex2f(xPos-30,yPos+50);
    glVertex2f(xPos-1,yPos+50);
    glEnd();

    glColor3ub(128, 168, 232);
    glBegin(GL_POLYGON);
    glVertex2f(xPos+1,yPos);
    glVertex2f(xPos+30,yPos);
    glVertex2f(xPos+30,yPos+50);
    glVertex2f(xPos+1,yPos+50);
    glEnd();

    glColor3ub(54, 84, 181);
    glBegin(GL_POLYGON);
    glVertex2f(xPos-80,yPos+5);
    glVertex2f(xPos+80,yPos+5);
    glVertex2f(xPos+80,yPos+0);
    glVertex2f(xPos-80,yPos+0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(200,250);

    Bird();

    glColor3ub(192, 202, 51);

    glBegin(GL_QUADS);
    glVertex2f(xr,yr);//xmin, ymin
    glVertex2f(10+xr,yr);
    glVertex2f(10+xr,10+yr);//xmax, ymax
    glVertex2f(xr,10+yr);
    glEnd();

    treeBG(-150);

    windmill(-120,-130);

    home(-240,-300);

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    printf("use array key");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(800, 100);
    glutCreateWindow("Bird Shooter - CG Project");
    cout << "\x1B[2J\x1B[H";
    cout<<"Move Cursor with\nArrow Keys."<<endl;
    cout<<"\nKill a Bird by\nPressing 'SPACEBAR'."<<endl;


    glutDisplayFunc(display);
    glutTimerFunc(100, timer, 0);

    glClearColor(0, 0.67, 1, 1);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-400, 400, -400, 400);
    glutSpecialFunc(specialkey);
    glutKeyboardFunc(NormalKeyHandler);

    glutMainLoop();
    return 0;
}
