#include "Material.h"
#include "Texture.h"
#include "Utilities.h"

Material::Material(Texture* texture)
	:	texture(texture)
{
}

Material::~Material()
{
	Memory::safeDelete(texture);
}

Color Material::color(const Vertex& v)
{
	if(texture == nullptr)
	{
		return v.color;
	}
	else
	{
		return texture->sample(v.texCoord.x, v.texCoord.y, MIPLEVEL);
	}
}
