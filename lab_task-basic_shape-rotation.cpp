#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

float _angle = 0.0f;
float _cameraAngle = 0.0f;

void octagon(void)
{
    glColor3f(0.65, 0.09, 0.04);
	int o1[] = { 4 , 12 };
	int o2[] = { 6 , 14 };
	int o3[] = { 9 , 14 };
	int o4[] = { 11, 12 };
	int o5[] = { 11 , 9 };
	int o6[] = { 9, 7 };
	int o7[] = { 6 , 7 };
	int o8[] = { 4 , 9 };

	glBegin(GL_POLYGON);
		glVertex2iv(o1);
		glVertex2iv(o2);
		glVertex2iv(o3);
		glVertex2iv(o4);
		glVertex2iv(o5);
		glVertex2iv(o6);
		glVertex2iv(o7);
		glVertex2iv(o8);
    glEnd();
}

void pentagon(void)
{
    glColor3f(1, 0.4, 0);
	int o1[] = { 6 , -11 };
	int o2[] = { 8 , -9 };
	int o3[] = { 10 , -11 };
	int o4[] = { 9, -13 };
	int o5[] = { 7 , -13 };

	glBegin(GL_POLYGON);
		glVertex2iv(o1);
		glVertex2iv(o2);
		glVertex2iv(o3);
		glVertex2iv(o4);
		glVertex2iv(o5);
    glEnd();
}

void hexagon(void)
{
    glColor3f(.5, .2, .7);
	int o1[] = { -4 , -3 };
	int o2[] = { -2 , -6 };
	int o3[] = { -4, -9 };
	int o4[] = { -7 , -9 };
	int o5[] = { -9 , -6 };
	int o6[] = { -7 , -3 };

	glBegin(GL_POLYGON);
		glVertex2iv(o1);
		glVertex2iv(o2);
		glVertex2iv(o3);
		glVertex2iv(o4);
		glVertex2iv(o5);
		glVertex2iv(o6);
    glEnd();
    glutSwapBuffers();
}


void display(void)
{
	glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -5.0f);
	glPushMatrix();
	glTranslatef(0.0f, -1.0f, 0.0f);
	glRotatef(_angle, 0.0f, 0.0f, -1.0f);

	glBegin(GL_QUADS);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(2, 4);
		glVertex2f(4, 4);
		glVertex2f(4, 6);
		glVertex2f(2, 6);
	glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glScalef(0.7f, 0.7f, 0.7f);

	glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f( 6, -1);
		glVertex2f( 2, -1 );
		glVertex2f( 4, 2 );
	glEnd();
	glPopMatrix();

	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		for (GLfloat i = -5.5; i <= 0; i += 0.25)
		{
			glVertex3f(i, 0, 0); glVertex3f(i, 0, -5.5);
			glVertex3f(0, 0, i); glVertex3f(-5.5, 0, i);
		}
	glEnd();

	glPushMatrix();
	glTranslatef(-1.0f, 1.0f, 0.0f);
	glRotatef(_angle, 1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
        glColor3f(.8,.2,.8);
        glVertex2f(-2.5,3);
        glVertex2f(-4,5);
        glVertex2f(-5.5,3);
        glVertex2f(-4,1);
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0f, 1.0f, 0.0f);
	glRotatef(_angle, 0.0f, 1.0f, 0.7f);
    	octagon();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(-1.0f, 0.5f, 0.0f);
	glRotatef(_angle, 0.5f, 1.0f, 0.8f);
    	pentagon();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(-1.0f, 0.0f, 1.0f);
	glRotatef(_angle, 0.9f, 0.0f, 0.2f);
		hexagon();
    glPopMatrix();

	glFlush();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay(); ////Tell GLUT that the scene has changed
	glutTimerFunc(25, update, 0);
}

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL); //Enable color
	glClearColor(0.7f, 0.9f, 1.0f, 1.0f); //Change the background to sky blue
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
	printf("LAB-1 (ID: 193-15-1071)\n");
	glutInit(&argc, argv);
	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(400,250);
	glutInitWindowSize(700,700);

	glutCreateWindow ("LAB1");
	initRendering();

	//glClearColor(1.0, 1.0, 1.0, 0.0);         // black background
	glMatrixMode(GL_PROJECTION);              // setup viewing projection
	//glLoadIdentity();                           // start with identity matrix
	glOrtho(-15.0, 15.0,-15.0, 15.0, -15.0, 15.0);   // setup a 10x10x2 viewing world

	glutDisplayFunc(display);
	//glutReshapeFunc(handleResize);
	glutTimerFunc(30, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}

