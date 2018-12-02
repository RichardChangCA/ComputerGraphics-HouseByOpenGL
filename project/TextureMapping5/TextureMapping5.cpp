// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//
/* Dr. Yawei Liang, 20140312, OpenGL with VC++: Yawei抯 space to space, main.cpp
*/

#include<GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include "RgbImage.h"
#include<iostream> // generate message
using std::cout;   // dot.cpp needs this

#define _USE_MATH_DEFINES // for C++
#include <stdio.h> 
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>
double rotate_y = 30; // Front faces viewer, try a different value, like -10
double rotate_x = 30; // Front faces viewer, try a different value, like -10
double rotate_z = 0;
double transfer_x = 0;
double transfer_y = 0;
double transfer_z = 0;
double scale_change = 1;
double pi = 3.1415926;
double a = sqrt(1600 - 400);
GLfloat w = 1600;  // the size of the screen space, top-right: 800, 600
GLfloat h = 1200;  // bottom-left: 0, 0
GLfloat d = 1600;//depth
GLuint	background;			// Storage For One Texture ( NEW )
GLuint houseFace;
GLuint gezi;
GLuint roof;
GLuint thanks;
void drawSphere(double r, int lats, int longs) {
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = pi * (-0.5 + (double)(i - 1) / lats);   // M_PI
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = pi * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= longs; j++) {
			double lng = 2 * pi * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(x * zr0, y * zr0, z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(x * zr1, y * zr1, z1);
		}
		glEnd();
	}
}

void loadTextureFromFile(char *filename)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(1, &background);					// Create The Texture
	glBindTexture(GL_TEXTURE_2D, background);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Typical Texture Generation Using Data From The Bitmap

	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

}

void loadTextureFromFile1(char *filename1)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename1);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(2, &houseFace);					// Create The Texture
	glBindTexture(GL_TEXTURE_2D, houseFace);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Typical Texture Generation Using Data From The Bitmap

	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

}

void loadTextureFromFile2(char *filename2)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename2);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(3, &gezi);					// Create The Texture
	glBindTexture(GL_TEXTURE_2D, gezi);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Typical Texture Generation Using Data From The Bitmap

	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

}

void loadTextureFromFile3(char *filename3)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename3);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(4, &roof);					// Create The Texture
	glBindTexture(GL_TEXTURE_2D, roof);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Typical Texture Generation Using Data From The Bitmap

	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

}

