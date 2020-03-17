/*
 * Vec3.h
 *
 *  Created on: 2015年4月1日
 *      Author: Zh
 */

#ifndef VEC3_H_
#define VEC3_H_

#include <math.h>

class Vec3
{
public:
	float X,Y,Z;
	
	inline float& operator [] (int i)					{return ((float*)this)[i];}
	inline float operator [] (int i) const				{return ((float*)this)[i];}
	/// ---------------------------------
    /// Constructors
    /// ---------------------------------
	/// Constructors.
	Vec3( float InX, float InY, float InZ )
	:	X(InX), Y(InY), Z(InZ)
	{}

	Vec3() :	X(0), Y(0), Z(0)
	{}


	/// BinarY math operators.
	Vec3 operator^( const Vec3& V ) const
	{
		return Vec3
		(
			Y * V.Z - Z * V.Y,
			Z * V.X - X * V.Z,
			X * V.Y - Y * V.X
		);
	}
	float operator|( const Vec3& V ) const
	{
		return X*V.X + Y*V.Y + Z*V.Z;
	}
	friend Vec3 operator*( float Scale, const Vec3& V )
	{
		return Vec3( V.X * Scale, V.Y * Scale, V.Z * Scale );
	}
	Vec3 operator+( const Vec3& V ) const
	{
		return Vec3( X + V.X, Y + V.Y, Z + V.Z );
	}
	Vec3 operator-( const Vec3& V ) const
	{
		return Vec3( X - V.X, Y - V.Y, Z - V.Z );
	}
	Vec3 operator*( float Scale ) const
	{
		return Vec3( X * Scale, Y * Scale, Z * Scale );
	}
	Vec3 operator/( float Scale ) const
	{
		float RScale = 1.f/Scale;
		return Vec3( X * RScale, Y * RScale, Z * RScale );
	}
	Vec3 operator*( const Vec3& V ) const
	{
		return Vec3( X * V.X, Y * V.Y, Z * V.Z );
	}

	/// BinarY comparison operators.
	bool operator==( const Vec3& V ) const
	{
		return X==V.X && Y==V.Y && Z==V.Z;
	}
	bool operator!=( const Vec3& V ) const
	{
		return X!=V.X || Y!=V.Y || Z!=V.Z;
	}

	/// UnarY operators.
	Vec3 operator-() const
	{
		return Vec3( -X, -Y, -Z );
	}

	/// Assignment operators.
	void operator+=( const Vec3& V )
	{
		X += V.X; Y += V.Y; Z += V.Z;
	}
	void operator-=( const Vec3& V )
	{
		X -= V.X; Y -= V.Y; Z -= V.Z;
	}
	void operator*=( float Scale )
	{
		X *= Scale; Y *= Scale; Z *= Scale;
	}
	void operator/=( float V )
	{
		float RV = 1.f/V;
		X *= RV; Y *= RV; Z *= RV;
	}
	void operator*=( const Vec3& V )
	{
		X *= V.X; Y *= V.Y; Z *= V.Z;
	}
	void operator/=( const Vec3& V )
	{
		X /= V.X; Y /= V.Y; Z /= V.Z;
	}

	/// Simple functions.
	float Length() const
	{
		return sqrt( X*X + Y*Y + Z*Z );
	}
	float SqrLength() const
	{
		return X*X + Y*Y + Z*Z;
	}
	int IsNearlyZero() const
	{
		return
				fabs(X)<0.0001f
			&&	fabs(Y)<0.0001f
			&&	fabs(Z)<0.0001f;
	}
	bool Normalize()
	{
		float squareSum = X*X+Y*Y+Z*Z;
		if( squareSum >= 0.0001f )
		{
			float scale = 1.f/sqrtf(squareSum);
			X *= scale; Y *= scale; Z *= scale;
			return true;
		}
		else return false;

		/*float f = X*X+Y*Y+Z*Z;
		if( f >= SMALL_NUMBER )
		{
			float half = 0.5f * f;
			int i = *(int*)&f;
			i = 0X5f3759df - (i>>1);
			f = *(float*)&i;
			f = f*(1.5f - half*f*f);

			X *= f;
			Y *= f;
			Z *= f;

			return true;
		}
		else
			return false;*/
	}

	//---------------------------------
	/// Operator replacement functions
	//---------------------------------
	void Set(float X, float Y, float Z) { this->X = X; this->Y = Y; this->Z = Z; }
	void Add(Vec3& v){ *this += v; }
	void Sub(Vec3& v){ *this -= v; }
	void Mul(Vec3& v){ *this *= v; }
	bool Cmp(Vec3& v){ return *this == v; }

	//---------------------------------
	/// Static functions
	//---------------------------------
	static Vec3 MakeDirection(float Yaw, float pitch, float roll);
	static Vec3 NormalFromTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2);

	static const Vec3& forward();
	static const Vec3& up();
	static const Vec3& zero();

	//---------------------------------
	/// The rest
	//---------------------------------
	double Yaw ();
	double Pitch ();
	double Roll ();
	void Zero()										{X = Y = Z = 0;}
	Vec3 GetNormal();
	Vec3 Normalized() const						{ Vec3 v = *this; v.Normalize(); return v; }//float s = 1.f/Length(); Vec3 n = *this * s; return n;}
	float  DotSelf() const							{return X*X + Y*Y + Z*Z;}
	float  Dot(const Vec3& v)	const				{return X*v.X + Y*v.Y + Z*v.Z;}
	Vec3 Cross(const Vec3 &v) const				{ return *this ^ v; }
	float  ScalarProjectionOntoVec3(Vec3& v1)	{return Dot(v1)/v1.Length();}
	Vec3 ProjectionOntoVec3(const Vec3& v1)	{return v1*(Dot(v1)/v1.DotSelf());}
	Vec3 Lerp(const Vec3& v1, float t);
	float  RadAngle(const Vec3& v1) const		    {return acosf(Dot(v1));}
	float  CosAngle(const Vec3& v1) const		    {return Dot(v1);}
	Vec3 Reflected(const Vec3& n)				{Vec3 r = n*(2.f * Dot(n));r-=*this;return r;}
	float  DistanceToLine(const Vec3& p0, const Vec3& p1) const;
	float  Average() const							{return (X + Y + Z) * 0.333333f;}
	Vec3 HalfWaY(const Vec3& dest) const		{return Vec3(0.5f * (X + dest.X),0.5f * (Y + dest.Y),0.5f * (Z + dest.Z));}
};

#endif /* VEC3_H_ */
