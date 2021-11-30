//#include<GLUT/freeglut.h>
//#include<iostream>
//#include"planet.h"
//#include"imageloader.h"
//#include "skybox.h"
//#include "imgui.h"
//#include"imgui_impl_glut.h"
//#include"imgui_impl_opengl3.h"
//float cameraX = 50, cameraY = 10, cameraZ = 20, viewX = 0, viewY = 0, viewZ = 0;
//
//Planet sun,mercury,venus,earth,moon,mars,phobos,jupiter,saturn,uranos,neptune;
//
////The id of the texture
//GLuint starTextureId, sunTextureId, mecuryTextureId, venusTextureId, earthTextureId, moonTextureId, marsTextureId, phobosTextureId, jupiterTextureId, saturnTextureId, uranosTextureId, neptuneTextureId;
//
////GLUquadric quad;
//GLUquadricObj* quad;
//
//SkyBox skybox;
//
////Makes the image into a texture, and returns the id of the texture
//static bool show_demo_window = true;
//static bool show_another_window = false;
//static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
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
//
//        image->pixels);               //The actual pixel data
//
//    return textureId; //Returns the id of the texture
//
//}
//
//void initRendering() {
//
//    glEnable(GL_DEPTH_TEST);
//
//    glMatrixMode(GL_PROJECTION);
//
//    glEnable(GL_LIGHT0);
//
//    glEnable(GL_NORMALIZE);
//
//    glEnable(GL_COLOR_MATERIAL);
//
//    quad = gluNewQuadric();
//
//    Image* starImage = loadBMP("texture/star.bmp");
//    Image* sunImage = loadBMP("texture/sun.bmp");
//    Image* mercuryImage = loadBMP("texture/mercury.bmp");
//    Image* venusImage = loadBMP("texture/venus.bmp");
//    Image* earthImage = loadBMP("texture/earth.bmp");
//    Image* moonImage = loadBMP("texture/moon.bmp");
//    Image* marsImage = loadBMP("texture/mars.bmp");
//    Image* phobosImage = loadBMP("texture/phobos.bmp");
//    Image* jupiterImage = loadBMP("texture/jupiter.bmp");
//    Image* saturnImage = loadBMP("texture/saturn.bmp");
//    Image* uranosImage = loadBMP("texture/uranos.bmp");
//    Image* neptuneImage = loadBMP("texture/neptune.bmp");
//
//    starTextureId = loadTexture(starImage);
//    sunTextureId = loadTexture(sunImage);
//    mecuryTextureId = loadTexture(mercuryImage);
//    venusTextureId = loadTexture(venusImage);
//    earthTextureId = loadTexture(earthImage);
//    moonTextureId = loadTexture(moonImage);
//    marsTextureId = loadTexture(marsImage);
//    phobosTextureId = loadTexture(phobosImage);
//    jupiterTextureId = loadTexture(jupiterImage);
//    saturnTextureId = loadTexture(saturnImage);
//    uranosTextureId = loadTexture(uranosImage);
//    neptuneTextureId = loadTexture(neptuneImage);
//
//    std::cout << starTextureId << std::endl;
//    std::cout << sunTextureId<< std::endl;
//    std::cout << mecuryTextureId << std::endl;
//    std::cout << venusTextureId << std::endl;
//    std::cout << earthTextureId << std::endl;
//    std::cout << moonTextureId << std::endl;
//    std::cout << marsTextureId << std::endl;
//    std::cout << phobosTextureId << std::endl;
//    std::cout << jupiterTextureId << std::endl;
//    std::cout << saturnTextureId << std::endl;
//    std::cout << uranosTextureId << std::endl;
//    std::cout << neptuneTextureId << std::endl;
//
//
//    delete starImage, sunImage, mercuryImage, venusImage, earthImage, moonImage, marsImage, phobosImage, jupiterImage, saturnImage, uranosImage, neptuneImage;
//
//}
//
//void reShapeDisplay(int w, int h) {
//
//    glViewport(0, 0, w, h);
//
//    glMatrixMode(GL_PROJECTION);
//
//    glLoadIdentity();
//
//    gluPerspective(45.0, (float)w / (float)h, 1.0, 500.0);
//    glFrustum(-10, 10, -10, 10, 0, 500);
//}
//
//void mykeyboard(unsigned char key, int x, int y) {
//    if (key == 'D' || key == 'd') {
//        cameraX += 1;
//        std::cout << "X UP" << std::endl;
//    }
//    else if (key == 'A' || key == 'a') {
//        cameraX -= 1;
//        std::cout << "X DOWN" << std::endl;
//    }
//    else if (key == 'W' || key == 'w') {
//        cameraY += 1;
//        std::cout << "Y UP" << std::endl;
//    }
//    else if (key == 'S' || key == 's') {
//        cameraY -= 1;
//        std::cout << "Y DOWN" << std::endl;
//    }
//    else if (key == 'T' || key == 't') {
//        cameraZ += 1;
//        std::cout << "Z UP" << std::endl;
//    }
//    else if (key == 'G' || key == 'g') {
//        cameraZ -= 1;
//        std::cout << "Z DOWN" << std::endl;
//    }
//    glutPostRedisplay();
//}
//
//void mySpecialKeyboard(int key, int x, int y) {
//    if (key == GLUT_KEY_RIGHT) {
//        viewX += 1;
//        std::cout << "X UP" << std::endl;
//    }
//    else if (key == GLUT_KEY_LEFT) {
//        viewX -= 1;
//        std::cout << "X DOWN" << std::endl;
//    }
//    else if (key == GLUT_KEY_UP) {
//        viewY += 1;
//        std::cout << "Y UP" << std::endl;
//    }
//    else if (key == GLUT_KEY_DOWN) {
//        viewY -= 1;
//        std::cout << "Y DOWN" << std::endl;
//    }
//    else if (key == GLUT_KEY_CTRL_R) {
//        viewZ += 1;
//        std::cout << "Z UP" << std::endl;
//    }
//    else if (key == GLUT_KEY_CTRL_L) {
//        viewZ -= 1;
//        std::cout << "Z DOWN" << std::endl;
//    }
//    glutPostRedisplay();
//}
//
//void InitLight() {
//	GLfloat light0_ambient[] = { 0.1,0.1,0.1,1.0 };
//	GLfloat light0_diffuse[] = { 0.8,0.7,0.6,1.0 };
//	GLfloat light0_specular[] = { 0.0,0.0,0.0,1.0 };
//
//	glShadeModel(GL_SMOOTH);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHT0);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
//}
//
//void planetSetting() {
//    skybox.skyBoxTextureSetting(starTextureId);
//    sun.setPlanetInfo(quad, 5, 0, 0.1, 0, sunTextureId);
//    mercury.setPlanetInfo(quad, 0.4, 7, 1, 0.7, mecuryTextureId);
//    venus.setPlanetInfo(quad, 0.5, 9, 0.7, 0.5, venusTextureId);
//    earth.setPlanetInfo(quad, 0.6, 12, 0.5, 0.3, earthTextureId);
//    moon.setPlanetInfo(quad, 0.1, 1, 0.3, 0.1, moonTextureId);
//    mars.setPlanetInfo(quad, 0.5, 15, 0.3, 0.1, marsTextureId);
//    jupiter.setPlanetInfo(quad, 2, 20, 1, 0.01, jupiterTextureId);
//    saturn.setPlanetInfo(quad, 1.6, 25, 0.2, 0.2, jupiterTextureId, 0.5);
//    uranos.setPlanetInfo(quad, 1.5, 32, 0.3, 0.5, uranosTextureId, 0.2,90);
//    neptune.setPlanetInfo(quad, 1.3, 40, 0.5, 0.5, neptuneTextureId,0.1,-45);
//}
//
//void MyDisplay() {
//    GLfloat LightPosition[] = { 0.0,0.0,0.0,1.0 };
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//
//    glLoadIdentity();
//    gluLookAt(cameraX, cameraY, cameraZ, viewX, viewY, viewZ, 0, 1, 0);
//    glPushMatrix();
//
//    glRotatef(-90, 1.0f, 0.0f, 0.0f);
//    
//    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
//
//
//    // draw sun
//    glDisable(GL_LIGHTING);
//
//    sun.drawPlanet();
//
//    glEnable(GL_LIGHTING);
//
//    // draw mercury
//    glPushMatrix();
//    mercury.drawOrbit();
//    mercury.drawPlanet();
//    glPopMatrix();
//
//
//    //draw venus
//    glPushMatrix();
//    venus.drawOrbit();
//    venus.drawPlanet();
//    glPopMatrix();
//
//
//    //draw earth
//    glPushMatrix();
//    earth.drawOrbit();
//    earth.drawPlanet();
//
//    //draw moon
//    moon.drawOrbit();
//    moon.drawPlanet();
//    glPopMatrix();
//
//    //draw mars
//    glPushMatrix();
//    mars.drawOrbit();
//    mars.drawPlanet();
//    glPopMatrix();
//
//
//    //draw jupiter
//    glPushMatrix();
//    jupiter.drawOrbit();
//    jupiter.drawPlanet();
//    glPopMatrix();
//
//    //draw saturn
//    glPushMatrix();
//    saturn.drawOrbit();
//    saturn.drawPlanet();
//    glPopMatrix();
//
//    //draw uranos
//    glPushMatrix();
//    uranos.drawOrbit();
//    uranos.drawPlanet();
//    glPopMatrix();
//
//    //draw neptune
//    glPushMatrix();
//    neptune.drawOrbit();
//    neptune.drawPlanet();
//    glPopMatrix();
//
//    glPopMatrix();
//
//    skybox.draw();
//
//
//    glutPostRedisplay();
//
//    glutSwapBuffers();
//
//    glFlush();
//
//}
//
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//
//    glutInitWindowSize(800, 800);
//
//    glutCreateWindow("Textures-codeincodeblock.blogspot.com");
//
//    initRendering();
//    InitLight();
//    planetSetting();
//
//    glutDisplayFunc(MyDisplay);
//
//    glutReshapeFunc(reShapeDisplay);
//
//    glutSpecialFunc(mySpecialKeyboard);
//
//    glutKeyboardFunc(mykeyboard);
//
//    glutMainLoop();
//
//    return 0;
//
//}