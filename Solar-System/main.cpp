//#include<GLUT/freeglut.h>
//#include<GLUT/freeglut_ext.h>
//#include<GLUT/freeglut_std.h>
//#include<gl/GLU.h>
//#include<gl/GL.h>
//#include"planet.h"
//
//
//static float Day = 0, Time = 0;
//Planet sun, earth, moon;//, mercury, venus, Earth, Mars, jupiter, saturn, uranos, neptune;
//
//GLuint loadTexture(Image* image) {
//
//    GLuint textureId;
//
//    glGenTextures(1, &textureId); //Make room for our texture
//
//    glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
//
//    //Map the image to the texture
//
//    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
//
//        0,                            //0 for now
//
//        GL_RGB,                       //Format OpenGL uses for image
//
//        image->width, image->height,  //Width and height
//
//        0,                            //The border of the image
//
//        GL_RGB, //GL_RGB, because pixels are stored in RGB format
//
//        GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
//
//                          //as unsigned numbers
//        image->pixels);               //The actual pixel data
//    return textureId; //Returns the id of the texture
//}
//
//GLuint sunTexture, earthTexture, moonTexture; //The id of the texture
//
//
//void inIt() {
//
//	glEnable(GL_DEPTH_TEST);
//	glMatrixMode(GL_PROJECTION);
//	glEnable(GL_NORMALIZE);
//	glEnable(GL_COLOR_MATERIAL);
//	glMatrixMode(GL_MODELVIEW);
//
//	//glEnable(GL_LIGHTING);
//
//	//glEnable(GL_LIGHT0);
//
//	glEnable(GL_NORMALIZE);
//
//	glEnable(GL_COLOR_MATERIAL);
//
//	Image* image[3];
//
//	image[0] = loadBMP("earth.bmp");
//	image[1] = loadBMP("earth.bmp");
//	image[2] = loadBMP("moon.bmp");
//	sunTexture = loadTexture(image[0]);
//	earthTexture = loadTexture(image[1]);
//	moonTexture = loadTexture(image[2]);
//
//	for (int i = 0; i < 3; i++)
//		delete image[i];
//
//	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
//}
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluLookAt(10,0,0, 1, 1, 1, 0, 1, 0);
//		glutWireTeapot(0.5);
//		GLUquadricObj *quadric = gluNewQuadric();
//		gluSphere(quadric, 1.0, 20, 20);
//		glFlush();
//	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	//glLoadIdentity();
//	//gluLookAt(10, 0, 0, 1, 1, 1, 0, 1, 0);
//	//GLUquadricObj* quadricObj = gluNewQuadric();
//	//glLoadIdentity();
//	//glTranslatef(0.0f, 0.0f, -1.5f);
//	//glRotatef(-90, 1.0, 0.0, 0.0);
//	//glRotatef(Day, 0.0, 0.0, 1.0);
//	///*glEnable(GL_TEXTURE_2D);
//	//glBindTexture(GL_TEXTURE_2D, earthTexture);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);*/
//	//gluQuadricTexture(quadricObj, 1);
//	//gluSphere(quadricObj, 1, 20.0f, 20.0f);
//	///*glDisable(GL_TEXTURE_2D);*/
//	//glutSwapBuffers();
//}
//void timer(int){
//	Day = (Day + 0.5);
//	Time = (Time + 0.1);
//	glutPostRedisplay();
//	glutTimerFunc(1000 / 60, timer, 0);
//}
//
//
//int main(int argc, char**argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Opengl sample drawing");
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glutDisplayFunc(MyDisplay);
//	/*glutTimerFunc(0,timer,0);*/
//	inIt();
//	glutMainLoop();
//	
//}