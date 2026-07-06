#include<GL/freeglut.h>
#include<iostream>
using namespace std;

bool bIsFullScreen = false;

int main(int argc, char* argv[])
{
    //function declarations
    void initialize(void);
    void uninitialize(void);
    void resize(int, int);
    void display(void);
    void keyboard(unsigned char, int, int);
    void mouse(int, int, int, int);

    // code
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scenery by Sakshi");

    initialize();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutCloseFunc(uninitialize);

    glutMainLoop();

    //Flow should not come here
    return(0);
}

void initialize(void)
{
    // code
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void resize(int width, int height)
{
    // code
    if (height <= 0)
        height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    //cout << width << "\n" << height << endl;
}

void display(void)
{
    // code
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Full Scene
    glBegin(GL_QUADS);
    glColor3f(0.36f, 0.36f, 0.66f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glColor3f(0.36f, 0.36f, 0.66f);
    glVertex3f(-1.0f, -1.0f, 0.0f);

    glColor3f(0.36f, 0.36f, 0.66f);
    glVertex3f(1.0f, -1.0f, 0.0f);

    glColor3f(0.36f, 0.36f, 0.66f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glEnd();
    

    // Moon surrounding
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.35f * cos(angle);
        float y = 0.35f * sin(angle);

        glColor4f(1.0f, 0.9f, 0.96f,0.5f);
        glVertex3f(x-0.2f, y+0.3, 0.0f);
    }
    glEnd();

    // Moon
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.3f * cos(angle);
        float y = 0.3f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x-0.2f, y + 0.3, 0.0f);
    }
    glEnd();

    // greenery
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -0.7f, 0.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -0.7f, 0.0f);
    glEnd();

    // 1st Triangle on greenery
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.95f, -0.65f, 0.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -0.7f, 0.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.9f, -0.7f, 0.0f);
    glEnd();

    //2nd triangle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.85f, -0.67f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.9f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.65f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.75f, -0.65f, 0.0f);
    glEnd();

    //3rd triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.35f, -0.63f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.65f, -0.75f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.175f, -0.7f, 0.0f);
    glEnd();

    //4th triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.28f, -0.68f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.175f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.62f, -0.7f, 0.0f);
    glEnd();

    //5th triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.68f, -0.64f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.62f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.82f, -0.7f, 0.0f);
    glEnd();

    //6th triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.94f, -0.675f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.82f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -0.7f, 0.0f);
    glEnd();

    //small tree structure
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.91f, -0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.9f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.85f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.85f, -0.475f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.1f * cos(angle);
        float y = 0.1f * sin(angle);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x-0.95f, y-0.45f, 0.0f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.15f * cos(angle);
        float y = 0.15f * sin(angle);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x-0.9f, y-0.25f, 0.0f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.125f * cos(angle);
        float y = 0.125f * sin(angle);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x-0.8f, y-0.45f, 0.0f);
    }
    glEnd();

    //big tree
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.55f, -0.25f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.55f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.6f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.6f, -0.25f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.1f * cos(angle);
        float y = 0.1f * sin(angle);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x+0.48f, y-0.25f, 0.0f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.2f * cos(angle);
        float y = 0.2f * sin(angle);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x+0.4f, y-0.085f, 0.0f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.2f * cos(angle);
        float y = 0.2f * sin(angle);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x+0.6f, y+0.05f, 0.0f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.15f * cos(angle);
        float y = 0.15f * sin(angle);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x+0.7f, y-0.25f, 0.0f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.08f * cos(angle);
        float y = 0.08f * sin(angle);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x+0.8f, y-0.1f, 0.0f);
    }
    glEnd();


    //bench
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.15f, -0.55f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.15f, -0.57f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.45f, -0.57f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.45f, -0.55f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.15f, -0.58f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.15f, -0.6f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.45f, -0.6f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.45f, -0.58f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.18f,-0.55f,0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.18f,-0.7f,0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.42f,-0.55f,0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.42f,-0.7f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.18f, -0.62f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.15f, -0.65f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.45f, -0.65f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.42f, -0.62f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.18f, -0.65f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.18f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.19f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.19f, -0.65f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.42f, -0.65f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.42f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.41f, -0.7f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.41f, -0.65f, 0.0f);
    glEnd();

    //clouds
    //middle cloud
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.09f * cos(angle);
        float y = 0.04f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.2, y+0.8, 0.0f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.05f * cos(angle);
        float y = 0.025f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.29f, y+0.78f, 0.0f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.05f * cos(angle);
        float y = 0.025f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.11f, y+0.78f, 0.0f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.07f * cos(angle);
        float y = 0.04f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.82f, y+0.46f, 0.0f);
    }
    glEnd();
    //right cloud
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.1f * cos(angle);
        float y = 0.05f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.78f, y+0.41f, 0.0f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.1f * cos(angle);
        float y = 0.05f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.85f, y+0.42f, 0.0f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.08f * cos(angle);
        float y = 0.06f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x+0.82f, y+0.39f, 0.0f);
    }
    glEnd();
    //left cloud
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.1f * cos(angle);
        float y = 0.07f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x-0.8f, y+0.8f, 0.0f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.08f * cos(angle);
        float y = 0.05f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x-0.75f, y+0.75f, 0.0f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        //angle
        float angle = (float)(i * 3.14 / 180);

        float x = 0.08f * cos(angle);
        float y = 0.05f * sin(angle);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(x-0.87f, y+0.76f, 0.0f);
    }
    glEnd();

    //stars
    //star1
    float a = 0.03f;
    float b = 0.01f;
    float x = -0.6f;
    float y = 0.9f;
    // 1ST TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //2ND TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glEnd();
    //3RD TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //4TH TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glEnd();
    //star2
    a = 0.03f;
    b = 0.01f;
    x = 0.9f;
    y = 0.7f;
    // 1ST TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //2ND TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glEnd();
    //3RD TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //4TH TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glEnd();
    
    //star3
    a = 0.02f;
    b = 0.005f;
    x = -0.5f;
    y = 0.8f;
    // 1ST TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //2ND TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glEnd();
    //3RD TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //4TH TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glEnd();

    //star4
    a = 0.02f;
    b = 0.005f;
    x = -0.8f;
    y = 0.6f;
    // 1ST TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //2ND TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glEnd();
    //3RD TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //4TH TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glEnd();

    //star5
    a = 0.04f;
    b = 0.01f;
    x = 0.4f;
    y = 0.5f;
    // 1ST TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //2ND TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glEnd();
    //3RD TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0*b+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*a+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(b+x, 0.0f+y, 0.0f);
    glEnd();
    //4TH TRIANGLE
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, -1.0*b+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(a+x, 0.0f+y, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f+x, b+y, 0.0f);
    glEnd();

    //birds
    //bird1
    a = 0.04f;   // wider wings
    b = 0.025f;  // slight upward tilt
    x = -0.3f;
    y = 0.7f;
    // make lines thicker
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    // left wing
    glVertex2f(x, y);
    glVertex2f(x - a, y + b);
    // right wing
    glVertex2f(x, y);
    glVertex2f(x + a, y + b);
    glEnd();

    //bird2
    a = 0.04f;   // wider wings
    b = 0.025f;  // slight upward tilt
    x = 0.7f;
    y = 0.6f;
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    // left wing
    glVertex2f(x, y);
    glVertex2f(x - a, y + b);
    // right wing
    glVertex2f(x, y);
    glVertex2f(x + a, y + b);
    glEnd();

    //bird3
    a = 0.03f;   // wider wings
    b = 0.015f;  // slight upward tilt
    x = -0.5f;
    y = 0.6f;
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    // left wing
    glVertex2f(x, y);
    glVertex2f(x - a, y + b);
    // right wing
    glVertex2f(x, y);
    glVertex2f(x + a, y + b);
    glEnd();

    //bird4
    a = 0.03f;   // wider wings
    b = 0.015f;  // slight upward tilt
    x = 0.4f;
    y = 0.9f;
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    // left wing
    glVertex2f(x, y);
    glVertex2f(x - a, y + b);
    // right wing
    glVertex2f(x, y);
    glVertex2f(x + a, y + b);
    glEnd();

    //bird5
    a = 0.03f;   // wider wings
    b = 0.015f;  // slight upward tilt
    x = -0.9f;
    y = 0.5f;
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    // left wing
    glVertex2f(x, y);
    glVertex2f(x - a, y + b);
    // right wing
    glVertex2f(x, y);
    glVertex2f(x + a, y + b);
    glEnd();



    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    // code
    switch (key)
    {
    case 27:
        glutLeaveMainLoop();
        break;
    case 'F':
    case 'f':
        if (bIsFullScreen == false)
        {
            glutFullScreen();
            bIsFullScreen = true;
        }
        else
        {
            glutLeaveFullScreen();
            bIsFullScreen = false;
        }
        break;
    default:
        break;
    }
}

void mouse(int button, int state, int x, int y)
{
    // code
    switch (button)
    {
    case GLUT_RIGHT_BUTTON:
        glutLeaveMainLoop();
        break;
    default:
        break;
    }
}

void uninitialize(void)
{
    // code
}

/*
cl.exe /c /EHsc /I C:\freeglut\include project.cpp


link.exe project.obj /LIBPATH:C:\freeglut\lib\x64 freeglut.lib /SUBSYSTEM:CONSOLE

project.exe
*/