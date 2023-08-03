#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

// we initialize our pointer of the class TextureHolder type to nullptr
TextureHolder* TextureHolder::m_s_Instance = nullptr;

// constructeur: ensures that m_s_Instance equals nullptr. sinon quitte le constructeur (assert)
TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	// assigns the pointer to this instance. le pointeur pointe l'objet instancié.
	// Donc, effectivement, nous avons maintenant un pointeur vers un
	// TextureHolder qui pointe vers la seule et unique instance de lui - même.
	// this is A singleton that is a design pattern
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	// Get a reference to m_Textures using m_S_Instance
	auto& m = m_s_Instance->m_Textures;
	// auto is the equivalent of map<string, Texture>

	// Create an iterator to hold a key-value-pair (kvp)
	// and search for the required kvp
	// using the passed in file name
	auto keyValuePair = m.find(filename);
	// auto is equivelant of map<string, Texture>::iterator
	
		
	// Did we find a match?
	if (keyValuePair != m.end())
	{
		// Yes
		// Return the texture,
		// the second part of the kvp, the texture
		return keyValuePair->second;
	}
	else
	{
		// File name not found
		// Create a new key value pair using the filename
		auto& texture = m[filename];
		// Load the texture from file in the usual way
		texture.loadFromFile(filename);

		// Return the texture to the calling code
		return texture;
	}
}