//#include<GLUT/freeglut.h>
//#include<GLUT/freeglut_ext.h>
//#include<GLUT/freeglut_std.h>
//#include<gl/GLU.h>
//#include<gl/GL.h>
//#include"planet.h"
//#include"imageloader.h"
//
//float cameraX=0, cameraY=0, cameraZ=20, viewX = 0,viewY = 0,viewZ = 0;
//
//void handleKeypress(unsigned char key, int x, int y) {
//
//    switch (key) {
//
//    case 27: //Escape key
//
//        exit(0);
//
//    }
//
//}
//
//
////Makes the image into a texture, and returns the id of the texture
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
//
//GLuint _textureId; //The id of the textur
//
//GLUquadric* quad;
//
//float rotate;
//
//
////GLUquadricObj quad;
//
//
//void initRendering() {
//
//    glEnable(GL_DEPTH_TEST);
//
//    //glEnable(GL_LIGHTING);
//
//    glEnable(GL_LIGHT0);
//
//    glEnable(GL_NORMALIZE);
//
//    glEnable(GL_COLOR_MATERIAL);
//
//    quad = gluNewQuadric();
//
//
//    Image* image = loadBMP("8k_earth_daymap.bmp");
//
//    _textureId = loadTexture(image);
//
//    std::cout << _textureId << std::endl;
//
//    delete image;
//
//}
//
//
//void handleResize(int w, int h) {
//
//    glViewport(0, 0, w, h);
//
//    glMatrixMode(GL_PROJECTION);
//
//    glLoadIdentity();
//
//    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
//
//    glFrustum(-100, 100, -100, 100, -100, 100);
//}
//
//void mykeyboard(unsigned char key, int x, int y) {
//    if (key == 'D' || key == 'd') {
//        cameraX+= 0.1;
//        std::cout << "X UP" << std::endl;
//    }
//    else if (key == 'A' || key == 'a') {
//        cameraX -= 0.1;
//        std::cout << "X DOWN" << std::endl;
//    }
//    else if (key == 'W' || key == 'w') {
//        cameraY += 0.1;
//        std::cout << "Y UP" << std::endl;
//    }
//    else if (key == 'S' || key == 's') {
//        cameraY -= 0.1;
//        std::cout << "Y DOWN" << std::endl;
//    }
//    else if (key == 'T' || key == 't') {
//        cameraZ += 0.5;
//        std::cout << "Z UP" << std::endl;
//    }
//    else if (key == 'G' || key == 'g') {
//        cameraZ -= 0.5;
//        std::cout << "Z DOWN" << std::endl;
//    }
//    glutPostRedisplay();
//}
//
//void mySpecialKeyboard(int key, int x, int y) {
//    if (key == GLUT_KEY_RIGHT) {
//        cameraX += 0.1;
//        std::cout << "X UP" << std::endl;
//    }
//    else if (key == GLUT_KEY_LEFT) {
//        cameraX -= 0.1;
//        std::cout << "X DOWN" << std::endl;
//    }
//    else if (key == GLUT_KEY_UP) {
//        cameraY += 0.1;
//        std::cout << "Y UP" << std::endl;
//    }
//    else if (key == GLUT_KEY_DOWN) {
//        cameraY -= 0.1;
//        std::cout << "Y DOWN" << std::endl;
//    }
//    else if (key == GLUT_KEY_CTRL_R) {
//        cameraZ += 0.1;
//        std::cout << "Z UP" << std::endl;
//    }
//    else if (key == GLUT_KEY_CTRL_L) {
//        cameraZ -= 0.1;
//        std::cout << "Z DOWN" << std::endl;
//    }
//    glutPostRedisplay();
//}
//
//void drawScene() {
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//    glMatrixMode(GL_MODELVIEW);
//
//    glLoadIdentity();
//    gluLookAt(cameraX, cameraY, cameraZ, viewX, viewY, viewZ, 0, 1, 0);
//
//
//    glEnable(GL_TEXTURE_2D);
//
//    glBindTexture(GL_TEXTURE_2D, _textureId);
//
//
//    //Bottom
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    glRotatef(90, 1.0f, 0.0f, 0.0f);
//
//    glRotatef(rotate, 0.0f, 0.0f, 1.0f);
//
//    gluQuadricTexture(quad, 1);
//
//    gluSphere(quad, 2, 20, 20);
//
//    glTranslatef(10, 0, 0);
//
//    glRotatef(rotate, 0.0f, 0.0f, 1.0f);
//
//    gluSphere(quad, 2, 20, 20);
//
//    glutSwapBuffers();
//
//}
//
//void update(int value)
//
//{
//
//    rotate += 2.0f;
//
//    if (rotate > 360.f)
//
//    {
//
//        rotate -= 360;
//
//    }
//
//    glutPostRedisplay();
//
//    glutTimerFunc(25, update, 0);
//
//}
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//
//    glutInitWindowSize(800, 800);
//
//
//    glutCreateWindow("Textures-codeincodeblock.blogspot.com");
//
//    initRendering();
//
//
//    glutTimerFunc(25, update, 0);
//
//
//    glutDisplayFunc(drawScene);
//
//    glutKeyboardFunc(handleKeypress);
//
//    glutReshapeFunc(handleResize);
//
//    glutSpecialFunc(mySpecialKeyboard);
//    glutKeyboardFunc(mykeyboard);
//
//    glutMainLoop();
//
//    return 0;
//
//}