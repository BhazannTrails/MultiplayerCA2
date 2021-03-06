#include "KeyBinding.hpp"

#include <string>
#include <algorithm>


KeyBinding::KeyBinding(int controlPreconfiguration)
	: mKeyMap()
{
	// Set initial key bindings for player 1
	if (controlPreconfiguration == 1)
	{
		mKeyMap[sf::Keyboard::Left] = ActionID::MoveLeft;
		mKeyMap[sf::Keyboard::Right] = ActionID::MoveRight;
		mKeyMap[sf::Keyboard::Up] = ActionID::MoveUp;
		mKeyMap[sf::Keyboard::Down] = ActionID::MoveDown;
		mKeyMap[sf::Keyboard::Space] = ActionID::Fire;
	//	mKeyMap[sf::Keyboard::M] = ActionID::LaunchMissile;
		mKeyMap[sf::Keyboard::Q] = ActionID::RotatePlayerAntiClockwise;
		mKeyMap[sf::Keyboard::E] = ActionID::RotatePlayerClockwise;
	}
	//else if (controlPreconfiguration == 2)
	//{
	//	// Player 2
	//	mKeyMap[sf::Keyboard::A] = ActionID::MoveLeft;
	//	mKeyMap[sf::Keyboard::D] = ActionID::MoveRight;
	//	mKeyMap[sf::Keyboard::W] = ActionID::MoveUp;
	//	mKeyMap[sf::Keyboard::S] = ActionID::MoveDown;
	//	mKeyMap[sf::Keyboard::F] = ActionID::Fire;
	//	//mKeyMap[sf::Keyboard::R] = ActionID::LaunchMissile;
	//}
}

void KeyBinding::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyMap.begin(); itr != mKeyMap.end(); )
	{
		if (itr->second == action)
			mKeyMap.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyMap[key] = action;
}

sf::Keyboard::Key KeyBinding::getAssignedKey(Action action) const
{
	for (auto pair : mKeyMap)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

bool KeyBinding::checkAction(sf::Keyboard::Key key, Action& out) const
{
	auto found = mKeyMap.find(key);
	if (found == mKeyMap.end())
	{
		return false;
	}
	else
	{
		out = found->second;
		return true;
	}
}

std::vector<KeyBinding::Action> KeyBinding::getRealtimeActions() const
{
	// Return all realtime actions that are currently active.
	std::vector<Action> actions;

	for (auto pair : mKeyMap)
	{
		// If key is pressed and an action is a realtime action, store it
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			actions.push_back(pair.second);
	}

	return actions;
}

bool isRealtimeAction(ActionID action)
{
	switch (action)
	{
	case ActionID::MoveLeft:
	case ActionID::MoveRight:
	case ActionID::MoveDown:
	case ActionID::MoveUp:
	case ActionID::Fire:
	case ActionID::RotatePlayerClockwise:
	case ActionID::RotatePlayerAntiClockwise:
		return true;

	default:
		return false;
	}
}