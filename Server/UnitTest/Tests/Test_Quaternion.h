#ifndef Test_Quaternion_h__
#define Test_Quaternion_h__
#include "Solution.h"
#include "Type/Vec3.h"
#include "Type/Quaternion.h"
class Test_Quaternion :public Solution
{
public:
	void Excute() 
	{
		Fuck();
	}
	void Fuck()
	{
		Vec3 targetPosition(-41.5, 0.1, -48.8);
		Vec3 m_position(7.1, 3.2, 16.6);
		F32 upAngle = 90.0f;
		F32 ForwardHorSpeed = 20.0f;

		//计算目标方向
		Vec3 dir = (targetPosition - m_position);
		Vec3 horVec = dir.Normalized().Cross(Vec3(0, 1, 0));
		Quaternion quaternion;
		quaternion.setRotation(horVec, upAngle);
		Vec3 targetDir = dir.Normalized() * quaternion;  //目标方向
		//Vec3 targetDir = (targetPosition - Vec3(m_position.X, targetPosition.Y, m_position.Z)).Normalized() * quaternion;
		//计算初始速度
		//F32 horCosAngle = (targetPosition - m_position).Normalized().Dot((Vec3(targetPosition.X, m_position.Y, targetPosition.Z) - m_position).Normalized());
		F32 horCosAngle = targetDir.Normalized().Dot((Vec3(targetPosition.X, m_position.Y, targetPosition.Z) - m_position).Normalized());
		F32 oriSpeed = ForwardHorSpeed / horCosAngle;
		Vec3 oriVec = targetDir * oriSpeed;

		//计算y轴的加速度
		F32 HorDistance = (Vec3(m_position.X, targetPosition.Y, m_position.Z) - targetPosition).Length();
		F32 durTime = HorDistance / ForwardHorSpeed;




		F32 deltaY = (m_position.Y - targetPosition.Y);
		F32 h0 = oriVec.Y * durTime - deltaY;
		F32 totalH = 2.0f*h0 + deltaY;
		F32 v0 = oriVec.Y;
		F32 m_Gravity = v0 / (h0 / totalH * durTime);
		m_Gravity *= -1;
		Vec3 m_speed = oriVec;
	}


	void Fuck2()
	{
		Vec3 targetPosition(-41.5, 0.1, -48.8);
		Vec3 m_position(7.1, 3.2, 16.6);
		F32 upAngle = 20.0f;
		F32 ForwardHorSpeed = 20.0f;

		//计算目标方向
		Vec3 dir = (targetPosition - m_position);
		Vec3 m_speed = dir.Normalized();
		Quaternion quar;
		quar.fromEuler(Vec3(0, -90, 0));

		Vec3 d1 = quar * Vec3(dir.X, 0.0f, dir.Z).Normalized();

		Quaternion quar2;
		quar2.setRotation(d1, upAngle);
		Vec3 moveSpeed = quar * m_speed;



		//计算y轴的加速度
		F32 HorDistance = (Vec3(m_position.X, targetPosition.Y, m_position.Z) - targetPosition).Length();
		F32 durTime = HorDistance / ForwardHorSpeed;
	}
};

#endif // Test_Quaternion_h__
