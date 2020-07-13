//#include <stdlib.h>
#include <GL/glew.h>
#define GLEW_STATIC
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

int w = 640, h = 480;

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

void drawTriangle();    
void draw();
void drawCube(GLfloat x0, GLfloat y0, GLfloat z0, GLfloat length);
void onKeyPressed(GLFWwindow * window, int key, int scancode, int action, int mods);

int main(){
    
    std::cout << "Oto nowe okno z zawartoscia" << std::endl;
   

    if(!glfwInit()) exit(EXIT_FAILURE);

    GLFWwindow * window;
    window = glfwCreateWindow(w, h, "Moje super okno", NULL, NULL);


    glfwSetKeyCallback( window, onKeyPressed );
    glfwSetInputMode( window, GLFW_STICKY_KEYS, 1 );
    


    if(!window){
        std::cout << "kupa" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    // do kostki
    glfwMakeContextCurrent(window);
    glViewport(0,0,w, h);
    glMatrixMode(GL_PROJECTION); // do kamery
    glLoadIdentity();// macierz jednostkowa
    glOrtho(0, w, 0,h, 0, 1000); // ustwaienia do kamery jakby
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.4,0.5,0.2,1);
        glPushMatrix();
        glTranslatef(w/2, h/2, -500);
        glRotatef(rotationX, 1, 0, 0);
        glRotatef(rotationY, 0, 1, 0);
        glTranslatef(-w/2, -h/2, 500);
        
        drawCube(w/2,h/2,-500,200);

        glPopMatrix();
        
        /*
        glfwGetFramebufferSize(window, &w, &h);
        glViewport(0,0, w, h);
        glClearColor(0.4,0.5,0.2,1);
        glClear(GL_COLOR_BUFFER_BIT);
        //draw();
       

        glfwSwapBuffers(window);
        glfwPollEvents();
        */
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    return 0;
}

void drawTriangle(){
    glBegin(GL_TRIANGLES);
   // GL_QUAD do prostokata
        glColor3f(0.8,0.4,0.1);// cos tam 
        glVertex3f(-1,0,0);
        glColor3f(0,1,0);//green
        glVertex3f(0,1,0);
        glColor3f(0,0,1);//red
        glVertex3f(1,0,0);
    glEnd();
}

void draw(){

    static float counter = 0.0;
    counter += .01;

     //transformacja ortogonalna Projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(float) w/h, (float)w/h, -1.f, 1.f, 1.f, -1.f);

    //trnsformacja modelView Matrixa
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // rysuj 11 trojkatuf

    for(int i = 0; i < 11;i++){
        float t = (float)i/10;
        glPushMatrix();

        //przeskaluj, obroc, translatuj
        glTranslatef(t * sin(counter), 0, 0);
        glRotatef(360 * t * counter, 0,0,1);
        glScalef(1-t, 1-t, 1-t);

        drawTriangle();

        glPopMatrix();
    }
    
}

void drawCube(GLfloat x0, GLfloat y0, GLfloat z0, GLfloat length){
    glColor3f(0.8,0.4,0.1); // orange lines 
    GLfloat vertices[] = {
        // front
        x0 - length/2, y0 + length/2, z0 + length/2, // lewy gorny
        x0 + length/2, y0 + length/2, z0 + length/2, // prawy gorny
        x0 + length/2, y0 - length/2, z0 + length/2, // prawy dolny
        x0 - length/2, y0 - length/2, z0 + length/2, // lewy dolny

        // tyl
        x0 - length/2, y0 + length/2, z0 - length/2, // lewy gorny
        x0 + length/2, y0 + length/2, z0 - length/2, // prawy gorny
        x0 + length/2, y0 - length/2, z0 - length/2, // prawy dolny
        x0 - length/2, y0 - length/2, z0 - length/2, // lewy dolny

        // lewa
        x0 - length/2, y0 + length/2, z0 + length/2, // lewy gorny
        x0 - length/2, y0 + length/2, z0 - length/2, // prawy gorny
        x0 - length/2, y0 - length/2, z0 - length/2, // prawy dolny
        x0 - length/2, y0 - length/2, z0 + length/2, // lewy dolny

        // prawa
        x0 + length/2, y0 + length/2, z0 + length/2, // lewy gorny
        x0 + length/2, y0 + length/2, z0 - length/2, // prawy gorny
        x0 + length/2, y0 - length/2, z0 - length/2, // prawy dolny
        x0 + length/2, y0 - length/2, z0 + length/2, // lewy dolny

        //gora
        x0 - length/2, y0 + length/2, z0 + length/2, // lewy gorny
        x0 - length/2, y0 + length/2, z0 - length/2, // prawy gorny
        x0 + length/2, y0 + length/2, z0 - length/2, // prawy dolny
        x0 + length/2, y0 + length/2, z0 + length/2, // lewy dolny

         //dol
        x0 - length/2, y0 - length/2, z0 + length/2, // lewy gorny
        x0 - length/2, y0 - length/2, z0 - length/2, // prawy gorny
        x0 + length/2, y0 - length/2, z0 - length/2, // prawy dolny
        x0 + length/2, y0 - length/2, z0 + length/2, // lewy dolny
    };

    

   
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);// 3 bo x, y, z o typie GLfloat
    glDrawArrays(GL_QUADS,0,24);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void onKeyPressed(GLFWwindow * window, int key, int scancode, int action, int mods){
    const GLfloat speed_of_rotation = 15;
    // action: GLFW_PRESS, GLFW_RELEASE, GLFW_REPEAT
    if(action == GLFW_PRESS || action == GLFW_REPEAT){
        switch(key){
            case GLFW_KEY_UP:
                rotationX -= speed_of_rotation;
                break;
            case GLFW_KEY_DOWN:
                rotationX += speed_of_rotation;
                break;
            case GLFW_KEY_RIGHT:
                rotationY += speed_of_rotation;
                break;
            case GLFW_KEY_LEFT:
                rotationY -= speed_of_rotation;
                break;
            
        }
    }
}