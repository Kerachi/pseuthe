/*********************************************************************
Matt Marchant 2015
http://trederia.blogspot.com

pseuthe Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

//draws an expanding 'echo'

#ifndef ECHO_DRAWABLE_HPP_
#define ECHO_DRAWABLE_HPP_

#include <Component.hpp>
#include <Log.hpp>

#include <SFML/Graphics/CircleShape.hpp>

class EchoDrawable final : public Component, public sf::Drawable
{
public:
    using Ptr = std::unique_ptr<EchoDrawable>;

    EchoDrawable(float, MessageBus&);
    ~EchoDrawable() = default;

    Component::Type type() const override;
    void entityUpdate(Entity&, float) override;
    void handleMessage(const Message&) override;

    void setColour(const sf::Color&);

private:

    sf::CircleShape m_circleShape;
    sf::Color m_colour;
    float m_lifetime;

    void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

#endif //ECHO_DRAWABLE_HPP_