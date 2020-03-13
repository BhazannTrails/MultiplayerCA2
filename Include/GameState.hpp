#ifndef Include_GAMESTATE_HPP
#define Include_GAMESTATE_HPP

#include "../Include/State.hpp"
#include "../Include/World.hpp"
#include "../Include/Player.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameState : public State
{
	public:
							GameState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		World				mWorld;
		Player				mPlayer;
};

#endif // Include_GAMESTATE_HPP
