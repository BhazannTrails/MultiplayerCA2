#include "SettingsState.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

SettingState::SettingState(StateStack& stack, Context context)
	:State(stack, context)
	, mGUIContainer()
{
	mBackgroundSprite.setTexture(context.textures->get(TextureID::TitleScreen));
	//Build key bindings and button labels
	for (std::size_t x = 0; x < 1; ++x)
	{
		addButtonLabel(static_cast<int>(ActionID::MoveLeft), x, 0, "Move Left", context);
		addButtonLabel(static_cast<int>(ActionID::MoveRight), x, 1, "Move Right", context);
		addButtonLabel(static_cast<int>(ActionID::MoveUp), x, 2, "Move Up", context);
		addButtonLabel(static_cast<int>(ActionID::MoveDown), x, 3, "Move Down", context);
		addButtonLabel(static_cast<int>(ActionID::Fire), x, 4, "Fire", context);
		addButtonLabel(static_cast<int>(ActionID::LaunchMissile), x, 5, "Missile", context);
		addButtonLabel(static_cast<int>(ActionID::RotatePlayerClockwise), x, 6, "Rotate Right", context);
		addButtonLabel(static_cast<int>(ActionID::RotatePlayerAntiClockwise), x, 7, "Rotate Left", context);
	}

	updateLabels();

	auto backButton = std::make_shared<GUI::Button>(context);
	backButton->setPosition(80.f, 620.f);
	backButton->setText("Back");
	backButton->setCallback(std::bind(&SettingState::requestStackPop, this));

	mGUIContainer.pack(backButton);
	
}

void SettingState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool SettingState::update(sf::Time dt)
{
	return true;
}

bool SettingState::handleEvent(const sf::Event& event)
{
	bool isKeyBinding = false;

	//Iterate through all key binding buttons to see they are being pressed, waiting for the user to enter a key
	for (std::size_t action = 0; action < static_cast<int>(ActionID::ActionCount); ++action)
	{
		if (mBindingButtons[action]->isActive())
		{
			isKeyBinding = true;
			if (event.type == sf::Event::KeyReleased)
			{
				// Player 1
				if (action < static_cast<int>(ActionID::ActionCount))
					getContext().keys1->assignKey(static_cast<ActionID>(action), event.key.code);

				// Player 2
				/*else
					getContext().keys2->assignKey(static_cast<ActionID>(action - static_cast<int>(ActionID::ActionCount)), event.key.code);
				mBindingButtons[action]->deactivate();*/
			}
			break;
		}
	}

	//If the keybindings have been updated we need to update the labels
	if (isKeyBinding)
	{
		updateLabels();
	}
	else
	{
		mGUIContainer.handleEvent(event);
	}
	return false;
}

void SettingState::updateLabels()
{
	for (std::size_t i = 0; i < static_cast<int>(ActionID::ActionCount); ++i)
	{
		auto action = static_cast<ActionID>(i);

		// Get keys of both players
		sf::Keyboard::Key key1 = getContext().keys1->getAssignedKey(action);
	//	sf::Keyboard::Key key2 = getContext().keys2->getAssignedKey(action);

		// Assign both key strings to labels
		mBindingLabels[i]->setText(toString(key1));
	//	mBindingLabels[i + static_cast<int>(ActionID::ActionCount)]->setText(toString(key2));
	}
}

void SettingState::addButtonLabel(std::size_t index, std::size_t x, std::size_t y, const std::string& text, Context context)
{
	// For x==0, start at index 0, otherwise start at half of array
	index += static_cast<int>(ActionID::ActionCount)* x;

	mBindingButtons[index] = std::make_shared<GUI::Button>(context);
	mBindingButtons[index]->setPosition(400.f * x + 80.f, 50.f * y + 100.f);
	mBindingButtons[index]->setText(text);
	mBindingButtons[index]->setToggle(true);

	mBindingLabels[index] = std::make_shared<GUI::Label>("", *context.fonts);
	mBindingLabels[index]->setPosition(400.f * x + 300.f, 50.f * y + 115.f);

	mGUIContainer.pack(mBindingButtons[index]);
	mGUIContainer.pack(mBindingLabels[index]);


}
