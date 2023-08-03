#pragma once
#include <SFML/Graphics.hpp>

/*
* Rammassage de vie ou de munitions
* We need our pickups to be upgradeable so that the
* player is forced to develop a strategy to progress through the waves.
* Nous avons besoin que nos ramassages soient évolutifs afin que le
* joueur soit obligé de développer une stratégie pour progresser à travers les vagues.
*/

using namespace sf;

class Pickup
{
private:
	//Start value for health pickups
	const int HEALTH_START_VALUE = 50; // la valeur de départ de tous les prélèvements de vie.
	const int AMMO_START_VALUE = 12; // la valeur de départ de tous les ramassages de munitions
	const int START_WAIT_TIME = 10; // combien de temps un pick-up attendra avant de réapparaître après avoir disparu.
	const int START_SECONDS_TO_LIVE = 5; // combien de temps durera un ramassage entre le spawn et le non-spawn

	// The sprite that represents this pickup
	Sprite m_Sprite;

	// The arena it exists in
	IntRect m_Arena;

	// How much is this pickup worth?
	int m_Value;

	// What type of pickup is this? 
	// 1 = health, 2 = ammo
	int m_Type;

	// Handle spawning and disappearing
	bool m_Spawned;  // Le pick-up est-il actuellement généré
	float m_SecondsSinceSpawn; // Depuis combien de temps le ramassage a-t-il été engendré ?
	float m_SecondsSinceDeSpawn; // Depuis combien de temps le pick-up a-t-il disparu ?
	float m_SecondsToLive;
	float m_SecondsToWait;

	// Public prototypes go here
public:

	Pickup(int type);

	// Prepare a new pickup
	void setArena(IntRect arena);

	void spawn();

	// Check the position of a pickup
	FloatRect getPosition();

	// Get the sprite for drawing
	Sprite getSprite();

	// Let the pickup update itself each frame
	void update(float elapsedTime);

	// Is this pickup currently spawned?
	// Ce pick-up est-il actuellement généré (visible) ?
	bool isSpawned();

	// Get the goodness from the pickup
	int gotIt();

	// Upgrade the value of each pickup
	void upgrade();

};



