//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************			Cano Olguin Luis Sergio			******//
//*************			Visual 	Studio					******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
char s[30];

CCamera objCamera;	//Crear objeto Camara

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture t_arbol;//arbol
CTexture t_hojas;//hojas
CTexture t_esfera;//esfera
CTexture t_esfera1;//esfera
CTexture t_esfera2;//esfera
CTexture t_esfera3;//esfera
CTexture t_esfera4;//esfera
CTexture t_madera;
CTexture t_fachada;
CTexture t_muro;
CTexture t_muro2;
CTexture t_muro3;
CTexture t_muro31;
CTexture t_piso;
CTexture t_techo;
CTexture t_tronco;


CTexture tree;
CTexture edificio;

CFiguras cubo;
CFiguras sky;

CFiguras objeto1;
CFiguras objeto2;
CFiguras objeto3;


//END NEW//////////////////////////////////////////


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

void ciudad ()
{

		glPushMatrix(); //Camino1
			glTranslatef(23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Camino2
			glTranslatef(-23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,7.0);
			glRotatef(90,1,0,0);
			glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,-7.0);
			glRotatef(90,1,0,0);
			//glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();
}

void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, t_fachada.GLindex);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glRotatef(90,0.0,1.0,0.0);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBindTexture(GL_TEXTURE_2D, t_muro.GLindex); 
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, t_muro2.GLindex); 
		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, t_muro3.GLindex);
		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, t_piso.GLindex);
		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, t_techo.GLindex);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}


void prisma1 (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glRotatef(90,0.0,1.0,0.0);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBindTexture(GL_TEXTURE_2D, textura2); 
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, textura1); 
		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, t_muro31.GLindex);
		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);			
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textura2);
		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, t_muro31.GLindex);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}


