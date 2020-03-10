#ifndef Include_MENUSTATE_HPP
#define Include_MENUSTATE_HPP

#include <Include/State.hpp>
#include <Include/Container.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class MenuState : public State
{
	public:
								MenuState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);


	private:
		sf::Sprite				mBackgroundSprite;
		GUI::Container			mGUIContainer;
};

#endif // Include_MENUSTATE_HPP
