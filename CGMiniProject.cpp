#include<iostream>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define pi 3.142857
using namespace std;
void sun(float sx, float sy,float r, int noseg){            /*function for sun/moon*/
    glBegin(GL_TRIANGLE_FAN);
        for(int p=0; p<noseg; p+= 1){
            glVertex2f(sx + r*cosf(2.0* pi* float(p)/float(noseg)),sy+ r* sinf(2.0* pi* float(p)/float(noseg)));
        }
    glEnd();
}
void drawmid(float cx, float cy,float r1, int segment){          /*function for draw circle*/
    glLineWidth(1.0);           /*declaring circle width*/
    glBegin(GL_LINE_LOOP);          /*beginning line loop*/
    for (int i=0; i<segment; i++){          /*initializing loop for no. of segments*/
        float thetha= 2.0 * pi* float(i)/float(segment);            /*getting angles*/
        float x= r1 * cosf(thetha);              /*getting x-coordinates*/
        float y = r1* sinf(thetha);              /*getting y-coordinate*/
        glVertex2f(x+cx,y+cy);              /*plotting the point*/
    }
    glEnd();
}
void track(float cxt, float cyt, float rad, int segs){          /*function for drawing track*/
        glBegin(GL_TRIANGLE_FAN);
            for(int l=0; l<= segs; l+= 1){
                float angle= 2.0* pi * float(l)/float(segs);
                float x= rad* cosf(angle);
                float y= rad* sinf(angle);
                glVertex2f(x+cxt, y+cyt);
            }
        glEnd();
}
void initialize(){
    glClearColor(0.0f,0.0f,0.0f,1.0f);         /*sets background color*/
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_LINE_SMOOTH|GL_POINT_SMOOTH);            /*enables different conditions*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}
void balltranslate(float tx, float ty, float tfx, float tfy){       /*function to translate ball*/
    glColor3f(0.0,0.0,1.0);
    float x= tx, y= ty;
    while(1){
        glClear(GL_COLOR_BUFFER_BIT);
        tx= tx + tfx;
        ty= ty + tfy;
        if(tx>640||tx<0||ty<0||ty>480){
            tx= x;
            ty= y;
        }
        sun(tx, ty, 0.0159,50);
        glFlush();
        glutPostRedisplay();
    }
}
void day(){         /*drawing day scene*/
    glClearColor(0.62,0.86,0.90,1.0);           /*declaring sky color*/
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(233,217,89);         /*giving color to sun*/
    sun(-0.5,0.7,0.056,150);            /*drawing sun*/
    glColor3ub(223,222,223);            /*giving color to clouds*/
    sun(-0.19,0.86,0.05,30);            /*drawing clouds*/
    sun(-0.11,0.84,0.065,25);
    sun(-0.22,0.789,0.045,28);
    sun(-0.155,0.775,0.05,25);
    sun(-0.2,0.745,0.04,35);
    sun(-0.65,0.785,0.06,25);
    sun(-0.72,0.75,0.04,40);
    sun(-0.69,0.77,0.052,30);
}
void teamA(){
    glLineWidth(1.9);           /*player width*/
    glBegin(GL_LINES);          /*drawing players for team A*/
        //3-4-3 formation
        glColor3ub(0,0,210);      /*color of A goalkeeper*/
        glVertex2f(-0.791,-0.65);       /*draw A keeper*/
        glVertex2f(-0.791,-0.595);
        glColor3ub(127,0,255);         /*A player color*/
        glVertex2f(-0.59,-0.899);           /*A right back*/
        glVertex2f(-0.59,-0.829);
        glVertex2f(-0.51,-0.65);            /*A center back*/
        glVertex2f(-0.51,-0.589);
        glVertex2f(-0.44,-0.41);            /*A left back*/
        glVertex2f(-0.44,-0.356);
        glVertex2f(-0.38,-0.963);          /*A right mid*/
        glVertex2f(-0.38,-0.891);
        glVertex2f(-0.33,-0.778);         /*A right center mid*/
        glVertex2f(-0.33,-0.713);
        glVertex2f(-0.271,-0.53);          /*A left center mid*/
        glVertex2f(-0.271,-0.47);
        glVertex2f(-0.245,-0.37);          /*A left mid*/
        glVertex2f(-0.245,-0.318);
        glVertex2f(-0.055,-0.86);           /*A right forward*/
        glVertex2f(-0.055,-0.793);
        glVertex2f(-0.15,-0.65);            /*A center forward*/
        glVertex2f(-0.15,-0.589);
        glVertex2f(-0.032,-0.445);           /*A left forward*/
        glVertex2f(-0.032,-0.389);
    glEnd();
}
void teamB(){
    glLineWidth(1.9);           /*player width*/
    glBegin(GL_LINES);          /*drawing players for team B*/
        //4-2-3-1 formation
        glColor3ub(200,0,0);          /*color of B goalkeeper*/
        glVertex2f(0.791,-0.65);            /*draw B goalkeeper*/
        glVertex2f(0.791,-0.595);
        glColor3ub(254,141,34);         /*B player color*/
        glVertex2f(0.60,-0.937);           /*B left back*/
        glVertex2f(0.60,-0.866);
        glVertex2f(0.65,-0.785);            /*B center left back*/
        glVertex2f(0.65,-0.7202);
        glVertex2f(0.56,-0.567);            /*B center right back*/
        glVertex2f(0.56,-0.5052);
        glVertex2f(0.422,-0.4);              /*B right back*/
        glVertex2f(0.422,-0.3455);
        glVertex2f(0.39,-0.84);             /*B left mid-back*/
        glVertex2f(0.39,-0.774);
        glVertex2f(0.32,-0.5);              /*B right mid-back*/
        glVertex2f(0.32,-0.442);
        glVertex2f(0.09,-0.85);             /*B left mid*/
        glVertex2f(0.09,-0.7822);
        glVertex2f(0.258,-0.65);             /*B center mid*/
        glVertex2f(0.258,-0.589);
        glVertex2f(0.088,-0.45);              /*B right mid*/
        glVertex2f(0.088,-0.394);
        glVertex2f(0.12,-0.65);              /*B center forward*/
        glVertex2f(0.12,-0.589);
    glEnd();
}
void ad(){
    glBegin(GL_QUADS);          /*drawing AD banner*/
        glColor3f(0.57,0.24,0.74);          /*gradient*/
        glVertex2f(-0.6,-0.3);          /*A*/
        glColor3f(0.85,0.47,0.75);          /*gradient*/
        glVertex2f(0.6,-0.3);           /*B*/
        glColor3f(0.05,0.47,0.57);          /*gradient*/
        glVertex2f(0.6,-0.267);         /*C*/
        glColor3f(0.74,0.85,0.47);          /*gradient*/
        glVertex2f(-0.6,-0.267);            /*D*/
    glEnd();
}
void night(){           /*drawing night scene*/
    glClearColor(0.44,0.50,0.53,1.0);           /*declare night sky color*/
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(191,196,201);            /*giving color to moon*/
    sun(-0.7,0.7,0.059,35);         /*drawing moon*/
}
void menu(int choice){          /*writing menu to give choices to user*/
    switch(choice){         /*declaring switch case*/
    case 1: day();
    break;
    case 2: night();
    break;
    }
}
void exitkey(unsigned char k, int x, int y){            /*declaring exit key as "Q"*/
    if(k==112)exit(0);
}
void choice(){          /*giving choices*/
    int ch;
    cout<<"Enter choice 1)Day, 2)Night: "<<endl;
    cin>>ch;
    menu(ch);
}
void field(){
    glLineWidth(1.5);           /*declares co-ordinate line width*/
    glBegin(GL_QUADS);          /*begin drawing field*/
        glColor3f(0.0f,0.78f,0.0f);            /*lower-left corner*/
        glVertex2f(-1.0f,-1.0f);                /*A*/
        glColor3f(0.0f,0.78f,0.0f);         /*lower-right corner*/
        glVertex2f(1.0f,-1.0f);         /*B*/
        glColor3f(0.0f,0.40f,0.0f);         /*upper-right corner*/
        glVertex2f(0.637f,-0.30f);           /*C*/
        glColor3f(0.0f,0.40f,0.0f);         /*upper left corner*/
        glVertex2f(-0.637f,-0.30f);          /*D*/
    glEnd();
    glLineWidth(1.0);           /*declaring width of field boundary*/
    glBegin(GL_LINES);          /*declaring field boundary*/
       glColor3f(1.0f,1.0f,1.0f);           /*declaring white color*/
       glVertex2f(0.637f,-0.30f);            /*declaring upper boundary*/
       glVertex2f(-0.637f,-0.30f);
       glVertex2f(-0.637,-0.30f);           /*declaring left boundary*/
       glVertex2f(-1.0f,-1.0f);
       glVertex2f(-1.0f,-1.0f);         /*declaring lower boundary*/
       glVertex2f(1.0f,-1.0f);
       glVertex2f(1.0f,-1.0f);          /*declaring right boundary*/
       glVertex2f(0.637f,-0.30f);
    glEnd();
    drawmid(0.0f,-0.65f,0.0915,25);         /*drawing mid-circle*/
    drawmid(-0.54f,-0.647f,0.055,25);           /*drawing left-D circle*/
    drawmid(0.54f,-0.647f,0.055f,20);            /*drawing right-D circle*/
    glBegin(GL_QUADS);          /*quads to cover D-circle*/
        glColor3f(0.0f,0.62f,0.0f);         /*giving field color*/
        glVertex2f(-0.62f,-0.702f);         /*A*/
        glVertex2f(-0.57f,-0.702f);         /*B*/
        glColor3f(0.0f,0.56f,0.0f);         /*giving field color*/
        glVertex2f(-0.523f,-0.590f);        /*C*/
        glVertex2f(-0.595f,-0.590f);        /*D*/
    glEnd();
    glBegin(GL_QUADS);          /*quads to cover D-circle*/
        glColor3f(0.0f,0.62f,0.0f);         /*giving field color*/
        glVertex2f(0.62f,-0.702f);          /*A*/
        glVertex2f(0.57f,-0.702f);          /*B*/
        glColor3f(0.0f,0.56f,0.0f);         /*giving field color*/
        glVertex2f(0.523f,-0.590f);         /*C*/
        glVertex2f(0.595f,-0.590f);         /*D*/
    glEnd();
    glLineWidth(1.0);           /*declaring line width for D*/
    glBegin(GL_LINES);          /*D Marking*/
        glColor3f(1.0f,1.0f,1.0f);          /*initializing white color*/
        glVertex2f(0.762f,-0.55f);          /*right inner-D begin*/
        glVertex2f(0.675f,-0.55f);
        glVertex2f(0.875f,-0.75f);
        glVertex2f(0.777f,-0.75f);         /*right inner-D terminated*/
        glVertex2f(-0.762f,-0.55f);         /*left inner-D begin*/
        glVertex2f(-0.675f,-0.55f);
        glVertex2f(-0.875f,-0.75f);
        glVertex2f(-0.777f,-0.75f);            /*left inner-D terminated*/
        glVertex2f(0.675f,-0.55f);          /*right inner-D closed*/
        glVertex2f(0.777f,-0.75f);
        glVertex2f(-0.675f,-0.55f);         /*left inner-D closed*/
        glVertex2f(-0.777f,-0.75f);
        glVertex2f(0.705f,-0.44f);           /*right outer-D begin*/
        glVertex2f(0.455f,-0.44f);                                                                                                         ;
        glVertex2f(0.927f,-0.86f);
        glVertex2f(0.631f,-0.86f);         /*right outer-D terminated*/
        glVertex2f(-0.705f,-0.44f);          /*left outer-D begin*/
        glVertex2f(-0.455f,-0.44f);
        glVertex2f(-0.927f,-0.86f);
        glVertex2f(-0.631f,-0.86f);            /*left outer-D terminated*/
        glVertex2f(0.455f,-0.44f);           /*right outer-D closed*/
        glVertex2f(0.631f,-0.86f);
        glVertex2f(-0.455f,-0.44f);          /*left outer-D closed*/
        glVertex2f(-0.631f,-0.86f);
    glEnd();
    glPointSize(1.8);           /*declaring point size*/
    glBegin(GL_POINTS);         /*initializing different points*/
        glColor3f(1.0f,1.0f,1.0f);          /*declaring white color*/
        glVertex2f(0.64f,-0.65f);           /*marking RH penalty spot*/
        glVertex2f(-0.64f,-0.65f);          /*marking LH penalty spot*/
        glVertex2f(0.0f,-0.65f);            /*marking mid point*/
    glEnd();
    glLineWidth(1.0);           /*declares inner field marking width*/
    glBegin(GL_LINES);          /*declaring field markings*/
        glColor3f(1.0f,1.0f,1.0f);          /*giving white color*/
        glVertex2f(0.0f,-0.30f);         /*drawing mid-line*/
        glVertex2f(0.0f,-1.0f);
    glEnd();
    glLineWidth(1.567);          /*width of goal post*/
    glBegin(GL_LINES);          /*drawing goal posts*/
        glColor3f(1.0f,1.0f,1.0f);          /*declaring color for posts*/
        glVertex2f(0.795f,-0.61f);           /*drawing RH upper pole*/
        glVertex2f(0.795f,-0.55f);
        glVertex2f(0.842f,-0.692f);          /*drawing RH lower pole*/
        glVertex2f(0.842f,-0.635f);
        glVertex2f(0.795f,-0.55f);           /*drawing RH connecting bar*/
        glVertex2f(0.842f,-0.635f);
        glVertex2f(0.795,-0.55);            /*upper horizontal RH*/
        glVertex2f(0.815,-0.55);
        glVertex2f(0.842,-0.635);          /*lower horizontal RH*/
        glVertex2f(0.862,-0.635);
        glVertex2f(0.815,-0.55);           /*background connecting rod RH*/
        glVertex2f(0.862,-0.635);
        glVertex2f(0.815,-0.55);           /*background upper pole RH*/
        glVertex2f(0.815,-0.61);
        glVertex2f(0.862,-0.635);          /*background lower pole RH*/
        glVertex2f(0.862,-0.692);
        glVertex2f(-0.795f,-0.61f);           /*drawing LH upper pole*/
        glVertex2f(-0.795f,-0.55f);
        glVertex2f(-0.842f,-0.692f);          /*drawing LH lower pole*/
        glVertex2f(-0.842f,-0.635f);
        glVertex2f(-0.795f,-0.55f);           /*drawing LH connecting bar*/
        glVertex2f(-0.842f,-0.635f);
        glVertex2f(-0.795,-0.55);            /*upper horizontal LH*/
        glVertex2f(-0.815,-0.55);
        glVertex2f(-0.842,-0.635);          /*lower horizontal LH*/
        glVertex2f(-0.862,-0.635);
        glVertex2f(-0.815,-0.55);           /*background connecting rod LH*/
        glVertex2f(-0.862,-0.635);
        glVertex2f(-0.815,-0.55);           /*background upper pole LH*/
        glVertex2f(-0.815,-0.61);
        glVertex2f(-0.862,-0.635);          /*background lower pole LH*/
        glVertex2f(-0.862,-0.692);
    glEnd();
    glLineWidth(1.48);          /*width of corner stick*/
    glBegin(GL_LINES);          /*drawing corner stick*/
        glColor3ub(0,0,0);           /*giving yellow color*/
        glVertex2f(-0.637,-0.30);           /*flag at upper-left corner*/
        glVertex2f(-0.637,-0.27);
        glVertex2f(-1.0,-1.0);          /*flag at lower-left corner*/
        glVertex2f(-1.0,-0.95);
        glVertex2f(0.637,-0.30);            /*flag at upper-right corner*/
        glVertex2f(0.637,-0.27);
        glVertex2f(1.0,-1.0);           /*flag at lower-right corner*/
        glVertex2f(1.0,-0.95);
    glEnd();
    glBegin(GL_TRIANGLES);          /*drawing triangular corner flag*/
        glColor3f(1.0f,0.0f,0.0f);          /*giving red color to flags*/
        glVertex2f(-0.637,-0.27);           /*upper-left corner*/
        glVertex2f(-0.62,-0.277175);
        glVertex2f(-0.637,-0.28435);
        glVertex2f(0.637,-0.27);            /*upper-right corner*/
        glVertex2f(0.62,-0.277175);
        glVertex2f(0.637,-0.28435);
        glVertex2f(-1.0,-0.95);         /*lower-left corner*/
        glVertex2f(-0.983,-0.957125);
        glVertex2f(-1.0,-0.96425);
        glVertex2f(1.0,-0.95);          /*lower-right corner*/
        glVertex2f(0.983,-0.957125);
        glVertex2f(1.0,-0.96435);
    glEnd();
}
void display(void){
    glMatrixMode(GL_MODELVIEW);
    choice();
    glColor3f(0.54,0.68,0.47);          /*color of ceiling*/
    track(0.0,-0.841,1.4,110);          /*drawing ceiling*/
    glColor3f(0.22,0.31,0.24);          /*color of stand*/
    track(0.0,-0.85,1.4,100);           /*drawing the stand*/
    glColor3f(0.245,0.875,0.45);            /*color of stadium start*/
    track(0.0,-1.278,1.20,100);         /*drawing the stadium start*/
    glColor3ub(255,187,66);             /*color of racing track*/
    track(0.0,-1.308,1.20,50);          /*drawing racing track*/
    field();
    ad();
    teamA();
    teamB();
    glGetError();
    glFlush();
}
int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutCreateWindow("FirstProgram");
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1200,900);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    initialize();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutCreateMenu(menu);
    glutKeyboardFunc(exitkey);
    glutMainLoop();
    return 0;
}

