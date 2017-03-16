#include "Line.h"
#include "Circle.h"
#include "MyPolygon.h"
#include "Triangle.h"
#include "Rect.h"

#include <GL/glut.h>
#include <vector>


using namespace std;

const int WIDTH = 1366, HEIGHT = 768;

vector<Drawable*> drawables;
vector<Transformable*> transformables;
Point* point_mirror;
Segment* mirror_seg;
Line* mirror;
MyPolygon* polygon;
Triangle* triangle;
bool showInner;
bool showOuter;

Point closestPoint;

//USER DEFINED
int getClosestPointIndex (MyPolygon& pol, Point& p) {
	int index = 0;
	double dist = pol[0].distance (p);
	for ( int i = 1; i < pol.size (); i++ ) {
		double tmp = pol[i].distance (p);
		if ( tmp < dist ) {
			index = i;
			dist = tmp;
		}
	}
	return index;
}

Point& getClosestPoint (MyPolygon& pol, Point& p) {
	return pol[getClosestPointIndex (pol, p)];
}


void initGL () {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0, WIDTH, 0, HEIGHT, -1, 1);
	glMatrixMode (GL_MODELVIEW);
	glClearColor (0, 0, 0, 1);
	glDisable (GL_DEPTH_TEST);
}

void init () {
	mirror_seg = new Segment (Point (WIDTH / 2 + 120, 0), Point (WIDTH / 2, HEIGHT));
	drawables.push_back (mirror_seg);
	mirror = new Line (mirror_seg);
	point_mirror = new Point (WIDTH / 2, HEIGHT / 2);
	drawables.push_back (point_mirror);
	polygon = new MyPolygon (Point (400, 400), Point (140, 40), Point (40, 200));
	cout << "Polygon created:" << endl;
	cout << "Number of Points: " << polygon->size () << endl;
	cout << "Area: " << polygon->getArea () << endl;
	cout << "Perimeter: " << polygon->getPerimeter () << endl;
	transformables.push_back (polygon);
	closestPoint = polygon->getPoint (0);
	triangle = new Triangle (Point (20, 0), Point (40, 50), Point (0, 70));
	transformables.push_back (triangle);
	Rect* rect = new Rect (1, 1, 50, 50);
	drawables.push_back (rect);
	showInner = false;
	showOuter = false;
}

void clean () {
	for ( int i = 0; i < drawables.size (); i++ ) {
		delete drawables[i];
	}
	for ( int i = 0; i < transformables.size (); i++ ) {
		delete transformables[i];
	}
	delete mirror;
}

void display () {
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0f, 1.0f, 1.0f);

	for ( int i = 0; i < drawables.size (); i++ ) {
		drawables[i]->draw ();
	}
	for ( int i = 0; i < transformables.size (); i++ ) {
		transformables[i]->draw ();

		transformables[i]->reflect (point_mirror);
		transformables[i]->setColor (0.0f, 1.0f, 0.0f);
		transformables[i]->draw ();
		transformables[i]->reflect (point_mirror);

		transformables[i]->reflect (mirror);
		transformables[i]->setColor (0.0f, 0.0f, 1.0f);
		transformables[i]->draw ();
		transformables[i]->reflect (mirror);

		transformables[i]->setColor (1.0f, 1.0f, 1.0f);
	}
	if ( showInner ) {
		Circle* innerCircle = triangle->getInnerCircle ();
		innerCircle->draw ();
		delete innerCircle;
		if ( polygon->size () == 3 ) {
			Triangle polTri (polygon->getPoint (0), polygon->getPoint (1), polygon->getPoint (2));
			Circle* innerPolCircle = polTri.getInnerCircle ();
			innerPolCircle->draw ();
			delete innerPolCircle;
		}
	}
	if ( showOuter ) {
		Circle* outerCircle = triangle->getOuterCircle ();
		outerCircle->draw ();
		delete outerCircle;
		if ( polygon->size () == 3 ) {
			Triangle polTri (polygon->getPoint (0), polygon->getPoint (1), polygon->getPoint (2));
			Circle* outerPolCircle = polTri.getOuterCircle ();
			outerPolCircle->draw ();
			delete outerPolCircle;
		}
	}

	glFlush ();
}

void mouse_func (int button, int state, int x, int y) {
	y = HEIGHT - y;
	Point p (x, y);
	if ( button == GLUT_RIGHT_BUTTON ) {
		point_mirror->setPosition (p);
	} else if ( button == GLUT_LEFT_BUTTON ) {
		int index = getClosestPointIndex (*polygon, p);
		polygon->addPoint (p, index);
		cout << "Polygon changed:" << endl;
		cout << "Number of Points: " << polygon->size () << endl;
		cout << "Area: " << polygon->getArea () << endl;
		cout << "Perimeter: " << polygon->getPerimeter () << endl;
	}
	display ();
}

void passive_motion_func (int x, int y) {
	y = HEIGHT - y;
	Point p (x, y);
	triangle->setA (p);
	closestPoint = getClosestPoint (*polygon, p);
	if ( polygon->isInside (&p)) {
		polygon->setColor (1.0f, 0.0f, 0.0f);
	} else {
		polygon->setColor (1.0f, 1.0f, 1.0f);
	}
	display ();
}

void keyboard_func (unsigned char key, int x, int y) {
	switch ( key ) {
		case 'a':
			mirror_seg->move (-5, 0);
			delete mirror;
			mirror = new Line (mirror_seg);
			break;
		case 'd':
			mirror_seg->move (5, 0);
			delete mirror;
			mirror = new Line (mirror_seg);
			break;
		case 'w':
			mirror_seg->rotate (point_mirror, Circle::PI / 90);
			delete mirror;
			mirror = new Line (mirror_seg);
			break;
		case 's':
			mirror_seg->rotate (point_mirror, 2 * Circle::PI - Circle::PI / 90);
			delete mirror;
			mirror = new Line (mirror_seg);
			break;
		case 'f':
			polygon->move (-5, 0);
			break;
		case 'h':
			polygon->move (5, 0);
			break;
		case 't':
			polygon->rotate (point_mirror, Circle::PI / 90);
			break;
		case 'g':
			polygon->rotate (point_mirror, 2 * Circle::PI - Circle::PI / 90);
			break;
		case 'p':
			polygon->delPoint (closestPoint);
			cout << "Polygon changed:" << endl;
			cout << "Number of Points: " << polygon->size () << endl;
			cout << "Area: " << polygon->getArea () << endl;
			cout << "Perimeter: " << polygon->getPerimeter () << endl;
			break;
		case 'i':
			showInner = true;
			break;
		case 'k':
			showInner = false;
			break;
		case 'o':
			showOuter = true;
			break;
		case 'l':
			showOuter = false;
			break;
		default:
			break;
	}
	display ();
}

int main (int argc, char** argv) {
	glutInit (&argc, argv);
	glutCreateWindow ("GEOM 2D Test Program");
	glutFullScreen ();
	glutDisplayFunc (display);
	glutMouseFunc (mouse_func);
	glutPassiveMotionFunc (passive_motion_func);
	glutMotionFunc (passive_motion_func);
	glutKeyboardFunc (keyboard_func);
	initGL ();
	init ();
	atexit (clean);
	glutMainLoop ();

	return 0;
}