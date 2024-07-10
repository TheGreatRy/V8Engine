#pragma once
#include <cmath>

namespace Math
{
	constexpr float Pi = 3.14159265359;
	constexpr float TwoPi = 6.28318530718;
	constexpr float HalfPi = 1.57079632679;

	constexpr float RadtToDeg(float radians) { return radians * (180.0f / Pi); }
	constexpr float DegtToRad(float degrees) { return degrees * (Pi / 180.0f); }

	inline float Sin(float radians)
	{
		return std::sinf(radians);
	}
	inline float Cos(float radians)
	{
		return std::cosf(radians);
	}
	inline float Atan2(float y, float x)
	{
		return y / x;
	}
	inline float Sqrt(float value)
	{
		return std::sqrt(value);
	}

	template<typename T>
	T Max(T a, T b)
	{
		return (a > b) ? a : b;
	}

	template<typename T>
	T Min(T a, T b)
	{
		return (a < b) ? a : b;
	}
	template<typename T>
	T Abs(T value)
	{
		return (value < 0) ? -value : value;
	}
}
