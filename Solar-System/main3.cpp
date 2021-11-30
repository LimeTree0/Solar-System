#include<GLUT/freeglut.h>
#include<iostream>
#include"planet.h"
#include"imageloader.h"
#include "skybox.h"
#include "imgui.h"
#include"imgui_impl_glut.h"
#include"imgui_impl_opengl3.h"

#define SUN 0
#define MERCURY 1
#define VENUS 2
#define EARTH 3
#define MOON 4
#define MARS 5
#define JUPITER 6
#define SATURN 7
#define URANOS 8
#define NEPTUNE 9

float cameraX = 50, cameraY = 10, cameraZ = 20, viewX = 0, viewY = 0, viewZ = 0;

Planet planet[10];

//The id of the texture
GLuint starTextureId, sunTextureId, mecuryTextureId, venusTextureId, earthTextureId, moonTextureId, marsTextureId, phobosTextureId, jupiterTextureId, saturnTextureId, uranosTextureId, neptuneTextureId;

//GLUquadric quad;
GLUquadricObj* quad;

SkyBox skybox;

// Our state
static bool show_planetInfo_window = false;
static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

int planetNumber = 0;
GLboolean planetSelected = false;

void my_display_code()
{
    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    /*if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);*/

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    {

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("camera move : W, A, S, D, T, G");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Show planet information", &show_planetInfo_window);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

        if (ImGui::Button("FREE")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = false;
            cameraX = 50, cameraY = 10, cameraZ = 20, viewX = 0, viewY = 0, viewZ = 0;
        }
        if (ImGui::Button("SUN")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = SUN;
        }
        if (ImGui::Button("MERCURY")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = MERCURY;
        }
        if (ImGui::Button("VENUS")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = VENUS;
        }
        if (ImGui::Button("EARTH")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = EARTH;
        }
        if (ImGui::Button("MARS")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = MARS;
        }
        if (ImGui::Button("JUPITER")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = JUPITER;
        }
        if (ImGui::Button("SATURN")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = SATURN;
        }
        if (ImGui::Button("URANOS")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = URANOS;
        }
        if (ImGui::Button("NEPTUNE")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
            planetSelected = true;
            planetNumber = NEPTUNE;
        }
        ImGui::End();
    }

    // 3. Show another simple window.
    if (show_planetInfo_window)
    {
        ImGui::Begin("Planet Information Window", &show_planetInfo_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        if (planetNumber == SUN) {
            ImGui::Text("name : SUN");
            ImGui::Text("Mean distance 1.496 x 10^8km");
            ImGui::Text("Visual -26.74");
            ImGui::Text("Absolute : 4.83");
            ImGui::Text("Equatorial: 695,700km");
            ImGui::Text("radius : 696,342km");
            ImGui::Text("The Sun is the star at the center of the Solar System.\n It is a nearly perfect ball of hot plasma, heated to \nincandescence by nuclear fusion reactions in its core, radiating the energy mainly\n as visible light, ultraviolet light, and infrared radiation.\nThe Sun is the star at the center of the Solar System.It is a nearly perfect ball of hot plasma, [18][19] heated to incandescence by nuclear fusion reactions in its core, radiating the energy mainly as visible light, ultraviolet light, and infrared radiation.It is by far the most important source of energy for life on Earth.Its diameter is about 1.39 million kilometres(864, 000 miles), or 109 times that of Earth.Its mass is about 330, 000 times that of Earth, and it accounts for about 99.86 % of the total mass of the Solar System.[20] Roughly three quarters of the Sun's mass consists of hydrogen (~73%); the rest is mostly helium (~25%), with much smaller quantities of heavier elements, including oxygen, carbon, neon and iron.[21]It is by far the most important source of energy for life on Earth.\nIts diameter is about 1.39 million kilometres (864,000 miles), or 109 times that of Earth.\nIts mass is about 330,000 times that of Earth, and it accounts for about 99.86% of the total mass of the Solar System.\n Roughly three quarters of the Sun's mass consists of hydrogen (~73%); the rest is mostly helium (~25%),\nwith much smaller quantities of heavier elements, including oxygen, carbon, neon and iron.");
        }
        if (planetNumber == MERCURY) {
            ImGui::Text("name : MERCURY");
            ImGui::Text("Mean radius : 2,439.7km");
            ImGui::Text("surface area : 74,800,000km^2");
            ImGui::Text("mass : 3.285 x 10^23kg");
            ImGui::Text("period of revolution : 88Day");
            ImGui::Text("Rotation period : 55Days 15Hours 30Minutes");
            ImGui::Text("distance from sun : 57,910,000km");
            ImGui::Text("mean density : 5.43g/cm^3");
            ImGui::Text("Mercury is the smallest planet in the Solar System and the closest to the Sun.\nIts orbit around the Sun takes 87.97 Earth days, the shortest of all the Sun's \nplanets.It is named after the Roman god Mercurius(Mercury), god of commerce, \nmessenger of the gods, and mediator between gods and mortals, corresponding\nto the Greek god Hermes(Ἑρμῆς).Like Venus, Mercury orbits the Sun within Earth's\norbit as an inferior planet, and its apparent distance from the Sun as viewed from\nEarth never exceeds 28°.This proximity to the Sun means the planet can only be seen\nnear the western horizon after sunset or the eastern horizon before sunrise, usually\nin twilight.At this time, it may appear as a bright star - like object, but is more difficult\nto observe than Venus.From Earth, the planet telescopically displays the complete range\nof phases, similar to Venus and the Moon, which recurs over its synodic period of\napproximately 116 days.");
        }
        if (planetNumber == VENUS) {
            ImGui::Text("name : VENUS");
            ImGui::Text("Mean radius : 6,051.8km");
            ImGui::Text("surface area : 460,200,000km^2");
            ImGui::Text("mass : 4.867 x 10^24kg");
            ImGui::Text("period of revolution : 225Day");
            ImGui::Text("Rotation period : 116Days 18Hours 0Minutes");
            ImGui::Text("distance from sun : 108,200,000km");
            ImGui::Text("mean density : 5.243g/cm^3");
            ImGui::Text("Venus is the second planet from the Sun. It is named after the Roman goddess of love and beauty.\n As the brightest natural object in Earth's night sky after the Moon, Venus can cast shadows and can be,\n on rare occasions, visible to the naked eye in broad daylight. Venus lies within Earth's orbit, and so never\n appears to venture far from the Sun, either setting in the west just after dusk or rising in the east a little\n while before dawn. Venus orbits the Sun every 224.7 Earth days. It has a synodic day length of 117 Earth\n days and a sidereal rotation period of 243 Earth days. As a consequence, it takes longer to rotate about\n its axis than any other planet in the Solar System, and does so in the opposite direction to all but Uranus.\n This means the Sun rises in the west and sets in the east.[21] Venus does not have any moons, a distinction\n it shares only with Mercury among the planets in the Solar System.\n");
        }
        if (planetNumber == EARTH) {
            ImGui::Text("name : EARTH");
            ImGui::Text("Mean radius : 6,371.0kmkm");
            ImGui::Text("surface area : 510,065,623km^2");
            ImGui::Text("mass : 5.97237 x 10^24kg");
            ImGui::Text("period of revolution : 365.3Day");
            ImGui::Text("Rotation period : 23Hours 56Minutes");
            ImGui::Text("distance from sun : 150,000,000km");
            ImGui::Text("mean density : 5.514g/cm^3");
            ImGui::Text("Earth is the third planet from the Sun and the only astronomical object\n known to harbour and support life. 29.2% of Earth's surface is land \nconsisting of continents and islands. The remaining 70.8% is covered \nwith water, mostly by oceans, seas, gulfs, and other salt-water bodies, \nbut also by lakes, rivers, and other freshwater, which together constitute \nthe hydrosphere. Much of Earth's polar regions are covered in ice. Earth's \nouter layer is divided into several rigid tectonic plates[list] that migrate \nacross the surface over many millions of years, while its interior remains \nactive with a solid iron inner core, a liquid outer core that generates Earth's \nmagnetic field, and a convective mantle that drives plate tectonics.");
        }
        if (planetNumber == MARS) {
            ImGui::Text("name : MARS");
            ImGui::Text("Mean radius : 3,389.5km");
            ImGui::Text("surface area : 144,800,000km^2");
            ImGui::Text("mass : 6.4171 x 10^23kg");
            ImGui::Text("period of revolution : 687Day");
            ImGui::Text("Rotation period : 1Days 0Hours 37Minutes");
            ImGui::Text("distance from sun : 27,390,000km");
            ImGui::Text("mean density : 3.93g/cm^3");
            ImGui::Text("Mars is the fourth planet from the Sun and the second-smallest planet in the Solar System,\n being larger than only Mercury. In English, Mars carries the name of the Roman god of war\n and is often referred to as the Red Planet. The latter refers to the effect of the iron\n oxide prevalent on Mars's surface, which gives it a reddish appearance (as shown), that is\n distinctive among the astronomical bodies visible to the naked eye. Mars is a terrestrial \nplanet with a thin atmosphere, with surface features reminiscent of the impact craters of the Moon\n and the valleys, deserts and polar ice caps of Earth.");
        }
        if (planetNumber == JUPITER) {
            ImGui::Text("name : JUPITER");
            ImGui::Text("Mean radius : 69,911km");
            ImGui::Text("surface area : 6.142 x 10^10km^2");
            ImGui::Text("mass : 1.898 x 10^27kg");
            ImGui::Text("period of revolution : 12Years");
            ImGui::Text("Rotation period : 0Days 9Hours 56Minutes");
            ImGui::Text("distance from sun : 777,920,000km");
            ImGui::Text("mean density : 1326kg/m^3");
            ImGui::Text("Jupiter is the fifth planet from the Sun and the largest in the Solar System.\n It is a gas giant with a mass more than two and a half times that of\n all the other planets in the Solar System combined, but slightly less than \none-thousandth the mass of the Sun. Jupiter is the third-brightest natural \nobject in the Earth's night sky after the Moon and Venus. It has been observed\n since pre-historic times and is named after the Roman god Jupiter, the king of the gods,\n because of its observed size.");
        }
        if (planetNumber == SATURN) {
            ImGui::Text("name : SATURN");
            ImGui::Text("Mean radius : 58,232km");
            ImGui::Text("surface area : 4.27 x 10^10km^2");
            ImGui::Text("mass : 5.683 x 10^26kg");
            ImGui::Text("period of revolution : 29Years");
            ImGui::Text("Rotation period : 0Days 10Hours 47Minutes");
            ImGui::Text("distance from sun : 1,430,180,000km");
            ImGui::Text("mean density : 0.6873g/cm^3");
            ImGui::Text("Saturn is the sixth planet from the Sun and the second-largest in the Solar System, after Jupiter.\n It is a gas giant with an average radius of about nine and a half times that of Earth.\n It only has one-eighth the average density of Earth; however, with its larger volume,\n Saturn is over 95 times more massive. Saturn is named after the Roman god of wealth and agriculture.\n Its astronomical symbol has been traced back to the Greek Oxyrhynchus Papyri, where it can be seen to\n be a Greek kappa-rho with a cross-bar, as an abbreviation for Cronos, the Greek name for the planet.\nIt later came to look like a lower-case Greek eta, with the cross added at the top in the 16th century.\nThe Romans named the seventh day of the week Saturday.");
        }
        if (planetNumber == URANOS) {
            ImGui::Text("name : URANUS");
            ImGui::Text("Mean radius : 25,362km");
            ImGui::Text("surface area : 8.083 x 10^9km^2");
            ImGui::Text("mass : 8.681 x 10^25kg");
            ImGui::Text("period of revolution : 84Years");
            ImGui::Text("Rotation period : 0Days 17Hours 14Minutes");
            ImGui::Text("distance from sun : 2,869,330,000km");
            ImGui::Text("mean density : 1.27g/cm^3");
            ImGui::Text("Uranus is the seventh planet from the Sun. Its name is a reference to the Greek god of the sky,\n Uranus, who, according to Greek mythology, was the great-grandfather of Ares (Mars),\n grandfather of Zeus (Jupiter) and father of Cronus (Saturn). It has the third-largest planetary radius\n and fourth-largest planetary mass in the Solar System. Uranus is similar in composition to Neptune,\n and both have bulk chemical compositions which differ from that of the larger gas giants Jupiter and Saturn.\n For this reason, scientists often classify Uranus and Neptune as ice giants to distinguish\n them from the other giant planets. Uranus's atmosphere is similar to Jupiter's and Saturn's in its primary\n composition of hydrogen and helium, but it contains more ices such as water, ammonia, and methane,\n along with traces of other hydrocarbons. It has the coldest planetary atmosphere in the Solar System,\n with a minimum temperature of 49 K, and has a complex, layered cloud structure with water thought \nto make ulowest clouds and methane the uppermost layer of clouds. The interior of Uranus is mainly\ncomposed of ices and rock.");
        }
        if (planetNumber == NEPTUNE) {
            ImGui::Text("name : NEPTUNE");
            ImGui::Text("Mean radius : 24,622km");
            ImGui::Text("surface area : 7.618 x10^9km^2");
            ImGui::Text("mass : 1.024 x 10^26kg");
            ImGui::Text("period of revolution : 165Years");
            ImGui::Text("Rotation period : 0Days 16Hours 6Minutes");
            ImGui::Text("distance from sun : 4,507,450,000km");
            ImGui::Text("mean density : 1.638g/cm^3");
            ImGui::Text("Neptune is the eighth and farthest-known Solar planet from the Sun. In the Solar System,\n it is the fourth-largest planet by diameter, the third-most-massive planet, and the densest giant planet.\n It is 17 times the mass of Earth, slightly more massive than its near-twin Uranus. Neptune is denser and\n physically smaller than Uranus because its greater mass causes more gravitational compression of its atmosphere.\n The planet orbits the Sun once every 164.8 years at an average distance of 30.1 AU (4.5 billion km; 2.8 billion mi).\n It is named after the Roman god of the sea and has the astronomical symbol, a stylised version of the god Neptune's\n trident or the Greek letter psi.");
        }
        
        if (ImGui::Button("Close Me"))
            show_planetInfo_window = false;
        ImGui::End();
    }
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {

    GLuint textureId;

    glGenTextures(1, &textureId); //Make room for our texture

    glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit

    //Map the image to the texture

    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D

        0,                            //0 for now

        GL_RGB,                       //Format OpenGL uses for image

        image->width, image->height,  //Width and height

        0,                            //The border of the image

        GL_RGB, //GL_RGB, because pixels are stored in RGB format

        GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored

                          //as unsigned numbers

        image->pixels);               //The actual pixel data

    return textureId; //Returns the id of the texture

}

void initRendering() {

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);

    glEnable(GL_LIGHT0);

    glEnable(GL_NORMALIZE);

    glEnable(GL_COLOR_MATERIAL);

    quad = gluNewQuadric();

    Image* starImage = loadBMP("texture/star.bmp");
    Image* sunImage = loadBMP("texture/sun.bmp");
    Image* mercuryImage = loadBMP("texture/mercury.bmp");
    Image* venusImage = loadBMP("texture/venus.bmp");
    Image* earthImage = loadBMP("texture/earth.bmp");
    Image* moonImage = loadBMP("texture/moon.bmp");
    Image* marsImage = loadBMP("texture/mars.bmp");
    Image* phobosImage = loadBMP("texture/phobos.bmp");
    Image* jupiterImage = loadBMP("texture/jupiter.bmp");
    Image* saturnImage = loadBMP("texture/saturn.bmp");
    Image* uranosImage = loadBMP("texture/uranos.bmp");
    Image* neptuneImage = loadBMP("texture/neptune.bmp");

    starTextureId = loadTexture(starImage);
    sunTextureId = loadTexture(sunImage);
    mecuryTextureId = loadTexture(mercuryImage);
    venusTextureId = loadTexture(venusImage);
    earthTextureId = loadTexture(earthImage);
    moonTextureId = loadTexture(moonImage);
    marsTextureId = loadTexture(marsImage);
    phobosTextureId = loadTexture(phobosImage);
    jupiterTextureId = loadTexture(jupiterImage);
    saturnTextureId = loadTexture(saturnImage);
    uranosTextureId = loadTexture(uranosImage);
    neptuneTextureId = loadTexture(neptuneImage);

    std::cout << starTextureId << std::endl;
    std::cout << sunTextureId<< std::endl;
    std::cout << mecuryTextureId << std::endl;
    std::cout << venusTextureId << std::endl;
    std::cout << earthTextureId << std::endl;
    std::cout << moonTextureId << std::endl;
    std::cout << marsTextureId << std::endl;
    std::cout << phobosTextureId << std::endl;
    std::cout << jupiterTextureId << std::endl;
    std::cout << saturnTextureId << std::endl;
    std::cout << uranosTextureId << std::endl;
    std::cout << neptuneTextureId << std::endl;


    delete starImage, sunImage, mercuryImage, venusImage, earthImage, moonImage, marsImage, phobosImage, jupiterImage, saturnImage, uranosImage, neptuneImage;

}

