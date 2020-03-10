#ifndef Include_SOUNDNODE_HPP
#define Include_SOUNDNODE_HPP

#include <Include/SceneNode.hpp>
#include <Include/ResourceIdentifiers.hpp>


class SoundPlayer;

class SoundNode : public SceneNode
{
	public:
		explicit				SoundNode(SoundPlayer& player);
		void					playSound(SoundEffect::ID sound, sf::Vector2f position);

		virtual unsigned int	getCategory() const;


	private:
		SoundPlayer&			mSounds;
};

#endif // Include_SOUNDNODE_HPP
