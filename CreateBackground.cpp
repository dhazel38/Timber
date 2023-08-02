#include <SFML/Graphics.hpp>
#include "ZombieArena.h"

int createBackground(VertexArray& rVA, IntRect arena)
{
	// Anything we do to rVA we are actually doing to background (in the main function)

	// How big is each tile/texture (50 x 200 to png)
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4; // always 4 in quad

	int worldWidth = arena.width / TILE_SIZE; // arena.width=500, in example worldWidth=10
	int worldHeight = arena.height / TILE_SIZE;

	// What type of primitive are we using?
	rVA.setPrimitiveType(Quads);

	// Set the size of the vertex array
	rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;

	for (int w = 0; w < worldWidth; w++)
	{
		for (int h = 0; h < worldHeight; h++)
		{
			// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);// 0,0
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);//50,0
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);// 50,50
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);// 0,50

			// Define the position in the Texture to draw for current quad
			// Either mud, stone, grass or wall
			// cree une bordure
			if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1)
			{
				// Use the wall texture
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);//0,150
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);//50,150
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);//50,150
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);//0,150
			}
			else
			{
				// Use a random floor texture
				srand((int)time(0) + h * w - h);
				int mOrG = (rand() % TILE_TYPES);// 0,1,2
				int verticalOffset = mOrG * TILE_SIZE;// 0 to 100

				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);

			}

			// Position ready for the next for vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	return TILE_SIZE;
}