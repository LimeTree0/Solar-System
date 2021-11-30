#ifndef SKYBOX_H
#define SKYBOX_H

#include<iostream>
#include<glut/freeglut.h>
#include"imageloader.h"

class SkyBox {
public:
	void draw();
	void skyBoxTextureSetting(GLuint textures);
private:
	typedef unsigned int uint;
	typedef const char* pcStr;
	int texture;
};
#endif // !SKYBOX_H
