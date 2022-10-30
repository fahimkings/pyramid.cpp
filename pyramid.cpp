#include<GL\glut.h>
GLfloat degree = 20;
void display_pyramid()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(degree, 1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.2f, 0.9f, 0.6f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	//*******************************
	glColor3f(0.7f, 1.0f, 0.9f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	//******************************
	glColor3f(0.4f, 1.0f, 0.3f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	//*****************************
	glColor3f(1.0f, 0.9f, 0.3f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.f, 0.3f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
		glEnd();
	degree += 1;
	glutSwapBuffers();
}
void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}
void reshape(GLsizei width, GLsizei height)
{
	if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Rotating Pyramid");
	glutDisplayFunc(display_pyramid);
	glutReshapeFunc(reshape);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glutTimerFunc(2000, timer, 0);
	glutMainLoop();
	return 0;
}
