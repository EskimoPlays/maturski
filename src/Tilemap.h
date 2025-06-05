#pragma once
#include "SFML/Graphics.hpp"

class Tilemap : public sf::Drawable, public sf::Transformable {
public:
	void load(const sf::Texture& tileset,sf::Vector2u tileSize,
		const int* level,unsigned int width,unsigned height);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::VertexArray m_Vertices;
	const sf::Texture* m_Tileset = nullptr;
};
