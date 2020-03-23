#include "NamePlayer.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

sf::String PlayerInput;
sf::Text PlayerText;
sf::Event event;



NamePlayer::NamePlayer(StateStack & stack, Context context) :State(stack, context), mGUIContainer()
{
	mBackgroundSprite.setTexture(context.textures->get(TextureID::TitleScreen));
	PlayerText.setPosition(60, 300);
	PlayerText.setFillColor(sf::Color::White);
	if (event.type == sf::Event::TextEntered)
	{
		
		PlayerInput += event.text.unicode;
		PlayerText.setString(PlayerInput);
	}

		

	auto backButton = std::make_shared<GUI::Button>(context);
	backButton->setPosition(80.f, 620.f);
	backButton->setText("Back");
	backButton->setCallback(std::bind(&NamePlayer::requestStackPop, this));

	mGUIContainer.pack(backButton);
}

void NamePlayer::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
	window.draw(PlayerText);
}

bool NamePlayer::update(sf::Time dt)
{
	return true;
}

bool NamePlayer::handleEvent(const sf::Event & event)
{
	mGUIContainer.handleEvent(event);
	return false;
}