void reShapeDisplay(int w, int h) {

    glViewport(0, 0, w, h);

    ImGui_ImplGLUT_ReshapeFunc(w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(45.0, (float)w / (float)h, 1.0, 500.0);
    glFrustum(-10, 10, -10, 10, 0, 500);
}

void mykeyboard(unsigned char key, int x, int y) {
    if (key == 'D' || key == 'd') {
        cameraX += 1;
        std::cout << "X UP" << std::endl;
    }
    else if (key == 'A' || key == 'a') {
        cameraX -= 1;
        std::cout << "X DOWN" << std::endl;
    }
    else if (key == 'W' || key == 'w') {
        cameraY += 1;
        std::cout << "Y UP" << std::endl;
    }
    else if (key == 'S' || key == 's') {
        cameraY -= 1;
        std::cout << "Y DOWN" << std::endl;
    }
    else if (key == 'T' || key == 't') {
        cameraZ += 1;
        std::cout << "Z UP" << std::endl;
    }
    else if (key == 'G' || key == 'g') {
        cameraZ -= 1;
        std::cout << "Z DOWN" << std::endl;
    }
}

void mySpecialKeyboard(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        viewX += 1;
        std::cout << "X UP" << std::endl;
    }
    else if (key == GLUT_KEY_LEFT) {
        viewX -= 1;
        std::cout << "X DOWN" << std::endl;
    }
    else if (key == GLUT_KEY_UP) {
        viewY += 1;
        std::cout << "Y UP" << std::endl;
    }
    else if (key == GLUT_KEY_DOWN) {
        viewY -= 1;
        std::cout << "Y DOWN" << std::endl;
    }
    else if (key == GLUT_KEY_CTRL_R) {
        viewZ += 1;
        std::cout << "Z UP" << std::endl;
    }
    else if (key == GLUT_KEY_CTRL_L) {
        viewZ -= 1;
        std::cout << "Z DOWN" << std::endl;
    }
}

