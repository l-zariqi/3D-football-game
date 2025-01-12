#include "Wall.h"

Wall::Wall(GLuint tex) : GameObject(), m_texture(tex)
{
	scale(5);
	transform.scale.z *= 5;	
}

Wall::Wall(GLuint tex, float x, float y, float z) : GameObject(x, y, z), m_texture(tex)
{
	scale(5);
	transform.scale.z *= 5;
}

void Wall::draw()
{
	glPushMatrix();
	//add some lighting normals for each vertex
	//draw the texture on the front
	glEnable(GL_TEXTURE_2D);
	glColor3f(0.8, 0.8, 0.8);
	glEnable(GL_TEXTURE_2D);

	// translates to object position
	glTranslatef(transform.position.x, transform.position.y, transform.position.z);
	glRotatef(transform.rotation.x, 1, 0, 0);
	glRotatef(transform.rotation.y, 0, 1, 0);
	glRotatef(transform.rotation.z, 0, 0, 1);

	// binds texture 
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glBegin(GL_QUAD_STRIP); // maps the brick texture to a four strip
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-transform.scale.x / 2, -transform.scale.y / 2, transform.scale.z /2);
	glTexCoord3f(0.9, 0.0, 0.0);
	glVertex3f(transform.scale.x / 2, -transform.scale.y / 2, transform.scale.z / 2);
	glTexCoord2f(0.0, 0.9);
	glVertex3f(-transform.scale.x / 2, transform.scale.y / 2, transform.scale.z / 2);
	glTexCoord2f(0.9, 0.9);
	glVertex3f(transform.scale.x / 2, transform.scale.y / 2, transform.scale.z / 2);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-transform.scale.x / 2, transform.scale.y / 2, -transform.scale.z / 2);
	glTexCoord2f(0.9, 1.0);
	glVertex3f(transform.scale.x / 2, transform.scale.y / 2, -transform.scale.z / 2);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
