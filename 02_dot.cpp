#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Vector3.h"
#include "Matrix.h"

// Store and handle vertex buffer object
GLunit VBO;

static void RenderSceneCB()
{
    // Clear framebuffer with given color
    // see glClearColor
    glClear(GL_COLOR_BUFFER_BIT);
    
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    // This tells the pipeline how to interpret the data inside the buffer.
    // first param - index of the attribute
    // second -number of components in the attr (3 for x, y, z)
    // third -data type of each component
    // forth - if normalized or not
    // fifth - the number of bytes between two instances of that attr in buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    // Draw the geometry
    glDrawArrays(GL_POINTS, 0, 1);
    
    glDisableVertexAttribArray(0);

    // Swap backbuffer and the frontbuffer
    glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
    Vector3 vertices[1];
    vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
    
    // glGen* functions used for generating object of different types.
    // first param specifies the number of objects
    // second an address of an array of GLunits.
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    // Fill binded object with data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Configure GLUT options,
    // GLUT_DOUBLE - double buffering, GLUT_RGBA - color buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Test 1");
    
    // Render all in one frame, "main" callback is called by GLUT
    InitializeGlutCallbacks();
    
    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }
    
    // A state changing function that sets the color
    // that will be used when clearing the framebuffer
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    CreateVertexBuffer();

    // Now pass control to GLUT main loop
    // In this case it'll only call RenderSceneCb
    // as it's the only function we registered as display callback
    glutMainLoop();
    
    return 0;
}
