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

	void Screen::Update(float p_delta)
	{
		for (auto& e : m_entities)
			e->Update(p_delta);
	}

	void Screen::Render(sf::RenderWindow& p_window)
	{
		for (auto& e : m_entities)
			e->Render(p_window);
	}

	void Screen::HandleInput(sf::Event& p_event)
	{
		for (auto& e : m_entities)
			e->HandleInput(p_event);
	}
} //  namespace Engine
