#pragma once
#include "ResourceHolder.h"

enum class TextureID { PlayerSheet, Tilemap };

using TextureHolder = ResourceHolder<sf::Texture, TextureID>;