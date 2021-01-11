#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void display(void){
    glClear (GL_COLOR_BUFFER_BIT);

    int x=0,y=0,b = 1,i;

    for(i = 1;i<=64;i++){
        if(i==9 || i==25 || i==41 || i==57){
            y++;
            b=0;
            x=0;
        }
        if(i==17 || i==33 || i==49){
            y++;
            b=1;
            x=0;
        }
        if(b==1){
            ///black
            glColor3f(0.0,0.0,0.0);
            glBegin(GL_POLYGON);
            glVertex3f(x,y,0.0);
            glVertex3f(x+1,y,0.0);
            glVertex3f(x+1,y+1,0.0);
            glVertex3f(x,y+1,0.0);
            glEnd();
            b = 0;
            x++;
        }else{
            ///white
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_POLYGON);
            glVertex3f(x,y,0.0);
            glVertex3f(x+1,y,0.0);
            glVertex3f(x+1,y+1,0.0);
            glVertex3f(x,y+1,0.0);
            glEnd();
            b = 1;
            x++;
        }
    }

    glFlush ();
}
void init (void){
    glClearColor (0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.5, 8.5, -0.5, 8.5, -10.0, 10.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (700, 600);
    glutInitWindowPosition (350, 80);
    glutCreateWindow ("My Chess Board - Marjuk");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
