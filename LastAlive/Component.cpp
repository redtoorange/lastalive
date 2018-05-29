#include "Component.h"

namespace Engine
{
	bool Component::GetsInput() const
	{
		return m_getsInput;
	}

	bool Component::GetsUpdate() const
	{
		return m_getsUpdate;
	}

	bool Component::GetsRender() const
	{
		return m_getsRender;
	}
} //  namespace Engine
