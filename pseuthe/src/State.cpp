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

#include <State.hpp>
#include <StateStack.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

State::Context::Context(sf::RenderWindow& rw, App& app)
    : renderWindow(rw), appInstance(app){}


//-----------------------------------------------------

State::State(StateStack& stateStack, Context context)
    : m_stateStack  (stateStack),
    m_context       (context)
{

}

void State::setContext(Context c)
{
    m_context.defaultView = c.defaultView;
}

//protected
void State::requestStackPush(States::ID id)
{
    m_stateStack.pushState(id);
}

void State::requestStackPop()
{
    m_stateStack.popState();
}

void State::requestStackClear()
{
    m_stateStack.clearStates();
}

State::Context State::getContext() const
{
    return m_context;
}