#include <stdio.h>
#include<GL/glut.h>

#include <math.h>

float x = 0;

#define PI		3.141592654
#define PI_2	PI * 2

//-------------------------------------------------------------------------
void fillOval (float x_center, float y_center, float w, float h, int n)
{
	float theta, angle_increment;
	float x, y;

	if (n <= 0)
		n = 1;

	angle_increment = PI_2 / n;

	glPushMatrix ();

	//  center the oval at x_center, y_center
	glTranslatef (x_center, y_center, 0);

	//  draw the oval using triangle fan
	glBegin (GL_TRIANGLE_FAN);

	//  specify the center

	for (theta = 0.0f; theta - PI_2 < 0.001; theta += angle_increment)
	{
		x = w/2 * cos (theta);
		y = h/2 * sin (theta);

		glVertex2f (x, y);
	}

	glEnd ();

	glPopMatrix ();
}

void drawArc  (float x_center, float y_center, float w, float h, float startAngle, float arcAngle, int n)
{
	float theta, angle_increment;
	float x, y;

	if (n <= 0)
		n = 1;

	angle_increment = PI_2 / n;

	glPushMatrix ();

	//  center the oval at x_center, y_center
	glTranslatef (x_center, y_center, 0);

	//  draw the oval using line segments
	glBegin (GL_LINE_STRIP);

	for (theta = startAngle; theta - (startAngle + arcAngle) < 0.001; theta += angle_increment)
	{
		x = w/2 * cos (theta);
		y = h/2 * sin (theta);

	}

	glEnd ();

	glPopMatrix ();
}



void display() {

	glClear(GL_COLOR_BUFFER_BIT);

    //FACE

	glColor3f(0.9,0.7,0.4);

    fillOval (0.0, 45.0, 30.0, 40.0, 50);

	glPushMatrix();

	//LEFT ARM

	glColor3f(0.9,0.7,0.4);

    drawArc (-125, -125, 20, 40, 0.785, 1.75, 10);

	//TSHIRT

	glBegin(GL_POLYGON);

	glColor3f(0.8,0.2,0.1);

	glVertex2f(-20,20);
	glVertex2f(20,20);
	glVertex2f(30,10);
	glVertex2f(25,5);
	glVertex2f(20,10);
	glVertex2f(20,-20);
	glVertex2f(-20,-20);
	glVertex2f(-20,10);
	glVertex2f(-25,5);
	glVertex2f(-30,10);

	glEnd();

	//SHORTS

	glBegin(GL_POLYGON);
	glColor3f(0.5,0.6,0.9);

    glVertex2f(-20,-20);
	glVertex2f(20,-20);
	glVertex2f(20,-40);
	glVertex2f(4,-40);
	glVertex2f(0,-30);
	glVertex2f(-4,-40);
	glVertex2f(-20,-40);


	glEnd();
    //LEFT LEG
    glBegin(GL_POLYGON);
	glColor3f(0.9,0.7,0.4);

    glVertex2f(-16,-40);
	glVertex2f(-16,-70);
	glVertex2f(-10,-70);
	glVertex2f(-10,-40);

	glEnd();

    //RIGHT LEG
    glBegin(GL_POLYGON);
	glColor3f(0.9,0.7,0.4);

    glVertex2f(10,-40);
	glVertex2f(10,-70);
	glVertex2f(16,-70);
	glVertex2f(16,-40);

	glEnd();

	//NECK
    glBegin(GL_POLYGON);
	glColor3f(0.9,0.7,0.4);

    glVertex2f(-5,30);
	glVertex2f(5,30);
	glVertex2f(5,20);
	glVertex2f(-5,20);

	glEnd();



	glPopMatrix();

	glFlush();

}


int main(int argc, char * argv[]) {
    glutInit(&argc,argv);
	glutInitWindowSize(600, 600);

	glutInitWindowPosition(100, 100);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("person");

	glutDisplayFunc(display);

	glClearColor(0, 0, 0, 0);

	gluOrtho2D(-150, 150, -150, 150);

	glutMainLoop();
}
