#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define drawW 200
#define drawH 200

int waveLines = 0, color, score, enemyFishX, enemyFishY = 100, sharkX, sharkY = -60;
float sharkScale = 1.0;
bool enemyFishDirection = false;
bool fishCaught = false;


void Timer(int value) {
    glutTimerFunc(8, Timer, 0);
    glutPostRedisplay();
}

void Reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float ratio = (float)width / height;

    if (width > height) {
        glOrtho(-drawW * ratio, drawW * ratio, -drawH, drawH, -1, 1);
    }
    else {
        glOrtho(-drawW, drawW, -drawH / ratio, drawH / ratio, -1, 1);
    }

    glClearColor(0.00000, 0.54118, 0.90196, 1);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'a') {
        if (sharkX >= -90) {
            sharkX -= 10;
        }
    }
    else if (key == 'd') { 
        if (sharkX <= 90) {
            sharkX += 10;
        }
    }
}

void enemyFish() {
    enemyFishY--;

    if (enemyFishX <= -120) {
        enemyFishDirection = true;
    }
    else if (enemyFishX >= 120) {
        enemyFishDirection = false;
    }

    if (enemyFishDirection) {
        enemyFishX++;
    }
    else {
        enemyFishX--;
    }

    if (enemyFishY <= -250) {
        enemyFishY = 250;
    }

    float dx = sharkX - enemyFishX;
    float dy = sharkY - enemyFishY;
    float distance = sqrt(dx * dx + dy * dy);

    if (distance <= 20) {
        fishCaught = true;
        sharkScale += 0.1;
        sharkY += 10;
        score++;
        color++;
        printf("%d \n", score);
        if (score == 5)
        {
            glutDestroyWindow(glutGetWindow());
            printf("You won!");
        }
    }
}

void drawShark() {
    glPushMatrix();
    glScalef(sharkScale, sharkScale, 1.0);
    glColor3f(0.5, 0.5, 0.5);

    // Front (main body)
    glBegin(GL_POLYGON);
    glVertex2f(sharkX, -26);
    glVertex2f(sharkX - 23, -53);
    glVertex2f(sharkX, -80);
    glVertex2f(sharkX + 23, -53);
    glEnd();

    // Back triangle (tail)
    glBegin(GL_TRIANGLES);
    glVertex2f(sharkX, -80);
    glVertex2f(sharkX - 20, -100);
    glVertex2f(sharkX + 20, -100);
    glEnd();
    glPopMatrix();
}

void drawFish() {
    if (color % 2 == 0) {
        glColor3f(1, 0, 0); //red
    }
    else if (color % 3 == 0) {
        glColor3f(0, 1, 0); //green
    }
    else {
        glColor3f(0.878, 0.659, 0.098); //Orange
    }

    // Front (main body)
    glBegin(GL_POLYGON);
    glVertex2f(enemyFishX, enemyFishY + 15);
    glVertex2f(enemyFishX - 15, enemyFishY - 5);
    glVertex2f(enemyFishX, enemyFishY - 17);
    glVertex2f(enemyFishX + 15, enemyFishY - 5);
    glEnd();

    // Tail triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(enemyFishX, enemyFishY - 16);
    glVertex2f(enemyFishX - 17, enemyFishY - 30);
    glVertex2f(enemyFishX + 17, enemyFishY - 30);
    glEnd();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    waveLines--;
    for (int i = 0; i < 500; i++) {
        glPushMatrix();
        glTranslated(0, waveLines + i * 100, 1);
        glBegin(GL_POLYGON);
        glColor3d(0.00000, 0.41961, 0.70196);
        glVertex2d(-800, -2040);
        glVertex2d(800, -2040);
        glVertex2d(800, -2000);
        glVertex2d(-800, -2000);
        glEnd();
        glPopMatrix();

    }
    glTranslated(sharkX, sharkY, 1);
    drawShark();
    glPopMatrix();

    enemyFish();

    if (!fishCaught) {
        glPushMatrix();
        glTranslated(enemyFishX, enemyFishY, 1);
        drawFish();
        glPopMatrix();
    }

    if (fishCaught) {
        enemyFishY = 250;
        fishCaught = false;
    }



    glFlush();
}

int main(int argc, char* argv[]) {

    int windowWidth = 800;
    int windowHeight = 600;
    glutInitWindowSize(windowWidth, windowHeight);

    glutInit(&argc, argv);
    glutCreateWindow("Shark Frenzy");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(keyboard);
    Timer(0);
    glutMainLoop();
    return 0;
}