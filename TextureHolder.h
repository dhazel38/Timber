#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;

/*
* ajout ifndef sur un singleton
*/

// support de texture
class TextureHolder
{
public:
	TextureHolder();
	// returns a reference to a Texture. 
	// a string as a constant reference, as a parameter. La référence est
	// constante, elle ne peut pas être modifiée.
	static Texture& GetTexture(std::string const& filename);

private:
	// A map container from the STL,
	// that holds related pairs of String and Texture
	std::map<std::string, sf::Texture> m_Textures;

	// A pointer of the same type as the class itself
	// the one and only instance
	static TextureHolder* m_s_Instance;
};

#endif