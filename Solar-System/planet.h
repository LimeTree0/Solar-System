#ifndef PLANET_H
#define PLANET_H

class Planet
{
private:
	GLuint textureId;
	GLUquadricObj* quadricObj;
	GLfloat distance, rotateAngle = 0, rotateSpeed, revolutionAngle = 0, revolutionSpeed, radius, ringRadius, axis,position_x,position_z;

public:
	void setPlanetInfo(GLUquadricObj* quadricObj, GLfloat radius, GLfloat distance, GLfloat rotateSpeed, GLfloat revolutionSpeed, GLuint textureId, GLfloat ringRadius = 0.0, GLfloat axis = 0.0);
	void drawPlanet();
	void drawOrbit();
	GLfloat GetPosition_X();
	GLfloat GetPosition_Z();
	GLfloat GetRadius();

};


#endif