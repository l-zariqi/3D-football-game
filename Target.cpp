#include "Target.h"

Target::Target(GLuint tex, int score) : TexturedPlane(tex), m_score(score), m_originalTexture(tex), m_hit(false)
{
}

Target::Target(GLuint tex, int score, float r) : TexturedPlane(tex), m_score(score), m_originalTexture(tex), m_hit(false)
{
	transform.scale = { r*2,r*2,r*2 };
}

Target::Target(GLuint tex, int score, float r, float x, float y, float z): TexturedPlane(tex, x, y, z), m_score(score), m_originalTexture(tex), m_hit(false)
{
	transform.scale = { r * 2,r * 2,r * 2 };
}

int Target::getScore() const
{
	return m_score;
}

void Target::hit(GLuint newTexture) // if ran it switches the texture and sets hit target to boolean true
{
	m_texture = newTexture;
	m_hit = true;
}

bool Target::isHit() const
{
	return m_hit;
}

void Target::reset() // resets to original texture and sets hit to boolean false
{
	m_texture = m_originalTexture;
	m_hit = false;
}
