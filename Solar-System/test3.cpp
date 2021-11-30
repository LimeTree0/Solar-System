//#include "imgui.h"
//#include "imgui_impl_glut.h"
//#include "imgui_impl_opengl3.h"
//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GLUT/freeglut.h>
//#include "planet.h"
//#endif
//
//#ifdef _MSC_VER
//#pragma warning (disable: 4505) // unreferenced local function has been removed
//#endif
//
//// Our state
//static bool show_demo_window = true;
//static bool show_another_window = false;
//static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//
//void my_display_code()
//{
//    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
//    if (show_demo_window)
//        ImGui::ShowDemoWindow(&show_demo_window);
//
//    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
//    {
//        static float f = 0.0f;
//        static int counter = 0;
//
//        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
//
//        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
//        ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
//        ImGui::Checkbox("Another Window", &show_another_window);
//
//        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
//        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
//
//        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
//            counter++;
//        ImGui::SameLine();
//        ImGui::Text("counter = %d", counter);
//
//        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//        ImGui::End();
//    }
//
//    // 3. Show another simple window.
//    if (show_another_window)
//    {
//        ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
//        ImGui::Text("Hello from another window!");
//        if (ImGui::Button("Close Me"))
//            show_another_window = false;
//        ImGui::End();
//    }
//}
//
//Planet sun;
//
//void glut_display_func()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glutInitDisplayMode(GL_MODELVIEW);
//    glLoadIdentity();
//    sun.drawPlanet();
//    gluLookAt(70, 0, 0, 0, 0, 0, 0, 1, 0);
//
//    // Start the Dear ImGui frame
//    ImGui_ImplOpenGL3_NewFrame();
//    ImGui_ImplGLUT_NewFrame();
//
//    my_display_code();
//
//    // Rendering
//    ImGui::Render();
//    /*ImGuiIO& io = ImGui::GetIO();*/
//    /*glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);*/
//    //glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
//    //glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound, but prefer using the GL3+ code.
//    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//
//    glutSwapBuffers();
//    glutPostRedisplay();
//}
//
//// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
//// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
//// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
//// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
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
//
//int main(int argc, char** argv)
//{
//    sun.setPlanetInfo(gluNewQuadric(), 1, 0, 0.1, 0, 0/*sunTextureId*/);
//    // Create GLUT window
//    glutInit(&argc, argv);
//#ifdef __FREEGLUT_EXT_H__
//    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
//#endif
//    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
//    glutInitWindowSize(1280, 720);
//    glutCreateWindow("Dear ImGui GLUT+OpenGL2 Example");
//
//    // Setup GLUT display function
//    // We will also call ImGui_ImplGLUT_InstallFuncs() to get all the other functions installed for us,
//    // otherwise it is possible to install our own functions and call the imgui_impl_glut.h functions ourselves.
//
//    glutReshapeFunc(reShapeDisplay);
//
//    glutDisplayFunc(glut_display_func);
//    
//
//    // Setup Dear ImGui context
//    IMGUI_CHECKVERSION();
//    ImGui::CreateContext();
//    ImGuiIO& io = ImGui::GetIO(); (void)io;
//    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
//
//    // Setup Dear ImGui style
//    ImGui::StyleColorsDark();
//    //ImGui::StyleColorsClassic();
//
//    // Setup Platform/Renderer backends
//    ImGui_ImplGLUT_Init();
//    ImGui_ImplGLUT_InstallFuncs();
//    ImGui_ImplOpenGL3_Init();
//
//    glutMainLoop();
//
//    // Cleanup
//    ImGui_ImplOpenGL3_Shutdown();
//    ImGui_ImplGLUT_Shutdown();
//    ImGui::DestroyContext();
//
//    return 0;
//}
