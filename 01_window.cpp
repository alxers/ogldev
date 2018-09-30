//#include <GL/freeglut.h>
//
//static void RenderSceneCB()
//{
//    // Clear framebuffer with given color
//    // see glClearColor
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Swap backbuffer and the frontbuffer
//    glutSwapBuffers();
//}
//
//static void InitializeGlutCallbacks()
//{
//    glutDisplayFunc(RenderSceneCB);
//}
//
//int main(int argc, char** argv)
//{
//    // Initialize GLUT
//    glutInit(&argc, argv);
//
//    // Configure GLUT options,
//    // GLUT_DOUBLE - double buffering, GLUT_RGBA - color buffer
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(1024, 768);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Test 1");
//    
//    // Render all in one frame, "main" callback is called by GLUT
//    InitializeGlutCallbacks();
//    
//    // A state changing function that sets the color
//    // that will be used when clearing the framebuffer
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//    // Now pass control to GLUT main loop
//    // In this case it'll only call RenderSceneCb
//    // as it's the only function we registered as display callback
//    glutMainLoop();
//    
//    return 0;
//}
//
