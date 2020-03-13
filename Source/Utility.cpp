#include "../Include/Utility.hpp"
#include "../Include/Animation.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <random>
#include <cmath>
#include <ctime>
#include <cassert>


namespace
{
	std::default_random_engine createRandomEngine()
	{
		auto seed = static_cast<unsigned long>(std::time(nullptr));
		return std::default_random_engine(seed);
	}

	auto RandomEngine = createRandomEngine();
}

std::string toString(sf::Keyboard::Key key)
{
	#define Include_KEYTOSTRING_CASE(KEY) case sf::Keyboard::KEY: return #KEY;

	switch (key)
	{
		Include_KEYTOSTRING_CASE(Unknown)
		Include_KEYTOSTRING_CASE(A)
		Include_KEYTOSTRING_CASE(B)
		Include_KEYTOSTRING_CASE(C)
		Include_KEYTOSTRING_CASE(D)
		Include_KEYTOSTRING_CASE(E)
		Include_KEYTOSTRING_CASE(F)
		Include_KEYTOSTRING_CASE(G)
		Include_KEYTOSTRING_CASE(H)
		Include_KEYTOSTRING_CASE(I)
		Include_KEYTOSTRING_CASE(J)
		Include_KEYTOSTRING_CASE(K)
		Include_KEYTOSTRING_CASE(L)
		Include_KEYTOSTRING_CASE(M)
		Include_KEYTOSTRING_CASE(N)
		Include_KEYTOSTRING_CASE(O)
		Include_KEYTOSTRING_CASE(P)
		Include_KEYTOSTRING_CASE(Q)
		Include_KEYTOSTRING_CASE(R)
		Include_KEYTOSTRING_CASE(S)
		Include_KEYTOSTRING_CASE(T)
		Include_KEYTOSTRING_CASE(U)
		Include_KEYTOSTRING_CASE(V)
		Include_KEYTOSTRING_CASE(W)
		Include_KEYTOSTRING_CASE(X)
		Include_KEYTOSTRING_CASE(Y)
		Include_KEYTOSTRING_CASE(Z)
		Include_KEYTOSTRING_CASE(Num0)
		Include_KEYTOSTRING_CASE(Num1)
		Include_KEYTOSTRING_CASE(Num2)
		Include_KEYTOSTRING_CASE(Num3)
		Include_KEYTOSTRING_CASE(Num4)
		Include_KEYTOSTRING_CASE(Num5)
		Include_KEYTOSTRING_CASE(Num6)
		Include_KEYTOSTRING_CASE(Num7)
		Include_KEYTOSTRING_CASE(Num8)
		Include_KEYTOSTRING_CASE(Num9)
		Include_KEYTOSTRING_CASE(Escape)
		Include_KEYTOSTRING_CASE(LControl)
		Include_KEYTOSTRING_CASE(LShift)
		Include_KEYTOSTRING_CASE(LAlt)
		Include_KEYTOSTRING_CASE(LSystem)
		Include_KEYTOSTRING_CASE(RControl)
		Include_KEYTOSTRING_CASE(RShift)
		Include_KEYTOSTRING_CASE(RAlt)
		Include_KEYTOSTRING_CASE(RSystem)
		Include_KEYTOSTRING_CASE(Menu)
		Include_KEYTOSTRING_CASE(LBracket)
		Include_KEYTOSTRING_CASE(RBracket)
		Include_KEYTOSTRING_CASE(SemiColon)
		Include_KEYTOSTRING_CASE(Comma)
		Include_KEYTOSTRING_CASE(Period)
		Include_KEYTOSTRING_CASE(Quote)
		Include_KEYTOSTRING_CASE(Slash)
		Include_KEYTOSTRING_CASE(BackSlash)
		Include_KEYTOSTRING_CASE(Tilde)
		Include_KEYTOSTRING_CASE(Equal)
		Include_KEYTOSTRING_CASE(Dash)
		Include_KEYTOSTRING_CASE(Space)
		Include_KEYTOSTRING_CASE(Return)
		Include_KEYTOSTRING_CASE(BackSpace)
		Include_KEYTOSTRING_CASE(Tab)
		Include_KEYTOSTRING_CASE(PageUp)
		Include_KEYTOSTRING_CASE(PageDown)
		Include_KEYTOSTRING_CASE(End)
		Include_KEYTOSTRING_CASE(Home)
		Include_KEYTOSTRING_CASE(Insert)
		Include_KEYTOSTRING_CASE(Delete)
		Include_KEYTOSTRING_CASE(Add)
		Include_KEYTOSTRING_CASE(Subtract)
		Include_KEYTOSTRING_CASE(Multiply)
		Include_KEYTOSTRING_CASE(Divide)
		Include_KEYTOSTRING_CASE(Left)
		Include_KEYTOSTRING_CASE(Right)
		Include_KEYTOSTRING_CASE(Up)
		Include_KEYTOSTRING_CASE(Down)
		Include_KEYTOSTRING_CASE(Numpad0)
		Include_KEYTOSTRING_CASE(Numpad1)
		Include_KEYTOSTRING_CASE(Numpad2)
		Include_KEYTOSTRING_CASE(Numpad3)
		Include_KEYTOSTRING_CASE(Numpad4)
		Include_KEYTOSTRING_CASE(Numpad5)
		Include_KEYTOSTRING_CASE(Numpad6)
		Include_KEYTOSTRING_CASE(Numpad7)
		Include_KEYTOSTRING_CASE(Numpad8)
		Include_KEYTOSTRING_CASE(Numpad9)
		Include_KEYTOSTRING_CASE(F1)
		Include_KEYTOSTRING_CASE(F2)
		Include_KEYTOSTRING_CASE(F3)
		Include_KEYTOSTRING_CASE(F4)
		Include_KEYTOSTRING_CASE(F5)
		Include_KEYTOSTRING_CASE(F6)
		Include_KEYTOSTRING_CASE(F7)
		Include_KEYTOSTRING_CASE(F8)
		Include_KEYTOSTRING_CASE(F9)
		Include_KEYTOSTRING_CASE(F10)
		Include_KEYTOSTRING_CASE(F11)
		Include_KEYTOSTRING_CASE(F12)
		Include_KEYTOSTRING_CASE(F13)
		Include_KEYTOSTRING_CASE(F14)
		Include_KEYTOSTRING_CASE(F15)
		Include_KEYTOSTRING_CASE(Pause)
	}

	return "";
}

void centerOrigin(sf::Sprite& sprite)
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void centerOrigin(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void centerOrigin(Animation& animation)
{
	sf::FloatRect bounds = animation.getLocalBounds();
	animation.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

float toDegree(float radian)
{
	return 180.f / 3.141592653589793238462643383f * radian;
}

float toRadian(float degree)
{
	return 3.141592653589793238462643383f / 180.f * degree;
}

int randomInt(int exclusiveMax)
{
	std::uniform_int_distribution<> distr(0, exclusiveMax - 1);
	return distr(RandomEngine);
}

float length(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f unitVector(sf::Vector2f vector)
{
	assert(vector != sf::Vector2f(0.f, 0.f));
	return vector / length(vector);
}