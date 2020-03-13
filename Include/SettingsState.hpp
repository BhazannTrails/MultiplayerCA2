#ifndef Include_SETTINGSSTATE_HPP
#define Include_SETTINGSSTATE_HPP

#include "../Include/State.hpp"
#include "../Include/KeyBinding.hpp"
#include "../Include/Container.hpp"
#include "../Include/Button.hpp"
#include "../Include/Label.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>


class SettingsState : public State
{
	public:
										SettingsState(StateStack& stack, Context context);

		virtual void					draw();
		virtual bool					update(sf::Time dt);
		virtual bool					handleEvent(const sf::Event& event);


	private:
		void							updateLabels();
		void							addButtonLabel(std::size_t index, std::size_t x, std::size_t y, const std::string& text, Context context);


	private:
		sf::Sprite											mBackgroundSprite;
		GUI::Container										mGUIContainer;
		std::array<GUI::Button::Ptr, 2*PlayerAction::Count>	mBindingButtons;
		std::array<GUI::Label::Ptr, 2*PlayerAction::Count> 	mBindingLabels;
};

#endif // Include_SETTINGSSTATE_HPP
