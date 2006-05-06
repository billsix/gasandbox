// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

// Daniel Fontijne -- fontijne@science.uva.nl

#ifdef WIN32
#include <windows.h>
#endif WIN32

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include <vector>

#include <libgasandbox/e3ga.h>
#include <libgasandbox/e3ga_draw.h>
#include <libgasandbox/e3ga_util.h>
#include <libgasandbox/gl_util.h>
#include <libgasandbox/glut_util.h>

using namespace e3ga;
using namespace mv_draw;

const char *WINDOW_TITLE = "Geometric Algebra, Chapter 3, Example 4: Color Space Conversion";
std::vector<unsigned char>g_sourceImage;
std::vector<unsigned char>g_destImage;

// GLUT state information
int g_viewportWidth = 800;
int g_viewportHeight = 600;
int g_GLUTmenu;

void display() {
	glViewport(0, 0, g_viewportWidth, g_viewportHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, g_viewportWidth, 0, g_viewportHeight, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_LIGHTING);
/*	glColor3f(1,1,1);
	void *font = GLUT_BITMAP_HELVETICA_12;
	renderBitmapString(10, 40, font, "-use left mouse button to drag red/green vectors and to orbit scene");
	renderBitmapString(10, 20, font, "-the blue vector should always be orthogonal to the red and green vectors");*/



	glutSwapBuffers();

}

void reshape(GLint width, GLint height) {
	g_viewportWidth = width;
	g_viewportHeight = height;

	// redraw viewport
	glutPostRedisplay();	
}


vector vectorAtDepth(double depth, const vector &v2d) {
	if ((GLpick::g_frustumWidth <= 0) || (GLpick::g_frustumHeight <= 0) ||
		(GLpick::g_frustumNear <= 0) || (GLpick::g_frustumFar <= 0)) {
		return vector();
	}

	return _vector((depth * (double)v2d.e1() * GLpick::g_frustumWidth) / (g_viewportWidth * GLpick::g_frustumNear) * e1 + 
		(depth * (double)v2d.e2() * GLpick::g_frustumHeight) / (g_viewportHeight * GLpick::g_frustumNear) * e2);
}


e3ga::vector mousePosToVector(int x, int y) {
	x -= g_viewportWidth / 2;
	y -= g_viewportHeight / 2;
	return e3ga::_vector((float)x * e3ga::e1 - (float)y * e3ga::e2);
}

void MouseButton(int button, int state, int x, int y) {
	g_rotateModel = false;

	g_prevMousePos = mousePosToVector(x, y);

	g_dragObject = pick(x, g_viewportHeight - y, display, &g_dragDistance);
	if (g_dragObject < 0) {
		e3ga::vector mousePos = mousePosToVector(x, y);
		g_rotateModel = true;
		if ((_Float(norm_e(mousePos)) / _Float(norm_e(g_viewportWidth * e1 + g_viewportHeight * e2))) < 0.2)
			g_rotateModelOutOfPlane = true;
		else g_rotateModelOutOfPlane = false;
	}
}

void MouseMotion(int x, int y) {
	// get mouse position, motion 
	e3ga::vector mousePos = mousePosToVector(x, y);
	e3ga::vector motion = _vector(mousePos - g_prevMousePos);
	if (g_rotateModel) {
		// update rotor
		if (g_rotateModelOutOfPlane)
			g_modelRotor = _rotor(e3ga::exp(0.005f * (motion ^ e3ga::e3)) * g_modelRotor);
		else g_modelRotor = _rotor(e3ga::exp(0.00001f * (motion ^ mousePos)) * g_modelRotor);		
	}
	else if ((g_dragObject >= 1) && (g_dragObject <= 2)) {
		// add motion to vector:
		vector T = vectorAtDepth(g_dragDistance, motion);
		T = _vector(inverse(g_modelRotor) * T * g_modelRotor);
		g_vectors[g_dragObject-1] += T;
	}

	// remember mouse pos for next motion:
	g_prevMousePos = mousePos;
		
		// redraw viewport
		glutPostRedisplay();	

}

void Keyboard(unsigned char key, int x, int y) {

}

int main(int argc, char*argv[]) {
	// NO profiling for Gaigen 2:
	// e3ga::g2Profiling::init();

	std::vector<e3ga::vector> IF(3);
	IF[0] = _vector(e1 + e2);
	IF[1] = _vector(e1 - e3);
	IF[2] = _vector(0.1 * e1 - 0.1 * e3 + 0.1 * e2);
	std::vector<e3ga::vector> RF;

	try {
		reciprocalFrame(IF, RF);
	} catch(const std::string &str) {
		printf("Wha: %s\n", str.c_str());
	}

	for (int i = 0; i < IF.size(); i++) {
		printf("1: %s\n", (IF[i] << RF[i]).c_str());
		for (int j = 0; j < IF.size(); j++) {
			if (i == j) continue;
			printf("0: %s\n", (IF[i] << RF[j]).c_str());

		}
	}
	return 0;


	// GLUT Window Initialization:
	glutInit (&argc, argv);
	glutInitWindowSize(g_viewportWidth, g_viewportHeight);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(WINDOW_TITLE);

	// Register callbacks:
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);

	glutMainLoop();

	return 0;
}