void InitLight() {
	GLfloat light0_ambient[] = { 0.1,0.1,0.1,1.0 };
	GLfloat light0_diffuse[] = { 0.8,0.7,0.6,1.0 };
	GLfloat light0_specular[] = { 0.0,0.0,0.0,1.0 };

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
}

void planetSetting() {
    skybox.skyBoxTextureSetting(starTextureId);
    planet[SUN].setPlanetInfo(quad, 5, 0, 0.0, 0, sunTextureId);
    planet[MERCURY].setPlanetInfo(quad, 0.4, 7, 1, 0.7, mecuryTextureId);
    planet[VENUS].setPlanetInfo(quad, 0.5, 9, 0.7, 0.5, venusTextureId);
    planet[EARTH].setPlanetInfo(quad, 0.6, 12, 0.5, 0.3, earthTextureId);
    planet[MOON].setPlanetInfo(quad, 0.1, 1, 0.3, 0.1, moonTextureId);
    planet[MARS].setPlanetInfo(quad, 0.5, 15, 0.3, 0.1, marsTextureId);
    planet[JUPITER].setPlanetInfo(quad, 2, 20, 1, 0.01, jupiterTextureId);
    planet[SATURN].setPlanetInfo(quad, 1.6, 25, 0.2, 0.2, jupiterTextureId, 0.5);
    planet[URANOS].setPlanetInfo(quad, 1.5, 32, 0.3, 0.5, uranosTextureId, 0.2,90);
    planet[NEPTUNE].setPlanetInfo(quad, 1.3, 40, 0.5, 0.5, neptuneTextureId,0.1,-45);
}

