#ifndef Include_LABEL_HPP
#define Include_LABEL_HPP

#include <Include/Component.hpp>
#include <Include/ResourceIdentifiers.hpp>
#include <Include/ResourceHolder.hpp>

#include <SFML/Graphics/Text.hpp>


namespace GUI
{

class Label : public Component
{
    public:
        typedef std::shared_ptr<Label> Ptr;
            

	public:
							Label(const std::string& text, const FontHolder& fonts);

        virtual bool		isSelectable() const;
		void				setText(const std::string& text);

        virtual void		handleEvent(const sf::Event& event);


    private:
        void				draw(sf::RenderTarget& target, sf::RenderStates states) const;


    private:
        sf::Text			mText;
};

}

#endif // Include_LABEL_HPP