void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	t_arbol.LoadTGA("Arbol.tga");
	t_arbol.BuildGLTexture();
	t_arbol.ReleaseImage();

	t_hojas.LoadTGA("Hojas.tga");
	t_hojas.BuildGLTexture();
	t_hojas.ReleaseImage();

	t_esfera.LoadTGA("Esfera1.tga");
	t_esfera.BuildGLTexture();
	t_esfera.ReleaseImage();

	t_esfera1.LoadTGA("Esfera2.tga");
	t_esfera1.BuildGLTexture();
	t_esfera1.ReleaseImage();

	t_esfera2.LoadTGA("Esfera3.tga");
	t_esfera2.BuildGLTexture();
	t_esfera2.ReleaseImage();

	t_esfera3.LoadTGA("Esfera4.tga");
	t_esfera3.BuildGLTexture();
	t_esfera3.ReleaseImage();

	t_esfera4.LoadTGA("Esfera5.tga");
	t_esfera4.BuildGLTexture();
	t_esfera4.ReleaseImage();

	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	edificio.LoadTGA("edificio.tga");
	edificio.BuildGLTexture();
	edificio.ReleaseImage();

	t_madera.LoadTGA("madera.tga");
	t_madera.BuildGLTexture();
	t_madera.ReleaseImage();

	t_techo.LoadTGA("techo.tga");
	t_techo.BuildGLTexture();
	t_techo.ReleaseImage();

	t_fachada.LoadTGA("fachada.tga");
	t_fachada.BuildGLTexture();
	t_fachada.ReleaseImage();
	
	t_muro.LoadTGA("muro.tga");
	t_muro.BuildGLTexture();
	t_muro.ReleaseImage();

	t_muro3.LoadTGA("muro3.tga");
	t_muro3.BuildGLTexture();
	t_muro3.ReleaseImage();

	t_muro31.LoadTGA("muro31.tga");
	t_muro31.BuildGLTexture();
	t_muro31.ReleaseImage();

	t_muro2.LoadTGA("muro2.tga");
	t_muro2.BuildGLTexture();
	t_muro2.ReleaseImage();

	t_piso.LoadTGA("piso.tga");
	t_piso.BuildGLTexture();
	t_piso.ReleaseImage();

	t_tronco.LoadTGA("tronco.tga");
	t_tronco.BuildGLTexture();
	t_tronco.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-7.0,0.0,-7.0);
			//glDisable(GL_LIGHTING);
				//glColor3f(0.0,0.0,0.0);
				objeto2.cilindro(0.3,2.0,30.0,t_arbol.GLindex);
				//glRotatef(,,);
				glColor3f(0.0,1.0,0.0);
				glTranslatef(0.0,2.0,0.0);
				objeto1.cono(7.0,1.0,30.0,t_hojas.GLindex);
				//esfera
				glPushMatrix();
				glColor3f(1.0,1.0,1.0);
					glTranslatef(1.0,1.0,0.0);
					glEnable(GL_ALPHA_TEST);//transpariencia
					glAlphaFunc(GL_GREATER,0.1);
					objeto3.esfera(0.2,20,20,t_esfera.GLindex);					
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();
				//esfera
				glPushMatrix();
				//glColor3f(1.0,0.0,0.0);
					glTranslatef(-1.0,1.0,0.0);
					glEnable(GL_ALPHA_TEST);//transpariencia
					glAlphaFunc(GL_GREATER,0.1);
					objeto3.esfera(0.2,20,20,t_esfera1.GLindex);
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();
				//esfera
				glPushMatrix();
				//glColor3f(1.0,0.0,0.0);
					glTranslatef(0.0,1.0,-1.0);
					glEnable(GL_ALPHA_TEST);//transpariencia
					glAlphaFunc(GL_GREATER,0.1);
					objeto3.esfera(0.2,20,20,t_esfera2.GLindex);
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();
				//esfera
				glPushMatrix();
				//glColor3f(1.0,.0,0.0);
					glTranslatef(0.0,1.0,1.0);
					glEnable(GL_ALPHA_TEST);//transpariencia
					glAlphaFunc(GL_GREATER,0.1);
					objeto3.esfera(0.2,20,20,t_esfera3.GLindex);
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();
				//esfera
				glPushMatrix();
				//glColor3f(1.0,0.0,0.0);
					glTranslatef(0.0,7.0,0.0);
					glEnable(GL_ALPHA_TEST);//transpariencia
					glAlphaFunc(GL_GREATER,0.1);
					objeto3.esfera(0.3,20,20,t_esfera4.GLindex);
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();
			glPopMatrix();


		glPushMatrix();

		glTranslatef(6.0,2.0,-6.5);
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0,4.0,4.0); 
			glEnable(GL_ALPHA_TEST);//transpariencia
			glAlphaFunc(GL_GREATER,0.1);	
			prisma(t_tronco.GLindex, t_muro2.GLindex);
			glDisable(GL_ALPHA_TEST);			
		glPopMatrix();
				
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0,2.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5,2.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0,2.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.5,2.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.5,2.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-1.0,2.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-1.5,2.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.25,2.75, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.75,2.75, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.25,2.75, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.25,2.75, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.75,2.75, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-1.25,2.75, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.5,3.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-1.0,3.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0,3.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5,3.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0,3.25, 0.0);
			glScalef(0.5,0.5,4.0);  
			prisma1(t_tronco.GLindex, t_muro2.GLindex);
		glPopMatrix();
		glPopMatrix();

			glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					glCallList(ciudad_display_list);
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();
			
			glPushMatrix(); //Flecha
				glScalef(7,0.1,7);
				glDisable(GL_LIGHTING);
				fig3.prisma_anun(text3.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glEnable ( GL_COLOR_MATERIAL );
			/*glPushMatrix();
				glTranslatef(-30, 0, 10);
				arbol();
			glPopMatrix();*/

			glPushMatrix();
				glTranslatef(17, 0, -10);
				glColor3f(1.0, 1.0, 1.0);
				fig1.esfera(4, 20, 20, text2.GLindex);
			glPopMatrix();

			glColor3f(1.0,1.0,1.0);

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	
		fig3.text_izq-= 0.001;
		fig3.text_der-= 0.001;
		if(fig3.text_izq<-1)
			fig3.text_izq=0;
		if(fig3.text_der<0)
			fig3.text_der=1;


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