void loadTextureFromFile4(char *filename4)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename4);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(5, &thanks);					// Create The Texture
	glBindTexture(GL_TEXTURE_2D, thanks);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Typical Texture Generation Using Data From The Bitmap

	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // background color


	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

	glBindTexture(GL_TEXTURE_2D, thanks);//thanks tile
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-150, -250, -250);
	glScalef(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(499, 1, 1);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(499, 199, 1);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1, 199, 1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1, 1,1);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, background);//background
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -799.0);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(799.0f, -599.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(799.0f, 600.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-799.0f, 600.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-799.0f, -599.0f, 0.0f);

	glEnd();


	for (int i = -450; i < 550; i = i + 80) {
		for (int j = -270; j < 400; j = j + rand() % 130) {
			for (int n = -500; n < 500; n = n + 100) {
				glLoadIdentity();
				glRotatef(rotate_x, 1.0, 0.0, 0.0);
				glRotatef(rotate_y, 0.0, 1.0, 0.0);
				glRotatef(rotate_z, 0.0, 0.0, 1.0);
				glTranslatef(transfer_x, transfer_y, transfer_z);
				glScalef(scale_change, scale_change, scale_change);
				glTranslatef(i, j, n);
				glScalef(0.1, 0.1, 0.1);
				glColor3f(0.0, 0.0, 1.0);//雨滴颜色
				glTranslatef(-550.0f, 220.0f, 0.0f);//雨滴位置
				glScalef(50.0 / 1.3333f, 50.0, 50.0 / 1.3333f);
				//底部开始
				drawSphere(1.0, 40, 40);
				//雨滴上方
				glLoadIdentity();
				glRotatef(rotate_x, 1.0, 0.0, 0.0);
				glRotatef(rotate_y, 0.0, 1.0, 0.0);
				glRotatef(rotate_z, 0.0, 0.0, 1.0);
				glTranslatef(transfer_x, transfer_y, transfer_z);
				glScalef(scale_change, scale_change, scale_change);
				glTranslatef(i, j, n);
				glScalef(0.1, 0.1, 0.1);
				glTranslatef(-550.0f, 235.0f, 0.0f);//雨滴位置
				glScalef(50.0 / 1.3333f, 50.0, 50.0 / 1.3333f);
				glColor3f(0.0, 0.0, 1.0);//雨滴颜色
				glBegin(GL_QUAD_STRIP);//连续填充四边形串
				int i = 0;
				for (i = 0; i <= 390; i += 15)
				{
					float p = i * 3.14 / 180;
					glVertex3f(0, 1.5, 0.0f);
					glVertex3f(sin(p), 0.0f, cos(p));
				}
				glEnd();
				/*雨滴结束*/

			}
		}
		/*雨滴*/
	}
	//张凌峰代码
	glLoadIdentity(); //gardan floor
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(0, -302, 0);
	glBegin(GL_QUAD_STRIP);
	glColor3f(110.0 / 225, 49.0 / 225, 10.0 / 225);
	glVertex3f(-500, 50, 500);
	glVertex3f(-500, 0, 500);
	glVertex3f(500, 50, 500);
	glVertex3f(500, 0, 500);
	glVertex3f(500, 50, -500);
	glVertex3f(500, 0, -500);
	glVertex3f(-500, 50, -500);
	glVertex3f(-500, 0, -500);
	glVertex3f(-500, 50, 500);
	glVertex3f(-500, 0, 500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, gezi);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-500, 0, 500);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(500, 0, 500);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(500, 0, -500);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-500, 0, -500);
	glColor3f(185 / 255.0, 185 / 255.0, 185 / 255.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-500, 50, 500);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(500, 50, 500);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(500, 50, -500);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-500, 50, -500);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, houseFace);
	glLoadIdentity(); //house
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-150, -250, -250);
	glScalef(1, 1, 1);
	glBegin(GL_QUADS);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 200, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 0, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(500, 0, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(500, 200, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(500, 0, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(500, 200, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(500, 200, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(500, 0, 350);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(500, 0, 350);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(500, 200, 350);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 200, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 350);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 200, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 200, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glVertex3f(0, 200, 0);
	glVertex3f(0, 200, 350);
	glVertex3f(500, 200, 350);
	glVertex3f(500, 200, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 350);
	glVertex3f(500, 0, 350);
	glVertex3f(500, 0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 200, 350);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(500, 200, 350);
	glTexCoord2f(0.5f, 0.4f); glVertex3f(250, 400, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 200, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(500, 200, 0);
	glTexCoord2f(0.5f, 0.4f); glVertex3f(250, 400, 0);
	glEnd();
	//roof
	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(250, 420, 370);
	glVertex3f(250, 400, 370);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 420, -20);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(550, 180, 370);
	glVertex3f(550, 160, 370);
	glVertex3f(550, 160, -20);
	glVertex3f(550, 180, -20);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(550, 180, -20);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(250, 420, -20);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(250, 420, 370);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(550, 180, 370);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(550, 160, 370);
	glVertex3f(550, 160, -20);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 400, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(550, 180, 370);
	glVertex3f(550, 160, 370);
	glVertex3f(250, 400, 370);
	glVertex3f(250, 420, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(550, 180, -20);
	glVertex3f(550, 160, -20);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 420, -20);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(-50, 180, 370);
	glVertex3f(-50, 160, 370);
	glVertex3f(-50, 160, -20);
	glVertex3f(-50, 180, -20);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-50, 180, 370);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(250, 420, 370);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(250, 420, -20);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-50, 180, -20);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(-50, 160, 370);
	glVertex3f(-50, 160, -20);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 400, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(-50, 180, -20);
	glVertex3f(-50, 160, -20);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 420, -20);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, houseFace);
	//balcony floor
	glBegin(GL_POLYGON);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 350);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 30, 350);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100, 30, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100, 0, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glTexCoord2f(1.0f, 0.0f);glVertex3f(0, 0, 0); 
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 30, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100, 30, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100, 0, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 0, 350);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-100, 0, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-100, 0, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glVertex3f(-100, 30, 350);
	glVertex3f(0, 30, 350);
	glVertex3f(0, 30, 0);
	glVertex3f(-100, 30, 0);
	glEnd();
	//balcony door
	glBegin(GL_POLYGON);
	glColor3f(9 / 255.0, 54 / 255.0, 59 / 255.0);
	glVertex3f(-1, 30, 200);
	glVertex3f(-1, 30, 270);
	glVertex3f(-1, 150, 270);
	glVertex3f(-1, 150, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0 / 255.0, 15 / 255.0, 9 / 255.0);
	glVertex3f(-2, 80, 250);
	glVertex3f(-2, 80, 260);
	glVertex3f(-2, 100, 260);
	glVertex3f(-2, 100, 250);
	glEnd();
	//balcony window frame
	glTranslatef(-520, 0, -140);
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 280);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 70, 280);
	glVertex3f(500, 70, 280);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 270);
	glVertex3f(520, 140, 270);
	glVertex3f(520, 70, 270);
	glVertex3f(500, 70, 270);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 200);
	glVertex3f(520, 140, 200);
	glVertex3f(520, 70, 200);
	glVertex3f(500, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 210);
	glVertex3f(520, 140, 210);
	glVertex3f(520, 70, 210);
	glVertex3f(500, 70, 210);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 280);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 140, 200);
	glVertex3f(500, 140, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 70, 280);
	glVertex3f(520, 70, 280);
	glVertex3f(520, 70, 200);
	glVertex3f(500, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 80, 280);
	glVertex3f(520, 80, 280);
	glVertex3f(520, 80, 200);
	glVertex3f(500, 80, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 130, 280);
	glVertex3f(520, 130, 280);
	glVertex3f(520, 130, 200);
	glVertex3f(500, 130, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 280);
	glVertex3f(500, 130, 280);
	glVertex3f(500, 130, 200);
	glVertex3f(500, 140, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 100, 280);
	glVertex3f(500, 110, 280);
	glVertex3f(500, 110, 200);
	glVertex3f(500, 100, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 280);
	glVertex3f(500, 140, 270);
	glVertex3f(500, 70, 270);
	glVertex3f(500, 70, 280);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 235);
	glVertex3f(500, 140, 245);
	glVertex3f(500, 70, 245);
	glVertex3f(500, 70, 235);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 200);
	glVertex3f(500, 140, 210);
	glVertex3f(500, 70, 210);
	glVertex3f(500, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 80, 280);
	glVertex3f(500, 70, 280);
	glVertex3f(500, 70, 200);
	glVertex3f(500, 80, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(184 / 255.0, 248 / 255.0, 255 / 255.0);
	glVertex3f(510, 130, 270);
	glVertex3f(510, 80, 270);
	glVertex3f(510, 80, 210);
	glVertex3f(510, 130, 210);
	glEnd();
	glTranslatef(520, 0, 140);//reset
							  //aside window frame
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 280);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 70, 280);
	glVertex3f(500, 70, 280);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 270);
	glVertex3f(520, 140, 270);
	glVertex3f(520, 70, 270);
	glVertex3f(500, 70, 270);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 200);
	glVertex3f(520, 140, 200);
	glVertex3f(520, 70, 200);
	glVertex3f(500, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 210);
	glVertex3f(520, 140, 210);
	glVertex3f(520, 70, 210);
	glVertex3f(500, 70, 210);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 280);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 140, 200);
	glVertex3f(500, 140, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 70, 280);
	glVertex3f(520, 70, 280);
	glVertex3f(520, 70, 200);
	glVertex3f(500, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 80, 280);
	glVertex3f(520, 80, 280);
	glVertex3f(520, 80, 200);
	glVertex3f(500, 80, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 130, 280);
	glVertex3f(520, 130, 280);
	glVertex3f(520, 130, 200);
	glVertex3f(500, 130, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 130, 280);
	glVertex3f(520, 130, 200);
	glVertex3f(520, 140, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 140, 270);
	glVertex3f(520, 70, 270);
	glVertex3f(520, 70, 280);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(520, 140, 200);
	glVertex3f(520, 140, 210);
	glVertex3f(520, 70, 210);
	glVertex3f(520, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(520, 80, 280);
	glVertex3f(520, 70, 280);
	glVertex3f(520, 70, 200);
	glVertex3f(520, 80, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(184 / 255.0, 248 / 255.0, 255 / 255.0);
	glVertex3f(510, 130, 270);
	glVertex3f(510, 80, 270);
	glVertex3f(510, 80, 210);
	glVertex3f(510, 130, 210);
	glEnd();
	//aside window frame two
	glTranslatef(0, 0, -140);
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 280);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 70, 280);
	glVertex3f(500, 70, 280);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 270);
	glVertex3f(520, 140, 270);
	glVertex3f(520, 70, 270);
	glVertex3f(500, 70, 270);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 200);
	glVertex3f(520, 140, 200);
	glVertex3f(520, 70, 200);
	glVertex3f(500, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 210);
	glVertex3f(520, 140, 210);
	glVertex3f(520, 70, 210);
	glVertex3f(500, 70, 210);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 140, 280);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 140, 200);
	glVertex3f(500, 140, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 70, 280);
	glVertex3f(520, 70, 280);
	glVertex3f(520, 70, 200);
	glVertex3f(500, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 80, 280);
	glVertex3f(520, 80, 280);
	glVertex3f(520, 80, 200);
	glVertex3f(500, 80, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(500, 130, 280);
	glVertex3f(520, 130, 280);
	glVertex3f(520, 130, 200);
	glVertex3f(500, 130, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 130, 280);
	glVertex3f(520, 130, 200);
	glVertex3f(520, 140, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(520, 140, 280);
	glVertex3f(520, 140, 270);
	glVertex3f(520, 70, 270);
	glVertex3f(520, 70, 280);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(520, 140, 200);
	glVertex3f(520, 140, 210);
	glVertex3f(520, 70, 210);
	glVertex3f(520, 70, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(153 / 255.0, 138 / 255.0, 129 / 255.0);
	glVertex3f(520, 80, 280);
	glVertex3f(520, 70, 280);
	glVertex3f(520, 70, 200);
	glVertex3f(520, 80, 200);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(184 / 255.0, 248 / 255.0, 255 / 255.0);
	glVertex3f(510, 130, 270);
	glVertex3f(510, 80, 270);
	glVertex3f(510, 80, 210);
	glVertex3f(510, 130, 210);
	glEnd();
	glTranslatef(0, 0, 140);//reset
							//fence bar one
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	//fence bar two
	glTranslatef(-40, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(40, 0, 0);//reset
						   //fence bar three
	glTranslatef(-60, 0, -40);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(60, 0, 40);//reset
							//fence bar four
	glTranslatef(-60, 0, -80);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(60, 0, 80);//reset
							//fence bar five
	glTranslatef(-60, 0, -120);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(60, 0, 120);//reset
							 //fence bar six
	glTranslatef(-60, 0, -160);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(60, 0, 160);//reset
							 //fence bar seven
	glTranslatef(-60, 0, -200);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(60, 0, 200);//reset
							 //fence bar eight
	glTranslatef(-60, 0, -240);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(60, 0, 240);//reset
							 //fence bar nine
	glTranslatef(-60, 0, -280);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(60, 0, 280);//reset
							 //fence bar ten
	glTranslatef(-60, 0, -320);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(60, 0, 320);//reset
							 //fence bar eleven
	glTranslatef(-20, 0, -330);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 350);
	glVertex3f(-40, 30, 350);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 100, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-40, 100, 330);
	glVertex3f(-40, 30, 330);
	glVertex3f(-40, 30, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 30, 330);
	glVertex3f(-20, 30, 350);
	glVertex3f(-20, 100, 350);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-30, 130, 340);
	glVertex3f(-40, 100, 330);
	glVertex3f(-20, 100, 330);
	glVertex3f(-20, 100, 350);
	glVertex3f(-40, 100, 350);
	glEnd();
	glTranslatef(20, 0, 330);//reset
							 //fence horizontal one
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(0, 55, 350);
	glVertex3f(-100, 55, 350);
	glVertex3f(-100, 75, 350);
	glVertex3f(0, 75, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(0, 75, 330);
	glVertex3f(-100, 75, 330);
	glVertex3f(-100, 55, 330);
	glVertex3f(0, 55, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(0, 75, 350);
	glVertex3f(-100, 75, 350);
	glVertex3f(-100, 75, 330);
	glVertex3f(0, 75, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(0, 55, 330);
	glVertex3f(-100, 55, 330);
	glVertex3f(-100, 55, 350);
	glVertex3f(0, 55, 350);
	glEnd();
	//fence horizontal two
	glTranslatef(0, 0, -330);
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(0, 55, 350);
	glVertex3f(-100, 55, 350);
	glVertex3f(-100, 75, 350);
	glVertex3f(0, 75, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(0, 75, 330);
	glVertex3f(-100, 75, 330);
	glVertex3f(-100, 55, 330);
	glVertex3f(0, 55, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(0, 75, 350);
	glVertex3f(-100, 75, 350);
	glVertex3f(-100, 75, 330);
	glVertex3f(0, 75, 330);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(0, 55, 330);
	glVertex3f(-100, 55, 330);
	glVertex3f(-100, 55, 350);
	glVertex3f(0, 55, 350);
	glEnd();
	glTranslatef(0, 0, 330);//reset
							//fence horizontal three
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-100, 75, 0);
	glVertex3f(-100, 55, 0);
	glVertex3f(-100, 55, 350);
	glVertex3f(-100, 75, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-80, 75, 0);
	glVertex3f(-80, 55, 0);
	glVertex3f(-80, 55, 350);
	glVertex3f(-80, 75, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-100, 55, 0);
	glVertex3f(-80, 55, 0);
	glVertex3f(-80, 55, 350);
	glVertex3f(-100, 55, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(105 / 255.0, 52 / 255.0, 0 / 255.0);
	glVertex3f(-100, 75, 0);
	glVertex3f(-80, 75, 0);
	glVertex3f(-80, 75, 350);
	glVertex3f(-100, 75, 350);
	glEnd();
	glTranslatef(400, 200, 150);//chimney
	glRotatef(-90, 1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(204 / 255.0, 145 / 255.0, 94 / 255.0);
	glVertex3f(0.0, 0.0, 230.0);
	for (int i = 0; i <= 360; i++)
		glVertex3f(70 * cos(2 * 3.14 / 360 * i), 70 * sin(2 * 3.14 / 360 * i), 230.0);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, 200.0);
	for (int i = 0; i <= 360; i++)
		glVertex3f(70 * cos(2 * 3.14 / 360 * i), 70 * sin(2 * 3.14 / 360 * i), 200.0);
	glEnd();
	glBegin(GL_QUADS);
	for (int i = 0; i <= 360; i++) {
		glVertex3f(50 * cos(2 * 3.14 / 360 * i), 50 * sin(2 * 3.14 / 360 * i), 0);
		glVertex3f(50 * cos(2 * 3.14 / 360 * i), 50 * sin(2 * 3.14 / 360 * i), 200);
		glVertex3f(50 * cos(2 * 3.14 / 360 * (i + 1)), 50 * sin(2 * 3.14 / 360 * (i + 1)), 200);
		glVertex3f(50 * cos(2 * 3.14 / 360 * (i + 1)), 50 * sin(2 * 3.14 / 360 * (i + 1)), 0);
	}
	glEnd();
	glBegin(GL_QUADS);
	for (int i = 0; i <= 360; i++) {
		glVertex3f(70 * cos(2 * 3.14 / 360 * i), 70 * sin(2 * 3.14 / 360 * i), 230);
		glVertex3f(70 * cos(2 * 3.14 / 360 * i), 70 * sin(2 * 3.14 / 360 * i), 200);
		glVertex3f(70 * cos(2 * 3.14 / 360 * (i + 1)), 70 * sin(2 * 3.14 / 360 * (i + 1)), 200);
		glVertex3f(70 * cos(2 * 3.14 / 360 * (i + 1)), 70 * sin(2 * 3.14 / 360 * (i + 1)), 230);
	}
	glEnd();
	glLoadIdentity(); //house-front
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-52, -250, 100);
	glScalef(0.4, 0.6, 0.2);
	glBegin(GL_QUADS);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 200, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 0, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(500, 0, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(500, 200, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(500, 0, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(500, 200, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(500, 200, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(500, 0, 350);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(500, 0, 350);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(500, 200, 350);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 200, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 350);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 200, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 200, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glVertex3f(0, 200, 0);
	glVertex3f(0, 200, 350);
	glVertex3f(500, 200, 350);
	glVertex3f(500, 200, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 350);
	glVertex3f(500, 0, 350);
	glVertex3f(500, 0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(235 / 255.0, 250 / 255.0, 255 / 255.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 200, 350);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(500, 200, 350);
	glTexCoord2f(0.5f, 0.4f); glVertex3f(250, 400, 350);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 200, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(500, 200, 0);
	glTexCoord2f(0.5f, 0.4f); glVertex3f(250, 400, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(250, 420, 370);
	glVertex3f(250, 400, 370);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 420, -20);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(550, 180, 370);
	glVertex3f(550, 160, 370);
	glVertex3f(550, 160, -20);
	glVertex3f(550, 180, -20);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(550, 180, 370);
	glVertex3f(550, 180, -20);
	glVertex3f(250, 420, -20);
	glVertex3f(250, 420, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(550, 160, 370);
	glVertex3f(550, 160, -20);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 400, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(550, 180, 370);
	glVertex3f(550, 160, 370);
	glVertex3f(250, 400, 370);
	glVertex3f(250, 420, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(550, 180, -20);
	glVertex3f(550, 160, -20);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 420, -20);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(-50, 180, 370);
	glVertex3f(-50, 160, 370);
	glVertex3f(-50, 160, -20);
	glVertex3f(-50, 180, -20);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(-50, 180, 370);
	glVertex3f(-50, 180, -20);
	glVertex3f(250, 420, -20);
	glVertex3f(250, 420, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(-50, 160, 370);
	glVertex3f(-50, 160, -20);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 400, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(-50, 180, -20);
	glVertex3f(-50, 160, -20);
	glVertex3f(250, 400, -20);
	glVertex3f(250, 420, -20);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(128 / 255.0, 3 / 255.0, 34 / 255.0);
	glVertex3f(-50, 180, 370);
	glVertex3f(-50, 160, 370);
	glVertex3f(250, 400, 370);
	glVertex3f(250, 420, 370);
	glEnd();
	// window frame
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(250, 350, 370);
	glVertex3f(250, 330, 370);
	glVertex3f(250, 330, 350);
	glVertex3f(250, 350, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(100, 250, 370);
	glVertex3f(100, 230, 370);
	glVertex3f(100, 230, 350);
	glVertex3f(100, 250, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(400, 250, 370);
	glVertex3f(400, 230, 370);
	glVertex3f(400, 230, 350);
	glVertex3f(400, 250, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(250, 350, 370);
	glVertex3f(250, 330, 370);
	glVertex3f(100, 230, 370);
	glVertex3f(100, 250, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(250, 350, 370);
	glVertex3f(250, 330, 370);
	glVertex3f(400, 230, 370);
	glVertex3f(400, 250, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(100, 250, 370);
	glVertex3f(100, 230, 370);
	glVertex3f(400, 230, 370);
	glVertex3f(400, 250, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(100, 230, 370);
	glVertex3f(400, 230, 370);
	glVertex3f(400, 230, 350);
	glVertex3f(100, 230, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(250, 350, 370);
	glVertex3f(400, 250, 370);
	glVertex3f(400, 250, 350);
	glVertex3f(250, 350, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(240, 330, 370);
	glVertex3f(260, 330, 370);
	glVertex3f(260, 250, 370);
	glVertex3f(240, 250, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(175, 300, 370);
	glVertex3f(325, 300, 370);
	glVertex3f(325, 280, 370);
	glVertex3f(175, 280, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(100, 250, 370);
	glVertex3f(250, 350, 370);
	glVertex3f(250, 350, 350);
	glVertex3f(100, 250, 350);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(158 / 255.0, 255 / 255.0, 249 / 255.0);
	glVertex3f(100, 220, 360);
	glVertex3f(100, 0, 360);
	glVertex3f(400, 0, 360);
	glVertex3f(400, 220, 360);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(100, 220, 360);
	glVertex3f(100, 0, 360);
	glVertex3f(120, 0, 370);
	glVertex3f(120, 220, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(380, 220, 370);
	glVertex3f(380, 0, 370);
	glVertex3f(400, 0, 360);
	glVertex3f(400, 220, 360);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(100, 220, 360);
	glVertex3f(100, 210, 370);
	glVertex3f(400, 210, 370);
	glVertex3f(400, 220, 360);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(100, 10, 370);
	glVertex3f(100, 0, 360);
	glVertex3f(400, 0, 360);
	glVertex3f(400, 10, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(56 / 255.0, 22 / 255.0, 0 / 255.0);
	glVertex3f(240, 220, 370);
	glVertex3f(240, 0, 370);
	glVertex3f(260, 0, 370);
	glVertex3f(260, 220, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55 / 255.0, 97 / 255.0, 140 / 255.0);
	glVertex3f(200, 120, 370);
	glVertex3f(200, 80, 370);
	glVertex3f(220, 80, 370);
	glVertex3f(220, 120, 370);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55 / 255.0, 97 / 255.0, 140 / 255.0);
	glVertex3f(280, 120, 370);
	glVertex3f(280, 80, 370);
	glVertex3f(300, 80, 370);
	glVertex3f(300, 120, 370);
	glEnd();
	//周琳代码
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);

	glTranslatef(-250, -300, 100);
	//第一块草坪
	glBegin(GL_QUAD_STRIP);
	glColor3f(110.0 / 225, 49.0 / 225, 10.0 / 225);

	glVertex3f(260.0, 50.0, 160.0);
	glVertex3f(260.0, 0.0, 160.0);

	glVertex3f(260.0, 50.0, 0.0);
	glVertex3f(260.0, 0.0, 0.0);

	glVertex3f(0.0, 50.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glVertex3f(0.0, 50.0, 160.0);
	glVertex3f(0.0, 0.0, 160.0);

	glVertex3f(260.0, 50.0, 160.0);
	glVertex3f(260.0, 0.0, 160.0);
	;
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(0.0, 50.0, 0.0);
	glVertex3f(0.0, 50.0, 160.0);
	glVertex3f(260.0, 50.0, 160.0);
	glVertex3f(260.0, 50.0, 0.0);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 160.0);
	glVertex3f(260.0, 0.0, 160.0);
	glVertex3f(260.0, 0.0, 0.0);

	glEnd();
	//第二块草坪
	glBegin(GL_QUAD_STRIP);
	glColor3f(110.0 / 225, 49.0 / 225, 10.0 / 225);
	glVertex3f(260.0, 50.0, 400.0);
	glVertex3f(260.0, 0.0, 400.0);

	glVertex3f(260.0, 50.0, 240.0);
	glVertex3f(260.0, 0.0, 240.0);

	glVertex3f(0.0, 50.0, 240.0);
	glVertex3f(0.0, 0.0, 240.0);

	glVertex3f(0.0, 50.0, 400.0);
	glVertex3f(0.0, 0.0, 400.0);

	glVertex3f(260.0, 50.0, 400.0);
	glVertex3f(260.0, 0.0, 400.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(260.0, 50.0, 400.0);
	glVertex3f(260.0, 50.0, 240.0);
	glVertex3f(0.0, 50.0, 240.0);
	glVertex3f(0.0, 50.0, 400.0);

	glVertex3f(260.0, 0.0, 400.0);
	glVertex3f(260.0, 0.0, 240.0);
	glVertex3f(0.0, 0.0, 240.0);
	glVertex3f(0.0, 0.0, 400.0);

	glEnd();
	//第一条小路
	glBegin(GL_QUAD_STRIP);
	glColor3f(110.0 / 225, 49.0 / 225, 10.0 / 225);
	glVertex3f(0.0, 50.0, 240.0);
	glVertex3f(0.0, 0.0, 240.0);

	glVertex3f(600.0, 50.0, 240.0);
	glVertex3f(600.0, 0.0, 240.0);

	glVertex3f(600.0, 50.0, 160.0);
	glVertex3f(600.0, 0.0, 160.0);

	glVertex3f(0.0, 50.0, 160.0);
	glVertex3f(0.0, 0.0, 160.0);

	glVertex3f(0.0, 50.0, 240.0);
	glVertex3f(0.0, 0.0, 240.0);

	glEnd();


	glBindTexture(GL_TEXTURE_2D, houseFace);
	glBegin(GL_QUADS);
	glColor3f(189.0 / 225, 183.0 / 225, 107.0 / 225);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 50.0, 240.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(600.0, 50.0, 240.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(600.0, 50.0, 160.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 50.0, 160.0);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 0.0, 240.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(600.0, 0.0, 240.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(600.0, 0.0, 160.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 160.0);

	glEnd();

	//第二条小路
	glBegin(GL_QUAD_STRIP);
	glColor3f(110.0 / 225, 49.0 / 225, 10.0 / 225);
	glVertex3f(340.0, 51.0, 400.0);
	glVertex3f(340.0, 0.0, 400.0);

	glVertex3f(340.0, 51.0, 0.0);
	glVertex3f(340.0, 0.0, 0.0);

	glVertex3f(260.0, 51.0, 0.0);
	glVertex3f(260.0, 0.0, 0.0);

	glVertex3f(260.0, 51.0, 400.0);
	glVertex3f(260.0, 0.0, 400.0);

	glVertex3f(340.0, 51.0, 400.0);
	glVertex3f(340.0, 0.0, 400.0);

	glEnd();


	glBegin(GL_QUADS);
	glColor3f(189.0 / 225, 183.0 / 225, 107.0 / 225);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(340.0, 51.0, 400.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(340.0, 51.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(260.0, 51.0, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(260.0, 51.0, 400.0);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(340.0, 0.0, 400.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(340.0, 0.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(260.0, 0.0, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(260.0, 0.0, 400.0);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(110.0 / 225, 49.0 / 225, 10.0 / 225);

	glVertex3f(320.0, 52.0, 10.0);
	glVertex3f(320.0, 52.0, 0.0);
	glVertex3f(280.0, 52.0, 0.0);
	glVertex3f(280.0, 52.0, 10.0);

	glVertex3f(320.0, 52.0, 60.0);
	glVertex3f(320.0, 52.0, 30.0);
	glVertex3f(280.0, 52.0, 30.0);
	glVertex3f(280.0, 52.0, 60.0);

	//glVertex3f(340.0, 52.0, 100.0);
	//glVertex3f(340.0, 52.0, 85.0); 
	//glVertex3f(260.0, 52.0, 85.0);
	//glVertex3f(260.0, 52.0, 100.0);

	glVertex3f(320.0, 52.0, 120.0);
	glVertex3f(320.0, 52.0, 90.0);
	glVertex3f(280.0, 52.0, 90.0);
	glVertex3f(280.0, 52.0, 120.0);

	glVertex3f(320.0, 52.0, 180.0);
	glVertex3f(320.0, 52.0, 150.0);
	glVertex3f(280.0, 52.0, 150.0);
	glVertex3f(280.0, 52.0, 180.0);

	glVertex3f(320.0, 52.0, 240.0);
	glVertex3f(320.0, 52.0, 210.0);
	glVertex3f(280.0, 52.0, 210.0);
	glVertex3f(280.0, 52.0, 240.0);

	glVertex3f(320.0, 52.0, 300.0);
	glVertex3f(320.0, 52.0, 270.0);
	glVertex3f(280.0, 52.0, 270.0);
	glVertex3f(280.0, 52.0, 300.0);


	glVertex3f(320.0, 52.0, 360.0);
	glVertex3f(320.0, 52.0, 330.0);
	glVertex3f(280.0, 52.0, 330.0);
	glVertex3f(280.0, 52.0, 360.0);


	glVertex3f(320.0, 52.0, 400.0);
	glVertex3f(320.0, 52.0, 390.0);
	glVertex3f(280.0, 52.0, 390.0);
	glVertex3f(280.0, 52.0, 400.0);


	//glVertex3f(320.0, 52.0, 380.0);
	//glVertex3f(320.0, 52.0, 360.0);
	//glVertex3f(280.0, 52.0, 360.0);
	//glVertex3f(280.0, 52.0, 380.0);




	glEnd();
	//三
	glBegin(GL_QUAD_STRIP);
	glColor3f(110.0 / 225, 49.0 / 225, 10.0 / 225);
	glVertex3f(600.0, 50.0, 160.0);
	glVertex3f(600.0, 0.0, 160.0);

	glVertex3f(600.0, 50.0, 0.0);
	glVertex3f(600.0, 0.0, 0.0);

	glVertex3f(340.0, 50.0, 0.0);
	glVertex3f(340.0, 0.0, 0.0);

	glVertex3f(340.0, 50.0, 160.0);
	glVertex3f(340.0, 0.0, 160.0);

	glVertex3f(600.0, 50.0, 160.0);
	glVertex3f(600.0, 0.0, 160.0);

	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(600.0, 50.0, 160.0);
	glVertex3f(600.0, 50.0, 0.0);
	glVertex3f(340.0, 50.0, 0.0);
	glVertex3f(340.0, 50.0, 160.0);

	glVertex3f(600.0, 0.0, 160.0);
	glVertex3f(600.0, 0.0, 0.0);
	glVertex3f(340.0, 0.0, 0.0);
	glVertex3f(340.0, 0.0, 160.0);

	glEnd();


	glBegin(GL_QUAD_STRIP);
	glColor3f(110.0 / 225, 49.0 / 225, 10.0 / 225);
	glVertex3f(600.0, 50.0, 400.0);
	glVertex3f(600.0, 0.0, 400.0);

	glVertex3f(600.0, 50.0, 240.0);
	glVertex3f(600.0, 0.0, 240.0);

	glVertex3f(340.0, 50.0, 240.0);
	glVertex3f(340.0, 0.0, 240.0);

	glVertex3f(340.0, 50.0, 400.0);
	glVertex3f(340.0, 0.0, 400.0);

	glVertex3f(600.0, 50.0, 400.0);
	glVertex3f(600.0, 0.0, 400.0);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(600.0, 50.0, 400.0);
	glVertex3f(600.0, 50.0, 240.0);
	glVertex3f(340.0, 50.0, 240.0);
	glVertex3f(340.0, 50.0, 400.0);

	glVertex3f(600.0, 0.0, 400.0);
	glVertex3f(600.0, 0.0, 240.0);
	glVertex3f(340.0, 0.0, 240.0);
	glVertex3f(340.0, 0.0, 400.0);

	glEnd();
	//树1
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-400, -52, -150);
	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(20.0, 0.0, a);
	glVertex3f(20.0, -200.0, a);

	//glColor3f(0.0, 128.0, 0.0);
	glVertex3f(40.0, 0.0, 0);
	glVertex3f(40.0, -200.0, 0.0);

	glColor3f(1.0f, 0.5f, 0.0f);    // orange vextex
	glVertex3f(20.0, 0.0, -a);
	glVertex3f(20.0, -200.0, -a);

	//glColor3f(0.0f, 0.0f, 1.0f);    // blue vertex
	glVertex3f(-20.0, 0.0, -a);
	glVertex3f(-20.0, -200.0, -a);

	glColor3f(1.0f, 0.0f, 0.0f);    // red vextex
	glVertex3f(-40.0, 0.0, 0.0);
	glVertex3f(-40.0, -200.0, 0.0);

	//glColor3f(1.0f, 1.0f, 0.0f);    // yellow vertex
	glVertex3f(-20.0, 0.0, a);
	glVertex3f(-20.0, -200.0, a);

	glColor3f(0.0f, 1.0f, 0.0f);    // green vertex
	glVertex3f(20.0, 0.0, a);
	glVertex3f(20.0, -200.0, a);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);    // blue vertex
	glVertex3f(20.0, -200.0, a);
	glVertex3f(40.0, -200.0, 0.0);
	glVertex3f(20.0, -200.0, -a);
	glVertex3f(-20.0, -200.0, -a);
	glVertex3f(-40.0, -200.0, 0.0);
	glVertex3f(-20.0, -200.0, a);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 1.0f, 1.0f);    // blue vertex
	glVertex3f(20.0, 0.0, a);
	glVertex3f(40.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, -a);
	glVertex3f(-20.0, 0.0, -a);
	glVertex3f(-40.0, 0.0, 0.0);
	glVertex3f(-20.0, 0.0, a);

	glEnd();

	glBegin(GL_TRIANGLE_FAN); // construct a loop lines
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 150.0*sin(M_PI / 3), 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);    // blue vertex
	glVertex3f(60.0, 0.0, 80.0*sin(M_PI / 3));
	glVertex3f(120.0, 0.0, 0.0);
	glVertex3f(60.0, 0.0, -80.0*sin(M_PI / 3));
	glVertex3f(-60.0, 0.0, -80.0*sin(M_PI / 3));
	glVertex3f(-120.0, 0.0, 0.0);
	glVertex3f(-60.0, 0.0, 80.0*sin(M_PI / 3));
	glVertex3f(60.0, 0.0, 80.0*sin(M_PI / 3));
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // construct a loop lines
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 280.0*sin(M_PI / 3), 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);    // blue vertex
	glVertex3f(0.0, 100.0*sin(M_PI / 3), 90.0*sin(M_PI / 3));
	glVertex3f(45.0, 100.0*sin(M_PI / 3), 60.0*sin(M_PI / 3));
	glVertex3f(90.0, 100.0*sin(M_PI / 3), 0.0);
	glVertex3f(45.0, 100.0*sin(M_PI / 3), -60.0*sin(M_PI / 3));
	glVertex3f(0.0, 100.0*sin(M_PI / 3), -90.0*sin(M_PI / 3));
	glVertex3f(-45.0, 100.0*sin(M_PI / 3), -60.0*sin(M_PI / 3));
	glVertex3f(-90.0, 100.0*sin(M_PI / 3), 0.0);
	glVertex3f(-45.0, 100.0*sin(M_PI / 3), 60.0*sin(M_PI / 3));
	//glVertex3f(45.0, 100.0*sin(M_PI / 3), 60.0*sin(M_PI / 3));
	glVertex3f(0.0, 100.0*sin(M_PI / 3), 90.0*sin(M_PI / 3));
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // construct a loop lines
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 320 * sin(M_PI / 3), 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);    // blue vertex
	glVertex3f(30.0, 200.0*sin(M_PI / 3), 50.0*sin(M_PI / 3));
	glVertex3f(60.0, 200.0*sin(M_PI / 3), 0.0);
	glVertex3f(30.0, 200.0*sin(M_PI / 3), -50.0*sin(M_PI / 3));
	glVertex3f(-30.0, 200.0*sin(M_PI / 3), -50.0*sin(M_PI / 3));
	glVertex3f(-60.0, 200.0*sin(M_PI / 3), 0.0);
	glVertex3f(-30.0, 200.0*sin(M_PI / 3), 50.0*sin(M_PI / 3));
	glVertex3f(30.0, 200.0*sin(M_PI / 3), 50.0*sin(M_PI / 3));
	glEnd();
	//树2
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(270, -152, 430);
	glScalef(0.5, 0.5, 0.5);
	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(20.0, 0.0, a);
	glVertex3f(20.0, -200.0, a);

	//glColor3f(0.0, 128.0, 0.0);
	glVertex3f(40.0, 0.0, 0);
	glVertex3f(40.0, -200.0, 0.0);

	glColor3f(1.0f, 0.5f, 0.0f);    // orange vextex
	glVertex3f(20.0, 0.0, -a);
	glVertex3f(20.0, -200.0, -a);

	//glColor3f(0.0f, 0.0f, 1.0f);    // blue vertex
	glVertex3f(-20.0, 0.0, -a);
	glVertex3f(-20.0, -200.0, -a);

	glColor3f(1.0f, 0.0f, 0.0f);    // red vextex
	glVertex3f(-40.0, 0.0, 0.0);
	glVertex3f(-40.0, -200.0, 0.0);

	//glColor3f(1.0f, 1.0f, 0.0f);    // yellow vertex
	glVertex3f(-20.0, 0.0, a);
	glVertex3f(-20.0, -200.0, a);

	glColor3f(0.0f, 1.0f, 0.0f);    // green vertex
	glVertex3f(20.0, 0.0, a);
	glVertex3f(20.0, -200.0, a);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 1.0f);    // blue vertex
	glVertex3f(20.0, -200.0, a);
	glVertex3f(40.0, -200.0, 0.0);
	glVertex3f(20.0, -200.0, -a);
	glVertex3f(-20.0, -200.0, -a);
	glVertex3f(-40.0, -200.0, 0.0);
	glVertex3f(-20.0, -200.0, a);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0f, 1.0f, 1.0f);    // blue vertex
	glVertex3f(20.0, 0.0, a);
	glVertex3f(40.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, -a);
	glVertex3f(-20.0, 0.0, -a);
	glVertex3f(-40.0, 0.0, 0.0);
	glVertex3f(-20.0, 0.0, a);

	glEnd();

	glBegin(GL_TRIANGLE_FAN); // construct a loop lines
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 150.0*sin(M_PI / 3), 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);    // blue vertex
	glVertex3f(60.0, 0.0, 80.0*sin(M_PI / 3));
	glVertex3f(120.0, 0.0, 0.0);
	glVertex3f(60.0, 0.0, -80.0*sin(M_PI / 3));
	glVertex3f(-60.0, 0.0, -80.0*sin(M_PI / 3));
	glVertex3f(-120.0, 0.0, 0.0);
	glVertex3f(-60.0, 0.0, 80.0*sin(M_PI / 3));
	glVertex3f(60.0, 0.0, 80.0*sin(M_PI / 3));
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // construct a loop lines
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 280.0*sin(M_PI / 3), 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);    // blue vertex
	glVertex3f(0.0, 100.0*sin(M_PI / 3), 90.0*sin(M_PI / 3));
	glVertex3f(45.0, 100.0*sin(M_PI / 3), 60.0*sin(M_PI / 3));
	glVertex3f(90.0, 100.0*sin(M_PI / 3), 0.0);
	glVertex3f(45.0, 100.0*sin(M_PI / 3), -60.0*sin(M_PI / 3));
	glVertex3f(0.0, 100.0*sin(M_PI / 3), -90.0*sin(M_PI / 3));
	glVertex3f(-45.0, 100.0*sin(M_PI / 3), -60.0*sin(M_PI / 3));
	glVertex3f(-90.0, 100.0*sin(M_PI / 3), 0.0);
	glVertex3f(-45.0, 100.0*sin(M_PI / 3), 60.0*sin(M_PI / 3));
	//glVertex3f(45.0, 100.0*sin(M_PI / 3), 60.0*sin(M_PI / 3));
	glVertex3f(0.0, 100.0*sin(M_PI / 3), 90.0*sin(M_PI / 3));
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // construct a loop lines
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 320 * sin(M_PI / 3), 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);    // blue vertex
	glVertex3f(30.0, 200.0*sin(M_PI / 3), 50.0*sin(M_PI / 3));
	glVertex3f(60.0, 200.0*sin(M_PI / 3), 0.0);
	glVertex3f(30.0, 200.0*sin(M_PI / 3), -50.0*sin(M_PI / 3));
	glVertex3f(-30.0, 200.0*sin(M_PI / 3), -50.0*sin(M_PI / 3));
	glVertex3f(-60.0, 200.0*sin(M_PI / 3), 0.0);
	glVertex3f(-30.0, 200.0*sin(M_PI / 3), 50.0*sin(M_PI / 3));
	glVertex3f(30.0, 200.0*sin(M_PI / 3), 50.0*sin(M_PI / 3));
	glEnd();
	//孔维超代码
	/*太阳位置*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(255.0, 0.0, 0.0);
	glScalef(55.0f, 105.0 / 1.33333f, 60.0f);
	glTranslatef(-5.0f, 6.0f, 0.0f);
	drawSphere(150.0, 400, 400);
	/*太阳位置结束*/


	/*第一个(最上面)小云彩*/
	/*云朵最大圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0f, 400.0f, 0.0f);
	glScalef(60.0f, 60.0 / 1.33333f, 60.0f);
	drawSphere(150.0, 40, 40);
	/*云朵最大圆结束*/

	/*云朵左面圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-50.0f, 425.0f, 0.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵左面圆结束*/

	/*云朵右上圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(60.0f, 420.0f, 0.0f);
	glScalef(30.0f, 30.0 / 1.33333f, 30.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右上圆结束*/

	/*云朵右下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(60.0f, 405.0f, 0.0f);
	glScalef(30.0f, 30.0 / 1.33333f, 30.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右下圆结束*/

	/*云朵右下下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(45.0f, 380.0f, 0.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右下下圆结束*/

	/*云朵右二上圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(90.0f, 435.0f, 0.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右二上圆结束*/

	/*云朵右二下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(90.0f, 410.0f, 0.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右二下圆结束*/

	/*云朵右三圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(120.0f, 430.0f, 0.0f);
	glScalef(18.0f, 18.0 / 1.33333f, 18.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右三圆结束*/

	/*云朵尾一圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(137.0f, 436.0f, 0.0f);
	glScalef(11.0f, 11.0 / 1.33333f, 11.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾一圆结束*/

	/*云朵尾二圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(145.0f, 439.0f, 0.0f);
	glScalef(5.0f, 5.0 / 1.33333f, 5.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾二圆结束*/

	/*云朵尾三圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(148.0f, 443.0f, 0.0f);
	glScalef(4.0f, 4.0 / 1.33333f, 4.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾三圆结束*/

	/*云朵尾四圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(150.0f, 445.0f, 0.0f);
	glScalef(3.0f, 3.0f / 1.33333, 3.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾四圆结束*/

	/*云朵尾五圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(152.0f, 447.0f, 0.0f);
	glScalef(2.0f, 2.0f / 1.33333, 2.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾五圆结束*/

	/*云朵尾六圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(154.0f, 449.0f, 0.0f);
	glScalef(1.0f, 1.0 / 1.33333f, 1.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾六圆结束*/
	/*第一个小云彩结束*/

	/*第二(最左面)个小云彩*/
	/*云朵最大圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-300.0f, 350.0f, 50.0f);
	glScalef(60.0f, 60.0 / 1.33333f, 60.0f);
	drawSphere(150.0, 40, 40);
	/*云朵最大圆结束*/

	/*云朵左面圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-350.0f, 375.0f, 50.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵左面圆结束*/

	/*云朵右上圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-240.0f, 370.0f, 50.0f);
	glScalef(30.0f, 30.0 / 1.33333f, 30.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右上圆结束*/

	/*云朵右下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-240.0f, 355.0f, 50.0f);
	glScalef(30.0f, 30.0 / 1.33333f, 30.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右下圆结束*/

	/*云朵右下下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-255.0f, 330.0f, 50.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右下下圆结束*/

	/*云朵右二上圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-210.0f, 385.0f, 50.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右二上圆结束*/

	/*云朵右二下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-210.0f, 360.0f, 50.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右二下圆结束*/

	/*云朵右三圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-180.0f, 380.0f, 50.0f);
	glScalef(18.0f, 18.0 / 1.33333f, 18.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右三圆结束*/

	/*云朵尾一圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-163.0f, 386.0f, 50.0f);
	glScalef(11.0f, 11.0 / 1.33333f, 11.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾一圆结束*/

	/*云朵尾二圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-155.0f, 389.0f, 50.0f);
	glScalef(5.0f, 5.0 / 1.33333f, 5.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾二圆结束*/

	/*云朵尾三圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-152.0f, 393.0f, 50.0f);
	glScalef(4.0f, 4.0 / 1.33333f, 4.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾三圆结束*/

	/*云朵尾四圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-150.0f, 395.0f, 50.0f);
	glScalef(3.0f, 3.0f / 1.33333, 3.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾四圆结束*/

	/*云朵尾五圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-148.0f, 397.0f, 50.0f);
	glScalef(2.0f, 2.0f / 1.33333, 2.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾五圆结束*/

	/*云朵尾六圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-146.0f, 399.0f, 50.0f);
	glScalef(1.0f, 1.0 / 1.33333f, 1.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾六圆结束*/
	/*第二个小云彩结束*/


	/*第三个(最下面)小云彩*/
	/*云朵最大圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-70.0f, 300.0f, -50.0f);
	glScalef(60.0f, 60.0 / 1.33333f, 60.0f);
	drawSphere(150.0, 40, 40);
	/*云朵最大圆结束*/

	/*云朵左面圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-120.0f, 325.0f, -50.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵左面圆结束*/

	/*云朵右上圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-10.0f, 320.0f, -50.0f);
	glScalef(30.0f, 30.0 / 1.33333f, 30.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右上圆结束*/

	/*云朵右下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-10.0f, 305.0f, -50.0f);
	glScalef(30.0f, 30.0 / 1.33333f, 30.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右下圆结束*/

	/*云朵右下下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-25.0f, 280.0f, -50.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右下下圆结束*/

	/*云朵右二上圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(20.0f, 335.0f, -50.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右二上圆结束*/

	/*云朵右二下圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(20.0f, 310.0f, -50.0f);
	glScalef(25.0f, 25.0 / 1.33333f, 25.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右二下圆结束*/

	/*云朵右三圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(50.0f, 330.0f, -50.0f);
	glScalef(18.0f, 18.0 / 1.33333f, 18.0f);
	drawSphere(150.0, 40, 40);
	/*云朵右三圆结束*/

	/*云朵尾一圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(67.0f, 336.0f, -50.0f);
	glScalef(11.0f, 11.0 / 1.33333f, 11.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾一圆结束*/

	/*云朵尾二圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(75.0f, 339.0f, -50.0f);
	glScalef(5.0f, 5.0 / 1.33333f, 5.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾二圆结束*/

	/*云朵尾三圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(78.0f, 343.0f, -50.0f);
	glScalef(4.0f, 4.0 / 1.33333f, 4.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾三圆结束*/

	/*云朵尾四圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(80.0f, 345.0f, -50.0f);
	glScalef(3.0f, 3.0f / 1.33333, 3.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾四圆结束*/

	/*云朵尾五圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(82.0f, 347.0f, -50.0f);
	glScalef(2.0f, 2.0f / 1.33333, 2.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾五圆结束*/

	/*云朵尾六圆*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(84.0f, 349.0f, -50.0f);
	glScalef(1.0f, 1.0 / 1.33333f, 1.0f);
	drawSphere(150.0, 40, 40);
	/*云朵尾六圆结束*/
	/*第三个小云彩结束*/

	/*烟雾*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(61.0, 92.0, 92.0);
	glTranslatef(250.0f, 220.0f, -100.0f);
	glScalef(50.0f, 50.0 / 1.33333f, 50.0f);
	//底部开始
	drawSphere(150.0, 40, 40);

	glTranslatef(0.25f, 0.0f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.25f, 0.0f, 0.0f);
	drawSphere(150.0, 40, 40);
	//底部结束
	//第二层开始
	glTranslatef(-0.25f, 1.5f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.3f, -0.2f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.5f, -0.2f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.5f, -0.2f, 0.0f);
	drawSphere(150.0, 40, 40);
	//第二层结束
	//第三层开始
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(61.0, 92.0, 92.0);
	glTranslatef(284.0f, 345.0f, -100.0f);
	glScalef(65.0f, 65.0 / 1.33333f, 65.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.5f, -0.25f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.5f, -0.25f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.5f, -0.25f, 0.0f);
	drawSphere(150.0, 40, 40);

	//第三层结束
	//第四层开始
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(61.0, 92.0, 92.0);
	glTranslatef(284.0f, 365.0f, -100.0f);
	glScalef(65.0f, 65.0 / 1.33333f, 65.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(1.0f, 0.25f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.5f, -0.2f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.5f, -0.2f, 0.0f);
	drawSphere(150.0, 40, 40);

	glTranslatef(0.5f, -0.2f, 0.0f);
	drawSphere(150.0, 40, 40);

	//第四层结束
	//第五层
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(61.0, 92.0, 92.0);
	glTranslatef(304.0f, 385.0f, -100.0f);
	glScalef(65.0f, 65.0 / 1.33333f, 65.0f);
	drawSphere(150.0, 40, 40);
	//第五层结束
	//第六层
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(61.0, 92.0, 92.0);
	glTranslatef(334.0f, 395.0f, -100.0f);
	glScalef(65.0f, 65.0 / 1.33333f, 65.0f);
	drawSphere(150.0, 40, 40);
	//第六层结束
	//第七层
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(61.0, 92.0, 92.0);
	glTranslatef(354.0f, 394.0f, -100.0f);
	glScalef(65.0f, 65.0 / 1.33333f, 65.0f);
	drawSphere(150.0, 40, 40);
	//第七层结束
	//第八层
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glColor3f(61.0, 92.0, 92.0);
	glTranslatef(364.0f, 394.0f, -100.0f);
	glScalef(65.0f, 65.0 / 1.33333f, 65.0f);
	drawSphere(150.0, 40, 40);
	//第八层结束
	/*烟雾结束*/

	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glLoadIdentity();//车身
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glTranslatef(transfer_x, transfer_y, transfer_z);
	glScalef(scale_change, scale_change, scale_change);
	glTranslatef(-450.0f, -212.0f, 200.0f);
	glScalef(2.0, 2.0, 2.0);
	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(160.0, 20.0, 60.0);
	glVertex3f(160.0, 0.0, 60.0);

	glVertex3f(160.0, 20.0, 0.0);
	glVertex3f(160.0, 0.0, 0.0);

	glVertex3f(0.0, 20.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glVertex3f(0.0, 20.0, 60.0);
	glVertex3f(0.0, 0.0, 60.0);

	glVertex3f(160.0, 20.0, 60.0);
	glVertex3f(160.0, 0.0, 60.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(160.0, 0.0, 60.0);
	glVertex3f(160.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 60.0);

	glVertex3f(160.0, 20.0, 60.0);
	glVertex3f(160.0, 20.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);
	glVertex3f(0.0, 20.0, 60.0);

	glEnd();
	//车盖
	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(110.0, 50.0, 60.0);
	glVertex3f(130.0, 20.0, 60.0);

	glVertex3f(110.0, 50.0, 0.0);
	glVertex3f(130.0, 20.0, 0.0);

	glVertex3f(50.0, 50.0, 0.0);
	glVertex3f(30.0, 20.0, 0.0);

	glVertex3f(50.0, 50.0, 60.0);
	glVertex3f(30.0, 20.0, 60.0);

	glVertex3f(110.0, 50.0, 60.0);
	glVertex3f(130.0, 20.0, 60.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(130.0, 20.0, 60.0);
	glVertex3f(130.0, 20.0, 0.0);
	glVertex3f(30.0, 20.0, 0.0);
	glVertex3f(30.0, 20.0, 60.0);

	glVertex3f(110.0, 50.0, 60.0);
	glVertex3f(110.0, 50.0, 0.0);
	glVertex3f(50.0, 50.0, 0.0);
	glVertex3f(50.0, 50.0, 60.0);

	glEnd();




	//里侧轮胎
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i <= 360; i++) {
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 30, 10 * sin(2 * 3.14 / 360 * i) - 10, 0);
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 30, 10 * sin(2 * 3.14 / 360 * i) - 10, 10);
		glVertex3f(10 * cos(2 * 3.14 / 360 * (i + 1)) + 30, 10 * sin(2 * 3.14 / 360 * (i + 1)) - 10, 10);
		glVertex3f(10 * cos(2 * 3.14 / 360 * (i + 1)) + 30, 10 * sin(2 * 3.14 / 360 * (i + 1)) - 10, 0);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(30.0, -10.0, 10.0);
	for (int i = 0; i <= 360; i++)
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 30, 10 * sin(2 * 3.14 / 360 * i) - 10, 10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i <= 360; i++) {
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 130, 10 * sin(2 * 3.14 / 360 * i) - 10, 0);
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 130, 10 * sin(2 * 3.14 / 360 * i) - 10, 10);
		glVertex3f(10 * cos(2 * 3.14 / 360 * (i + 1)) + 130, 10 * sin(2 * 3.14 / 360 * (i + 1)) - 10, 10);
		glVertex3f(10 * cos(2 * 3.14 / 360 * (i + 1)) + 130, 10 * sin(2 * 3.14 / 360 * (i + 1)) - 10, 0);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(130.0, -10.0, 10.0);
	for (int i = 0; i <= 360; i++)
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 130, 10 * sin(2 * 3.14 / 360 * i) - 10, 10.0);
	glEnd();



	//外侧轮胎
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i <= 360; i++) {
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 30, 10 * sin(2 * 3.14 / 360 * i) - 10, 0 + 50);
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 30, 10 * sin(2 * 3.14 / 360 * i) - 10, 10 + 50);
		glVertex3f(10 * cos(2 * 3.14 / 360 * (i + 1)) + 30, 10 * sin(2 * 3.14 / 360 * (i + 1)) - 10, 10 + 50);
		glVertex3f(10 * cos(2 * 3.14 / 360 * (i + 1)) + 30, 10 * sin(2 * 3.14 / 360 * (i + 1)) - 10, 0 + 50);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(30.0, -10.0, 60.0);
	for (int i = 0; i <= 360; i++)
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 30, 10 * sin(2 * 3.14 / 360 * i) - 10, 60.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i <= 360; i++) {
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 130, 10 * sin(2 * 3.14 / 360 * i) - 10, 50);
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 130, 10 * sin(2 * 3.14 / 360 * i) - 10, 10 + 50);
		glVertex3f(10 * cos(2 * 3.14 / 360 * (i + 1)) + 130, 10 * sin(2 * 3.14 / 360 * (i + 1)) - 10, 10 + 50);
		glVertex3f(10 * cos(2 * 3.14 / 360 * (i + 1)) + 130, 10 * sin(2 * 3.14 / 360 * (i + 1)) - 10, 50);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(130.0, -10.0, 60.0);
	for (int i = 0; i <= 360; i++)
		glVertex3f(10 * cos(2 * 3.14 / 360 * i) + 130, 10 * sin(2 * 3.14 / 360 * i) - 10, 60.0);
	glEnd();


	//车窗
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(100.0, 25.0, 61.0);
	glVertex3f(100.0, 45.0, 61.0);
	glVertex3f(60.0, 45.0, 61.0);
	glVertex3f(60.0, 25.0, 61.0);

	glVertex3f(100.0, 25.0, -1.0);
	glVertex3f(100.0, 45.0, -1.0);
	glVertex3f(60.0, 45.0, -1.0);
	glVertex3f(60.0, 25.0, -1.0);

	glVertex3f(32.0, 25.0, 55.0);
	glVertex3f(48.0, 48.0, 55.0);
	glVertex3f(48.0, 48.0, 5.0);
	glVertex3f(32.0, 25.0, 5.0);

	glVertex3f(112.0, 25.0, 55.0);
	glVertex3f(128.0, 48.0, 55.0);
	glVertex3f(128.0, 48.0, 5.0);
	glVertex3f(112.0, 25.0, 5.0);

	glEnd();
	glutSwapBuffers();
	//glFlush();  // drawing the object to screen
	glDisable(GL_TEXTURE_2D);
}

/*  Initialization
*/
void init(void)
{
	cout << "The OpenGL version is: " << glGetString(GL_VERSION) << "\n";
	cout << glGetString(GL_VENDOR) << "\n";

	glLineWidth(5);
	glClearColor(0.0, 0.0, 0.0, 0.0);  // select background color
	glMatrixMode(GL_PROJECTION); // places the camera at (0,0,0) and faces it along(0,0,-1).
								 // glMatrixMode(GL_MODELVIEW);  // what is the difference?
	glLoadIdentity();

	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -d / 2, d / 2); // specify clipping volume
														  //glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); // specify coordinate system
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat qaDiffuseLight[] = { 1.0, 1.0, 1.0, 1.0 };//white light
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	GLfloat qaLightPosition[] = { 400.0, 150.0,100.0, 0.0 };//矢量发射方向。
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}
// specialKeys() Callback Function
void specialKeys(int key, int x, int y) {
	//  Right arrow - increase rotation by 1 degree
	if (key == GLUT_KEY_RIGHT) 		transfer_x -= 10;//右键，感觉人右移动
													 //  Left arrow - decrease rotation by 1 degree
	else if (key == GLUT_KEY_LEFT) 		transfer_x += 10;//左键，感觉人左移动
	else if (key == GLUT_KEY_UP) { scale_change += 0.01; transfer_z += 10; }//前进，相当于放大然后前进
	else if (key == GLUT_KEY_DOWN) { if (scale_change > 0)	scale_change -= 0.01; transfer_z -= 10; }//后退相当于缩小然后后退
	else if (key == GLUT_KEY_F1) rotate_x += 5;//F1沿着x轴正方向转5度//转的方向右手螺旋定则
	else if (key == GLUT_KEY_F2) rotate_x -= 5;//F2沿着x轴逆方向转5度
	else if (key == GLUT_KEY_F3) rotate_y += 5;//F3沿着y轴正方向转5度
	else if (key == GLUT_KEY_F4) rotate_y -= 5;//F4沿着y轴逆方向转5度
	else if (key == GLUT_KEY_F5) rotate_z += 5;//F5沿着z轴正方向转5度
	else if (key == GLUT_KEY_F6) rotate_z -= 5;//F6沿着z轴逆方向转5度
	else if (key == GLUT_KEY_F7) transfer_y += 5;//F7沿着y轴正向移动5个单位
	else if (key == GLUT_KEY_F8) transfer_y -= 5;//F8沿着y轴逆向移动5个单位
												 //  Request display update
	glutPostRedisplay();
}

char* filename = "./huanjing.bmp";
char* filename1 = "./wuxi.bmp";
char* filename2 = "./gezi.bmp";
char* filename3 = "./tile.bmp";
char* filename4 = "./thankyou.bmp";

int main(int argc, char** argv)
{
	glutInit(&argc, argv);//Initialize GLUT and process user parameters
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//Request double buffered true color window with Z-buffer
	glutInitWindowSize(w, h);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Project");// Create window

	loadTextureFromFile(filename);
	loadTextureFromFile1(filename1);
	loadTextureFromFile2(filename2);
	loadTextureFromFile3(filename3);
	loadTextureFromFile4(filename4);
	init();
	glEnable(GL_COLOR_MATERIAL);//光照颜色
	glLightModeli(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_DEPTH_TEST);// Enable Z-buffer depth test 
							//glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}