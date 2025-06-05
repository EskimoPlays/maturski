#pragma once
#include "ResourceHolder.h"

enum class ShaderID { Light };

using ShaderHolder = ResourceHolder<sf::Shader, ShaderID>;