#include "skybox.h"
#include<iostream>
#include<stdlib.h>
#include<glut/freeglut.h>
#define TEXTURE_SIZE 200

void SkyBox::skyBoxTextureSetting(GLuint texture) {
	SkyBox::texture = texture;
}

void SkyBox::draw() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, SkyBox::texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//앞
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 0.0); glVertex3f(-TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 0.0); glVertex3f(-TEXTURE_SIZE, -TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 1.0); glVertex3f(-TEXTURE_SIZE, -TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 1.0); glVertex3f(-TEXTURE_SIZE, TEXTURE_SIZE, -TEXTURE_SIZE);
	glEnd();

	//뒤
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 0.0); glVertex3f(TEXTURE_SIZE, TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 0.0); glVertex3f(TEXTURE_SIZE, -TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 1.0); glVertex3f(TEXTURE_SIZE, -TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 1.0); glVertex3f(TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_SIZE);
	glEnd();

	////좌
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 0.0); glVertex3f(TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 0.0); glVertex3f(TEXTURE_SIZE, -TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 1.0); glVertex3f(-TEXTURE_SIZE, -TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 1.0); glVertex3f(-TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_SIZE);
	glEnd();

	////우
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 0.0); glVertex3f(TEXTURE_SIZE, TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 0.0); glVertex3f(TEXTURE_SIZE, -TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 1.0); glVertex3f(-TEXTURE_SIZE, -TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 1.0); glVertex3f(-TEXTURE_SIZE, TEXTURE_SIZE, -TEXTURE_SIZE);
	glEnd();

	////위
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 0.0); glVertex3f(TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 0.0); glVertex3f(-TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 1.0); glVertex3f(-TEXTURE_SIZE, TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 1.0); glVertex3f(TEXTURE_SIZE, TEXTURE_SIZE, -TEXTURE_SIZE);
	glEnd();

	////아래
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 0.0); glVertex3f(-TEXTURE_SIZE, -TEXTURE_SIZE, TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 0.0); glVertex3f(-TEXTURE_SIZE, -TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(1.0, 1.0); glVertex3f(TEXTURE_SIZE, -TEXTURE_SIZE, -TEXTURE_SIZE);
	glNormal3f(0.0, 0.0, 1.0); glTexCoord2f(0.0, 1.0); glVertex3f(TEXTURE_SIZE, -TEXTURE_SIZE, TEXTURE_SIZE);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}