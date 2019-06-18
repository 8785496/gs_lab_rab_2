#include <GL/glut.h>

void  display(void)
{
	// рисуем точки
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3d(1, 0, 0);
	glVertex3d(-4.5, 4, 0); // первая точка
	glColor3d(0, 1, 0);
	glVertex3d(-4, 4, 0);   // вторая точка
	glColor3d(0, 0, 1);     // третья
	glVertex3d(-3.5, 4, 0);
	glEnd();

	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3d(1, 0, 0);
	glVertex3d(-2, 4, 0); // первая точка
	glColor3d(0, 1, 0);
	glVertex3d(-1, 4, 0);   // вторая точка  
	glColor3d(0, 0, 1);     // третья точка
	glVertex3d(0, 4, 0);
	glEnd();

	// рисуем линии
	glLineWidth(1);       // ширину линии  устанавливаем 1
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);     // красный цвет
	glVertex3d(-4.5, 3, 0); // первая линия
	glVertex3d(-3, 3, 0);
	glColor3d(0, 1, 0);     // зеленый
	glVertex3d(-3, 3.3, 0); // вторая линия
	glVertex3d(-4, 3.4, 0);
	glEnd();
	glLineWidth(3);      // ширина 3
	glBegin(GL_LINE_STRIP); // см. ниже
	glColor3d(1, 0, 0);
	glVertex3d(-2.7, 3, 0);
	glVertex3d(-1, 3, 0);
	glColor3d(0, 1, 0);
	glVertex3d(-1.5, 3.3, 0);
	glColor3d(0, 0, 1);
	glVertex3d(-1, 3.5, 0);
	glEnd();

	glLineWidth(5);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_LINE_STIPPLE); // разрешаем рисовать  прерывистую линию
	glLineStipple(2, 58360);    // устанавливаем маску
	glBegin(GL_LINE_LOOP);
	glColor3d(1, 0, 0);
	glVertex3d(1, 3, 0);
	glVertex3d(4, 3, 0);
	glColor3d(0, 1, 0);
	glVertex3d(3, 2.7, 0);
	glColor3d(0, 0, 1);
	glVertex3d(2.5, 3.7, 0);
	glEnd();

	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_LINE_STIPPLE);

	// рисуем треугольники
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	glColor3d(1, 0, 0);      // рисуем треугольник
	glVertex3d(-4, 2, 0);
	glVertex3d(-3, 2.9, 0);
	glVertex3d(-2, 2, 0);
	glEnd();
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //рисуем  проволочные треугольники
	glBegin(GL_TRIANGLE_STRIP);
	glColor3d(0, 1, 0);
	glVertex3d(1, 2, 0);
	glVertex3d(0, 2.9, 0);
	glVertex3d(-1, 2, 0);
	glVertex3d(0, 1.1, 0);
	glEnd();
	glEnable(GL_LINE_STIPPLE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0, 0, 1);
	glVertex3d(4, 2, 0);
	glVertex3d(2.6, 2.8, 0);
	glVertex3d(2, 2, 0);
	glVertex3d(3, 1.1, 0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	// рисуем многоугольники
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3d(0, 1, 0);      // рисуем многоугольник
	glVertex3d(-4, 0, 0);
	glVertex3d(-3, 0.9, 0);
	glVertex3d(-1, 0.9, 0);
	glVertex3d(-2, 0, 0);
	glEnd();

	glFlush();
}

void resize(int width, int height)
{ }

void init(void)
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, 2.0, 12.0);
	gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char ** argv)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50, 10);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Lab rab 2");
	glutReshapeFunc(resize);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
