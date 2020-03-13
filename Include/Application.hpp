#ifndef Include_APPLICATION_HPP
#define Include_APPLICATION_HPP

#include "../Include/ResourceHolder.hpp"
#include "../Include/ResourceIdentifiers.hpp"
#include "../Include/KeyBinding.hpp"
#include "../Include/StateStack.hpp"
#include "../Include/MusicPlayer.hpp"
#include "../Include/SoundPlayer.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Application
{
	public:
								Application();
		void					run();
		

	private:
		void					processInput();
		void					update(sf::Time dt);
		void					render();

		void					updateStatistics(sf::Time dt);
		void					registerStates();


	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		TextureHolder			mTextures;
	  	FontHolder				mFonts;
		MusicPlayer				mMusic;
		SoundPlayer				mSounds;

		KeyBinding				mKeyBinding1;
		KeyBinding				mKeyBinding2;
		StateStack				mStateStack;

		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};

#endif // Include_APPLICATION_HPP
