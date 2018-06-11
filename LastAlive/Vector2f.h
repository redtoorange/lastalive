#pragma once
#include <SFML/System/Vector2.hpp>

namespace Engine
{
	class Vector2f : public sf::Vector2f
	{
	public:
		Vector2f()
			: Vector2f(0, 0)
		{
		}

		virtual ~Vector2f() = default;

		Vector2f(float X, float Y)
			: Vector2<float>(X, Y)
		{
		}

		// Copy Assign/Constructor should make a valid copy of the current object
		//	e.g. Copy the data from one into the other
		// Copy Constructor
		Vector2f(const Vector2f& other)
			: sf::Vector2f(other)
		{
		}

		// Copy Assignment
		Vector2f& operator=(const Vector2f& other)
		{
			x = other.x;
			y = other.y;

			return *this;
		}


		// Move
		Vector2f(Vector2f&& other) noexcept = default;

		// Move
		Vector2f& operator=(Vector2f&& other) noexcept = default;


		friend bool operator==(const Vector2f& lhs, const Vector2f& rhs)
		{
			return (lhs.x == rhs.x && lhs.y == rhs.y);
		}

		friend bool operator!=(const Vector2f& lhs, const Vector2f& rhs)
		{
			return !(lhs == rhs);
		}

		/// Is this vector of length 1?
		bool isNormalized() const;

		/// Normalize this vector to a length of 1
		void normalize();

		/// What is the length of this vector
		float length() const;
	};
}
