#pragma once
#include "ResourceHolder.h"

enum class FontID { JetBrainsMono };

using FontHolder = ResourceHolder<sf::Font, FontID>;