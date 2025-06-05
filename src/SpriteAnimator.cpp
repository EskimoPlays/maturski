#include "SpriteAnimator.h"

SpriteAnimator::SpriteAnimator(sf::Sprite& sprite, int frameWidth,
	int frameHeight, int framesPerDirection, float frameTime):
	m_Sprite(sprite),m_FrameWidth(frameWidth),m_FrameHeight(frameHeight),
	m_FramesPerDirection(framesPerDirection),m_FrameTime(frameTime){}

void SpriteAnimator::update(sf::Time dt) {
	if (shouldAdvanceFrame(dt)) {
		setUpNextFrame();
	}
}

void SpriteAnimator::setDirection(Direction newDirection) {
	if (m_CurrentDirection != newDirection) {
		m_CurrentDirection = newDirection;
		m_CurrentFrame = 0;
	}
}

bool SpriteAnimator::shouldAdvanceFrame(sf::Time dt) {
	m_ElapsedTime += dt.asSeconds();
	if (m_ElapsedTime < m_FrameTime) {
		return false;
	}
	m_ElapsedTime = 0.f;
	return true;
}

void SpriteAnimator::setUpCurrentFrame() {
	auto currentRect = sf::IntRect({ m_CurrentFrame * m_FrameWidth,
		m_CurrentDirection * m_FrameHeight }, { m_FrameWidth, m_FrameHeight });
	m_Sprite.setTextureRect(currentRect);
}

void SpriteAnimator::setUpNextFrame() {
	m_CurrentFrame = (m_CurrentFrame + 1) % m_FramesPerDirection;
	setUpCurrentFrame();
}

void SpriteAnimator::setDefaultTexture() {
	m_CurrentFrame = 1;
	setUpCurrentFrame();
}

int SpriteAnimator::getFrameWidth() const {
	return m_FrameWidth;
}

int SpriteAnimator::getFrameHeight() const {
	return m_FrameHeight;
}