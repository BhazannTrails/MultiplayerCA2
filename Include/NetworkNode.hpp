#ifndef Include_NETWORKNODE_HPP
#define Include_NETWORKNODE_HPP

#include <Include/SceneNode.hpp>
#include <Include/NetworkProtocol.hpp>

#include <queue>


class NetworkNode : public SceneNode
{
	public:
								NetworkNode();

		void					notifyGameAction(GameActions::Type type, sf::Vector2f position);
		bool					pollGameAction(GameActions::Action& out);

		virtual unsigned int	getCategory() const;


	private:
		std::queue<GameActions::Action>	mPendingActions;
};

#endif // Include_NETWORKNODE_HPP
