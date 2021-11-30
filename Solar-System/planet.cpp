#include<GLUT/freeglut.h>
#include"imageloader.h"
#include"planet.h"
#include<math.h>
#define PI 3.141592
void Planet::setPlanetInfo(GLUquadricObj* quadricObj, GLfloat radius, GLfloat distance, GLfloat rotateSpeed, GLfloat revolutionSpeed, GLuint textureId, GLfloat ringRadius, GLfloat axis) {
	Planet::quadricObj = quadricObj;
	Planet::radius = radius;
	Planet::distance = distance;
	Planet::rotateSpeed = rotateSpeed;
	Planet::revolutionSpeed = revolutionSpeed;
	Planet::textureId = textureId;
	Planet::ringRadius = ringRadius;
	Planet::axis = axis;
}

void Planet::drawPlanet() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Planet::textureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//공전
		Planet::revolutionAngle = (Planet::revolutionAngle == 360) ? 0 : Planet::revolutionAngle + Planet::revolutionSpeed;
		glRotatef(Planet::revolutionAngle, 0.0f, 0.0f, 1.0f);
		//기준 행성과의 거리
		glTranslatef(Planet::distance, 0, 0);

		Planet::position_x = Planet::distance * cos(-Planet::revolutionAngle * PI / 180.0);
		Planet::position_z = Planet::distance * sin(-Planet::revolutionAngle * PI / 180.0);


		//자전축
		if (Planet::axis)
			glRotatef(Planet::axis, 0.0f, 1.0f, 0.0f);

		//자전 속도
		Planet::rotateAngle = (Planet::rotateAngle > 360) ? 0 : Planet::rotateAngle + Planet::rotateSpeed;
		glRotatef(Planet::rotateAngle, 0.0f, 0.0f, 1.0f);

		//행성 구현
		gluQuadricTexture(Planet::quadricObj, true);
		gluSphere(Planet::quadricObj, Planet::radius, 20, 20);
		glDisable(GL_TEXTURE_2D);

		if (Planet::ringRadius)
			glutSolidTorus(Planet::ringRadius, Planet::radius + 0.8, 2, 100);
}

GLfloat Planet::GetPosition_X() {
	return Planet::position_x;
}

GLfloat Planet::GetPosition_Z() {
	return Planet::position_z;
}

GLfloat Planet::GetRadius() {
	return Planet::radius;
}

void Planet::drawOrbit() {
	glutSolidTorus(0.07, Planet::distance, 2, 100);
}