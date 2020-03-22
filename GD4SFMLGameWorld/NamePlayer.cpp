#include "NamePlayer.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

NamePlayer::NamePlayer(StateStack & stack, Context context) :State(stack, context), mGUIContainer()
{
	mBackgroundSprite.setTexture(context.textures->get(TextureID::TitleScreen));
}

void NamePlayer::draw()
{
}

bool NamePlayer::update(sf::Time dt)
{
	return false;
}

bool NamePlayer::handleEvent(const sf::Event & event)
{
	return false;
}
