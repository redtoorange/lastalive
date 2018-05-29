#include "Screen.h"
#include "Entity.h"

namespace Engine
{
	Screen::Screen()
	{
	}

	Screen::~Screen()
	{
	}

	void Screen::update(float p_delta)
	{
		for (auto& e : m_entities)
			e->update(p_delta);
	}

	void Screen::render(sf::RenderWindow& p_window)
	{
		for (auto& e : m_entities)
			e->render(p_window);
	}

	void Screen::handleInput(sf::Event& p_event)
	{
		for (auto& e : m_entities)
			e->handleInput(p_event);
	}
} //  namespace Engine