void MyDisplay() {
    GLfloat LightPosition[] = { 0.0,0.0,0.0,1.0 };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    if (planetSelected) {
        viewX = planet[planetNumber].GetPosition_X(); 
        viewZ = planet[planetNumber].GetPosition_Z(); 
        cameraX = viewX + planet[planetNumber].GetRadius() + 2; 
        cameraZ = viewZ + planet[planetNumber].GetRadius() + 2;
    }

    gluLookAt(cameraX, cameraY, cameraZ, viewX, viewY, viewZ, 0, 1, 0);
    glPushMatrix();

    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);


    // draw sun
    glDisable(GL_LIGHTING);

    planet[SUN].drawPlanet();
    
    glEnable(GL_LIGHTING);

    // draw mercury
    glPushMatrix();
    planet[MERCURY].drawOrbit();
    planet[MERCURY].drawPlanet();
    glPopMatrix();


    //draw venus
    glPushMatrix();
    planet[VENUS].drawOrbit();
    planet[VENUS].drawPlanet();
    glPopMatrix();


    //draw earth
    glPushMatrix();
    planet[EARTH].drawOrbit();
    planet[EARTH].drawPlanet();

    //draw moon
    planet[MOON].drawOrbit();
    planet[MOON].drawPlanet();
    glPopMatrix();

    //draw mars
    glPushMatrix();
    planet[MARS].drawOrbit();
    planet[MARS].drawPlanet();
    glPopMatrix();


    //draw jupiter
    glPushMatrix();
    planet[JUPITER].drawOrbit();
    planet[JUPITER].drawPlanet();
    glPopMatrix();

    //draw saturn
    glPushMatrix();
    planet[SATURN].drawOrbit();
    planet[SATURN].drawPlanet();
    glPopMatrix();

    //draw uranos
    glPushMatrix();
    planet[URANOS].drawOrbit();
    planet[URANOS].drawPlanet();
    glPopMatrix();

    //draw neptune
    glPushMatrix();
    planet[NEPTUNE].drawOrbit();
    planet[NEPTUNE].drawPlanet();
    glPopMatrix();

    glPopMatrix();

    skybox.draw();

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGLUT_NewFrame();

    my_display_code();

    // Rendering
    ImGui::Render();
    ImGuiIO& io = ImGui::GetIO();
    glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
    /*glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);*/
    //glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound, but prefer using the GL3+ code.
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glutPostRedisplay();

    glutSwapBuffers();

    glFlush();

}


int main(int argc, char** argv) {

    glutInit(&argc, argv);

#ifdef __FREEGLUT_EXT_H__
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowSize(1280, 720);

    glutCreateWindow("Textures-codeincodeblock.blogspot.com");

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGLUT_Init();
    ImGui_ImplGLUT_InstallFuncs();
    ImGui_ImplOpenGL3_Init();

    initRendering();
    InitLight();
    planetSetting();

    glutDisplayFunc(MyDisplay);

    glutReshapeFunc(reShapeDisplay);

    glutKeyboardFunc(mykeyboard);

    glutMainLoop();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();

    return 0;

}