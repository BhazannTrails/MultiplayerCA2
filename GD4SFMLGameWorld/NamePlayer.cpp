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
	sf::RenderWindow& window = *getContext().window;
	//sf::RenderWindow window(sf::VideoMode(1180, 600), "PANZER_WAR:TPL_GAME", sf::Style::None);
	sf::Font font;
	mBackgroundSprite.setTexture(context.textures->get(TextureID::TitleScreen));
	/*PlayerText.setPosition(300, 300);
	PlayerText.setFillColor(sf::Color::White);
	if (event.type == sf::Event::TextEntered)
	{
		
		PlayerInput += event.text.unicode;
		PlayerText.setString(PlayerInput);
	}*/


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					PlayerInput += event.text.unicode;
					PlayerText.setString(PlayerInput);
				}
			}
			window.draw(PlayerText);
		}
		window.display();

	auto joinPlayButton = std::make_shared<GUI::Button>(context);
	joinPlayButton->setPosition(750.f, 620.f);
	joinPlayButton->setText("Join");
	joinPlayButton->setCallback([this]()
	{
		requestStackPop();
		requestStackPush(StateID::JoinGame);
	});
		

	auto backButton = std::make_shared<GUI::Button>(context);
	backButton->setPosition(80.f, 620.f);
	backButton->setText("Back");
	backButton->setCallback(std::bind(&NamePlayer::requestStackPop, this));

	mGUIContainer.pack(backButton);
	mGUIContainer.pack(joinPlayButton);
	window.draw(PlayerText);
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
