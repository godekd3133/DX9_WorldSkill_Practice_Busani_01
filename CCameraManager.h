#pragma once
#include "CSingleton.h"
enum Axis
{
	Foward,
	RF,
	LF,
	Back,
	Right,
	Left
};
class CCameraManager :
	public CSingleton< CCameraManager>
{
public:
	CCameraManager();
	~CCameraManager();

public:
	CScheduleAdmin  * sa;
	Vector3 m_vCharactorDir;
	Vector3 m_vPos;
	Vector3 m_vLookAt;
	Vector3 m_vUp;
	Vector3 m_vFoward = Vector3(0, 0, 1);
	Vector3 m_vCharactorAxis[6];
	Matrix m_matView;
	Matrix m_matProj;

	Vector3 m_vShakePos;
	Vector2 m_vRotation = Vector2(20,0);
	Vector3 m_vOffset = Vector3(0, 0, 0);
	float m_fCameraTime;
	float m_fShakePower;
	float m_fSensitivity = 10.f;
public:
	void Update();
	Vector3 GetFinalPos();
	void SetTransform();
	CGameObject * m_pFollowObject = nullptr;
	float m_fDistance = 0.f;
public:
	void Shake(float _fTime, float _fPower);
	void Follow(CGameObject * _Follow, float _Distance)
	{
		m_bScrolling = true;
		m_pFollowObject = _Follow;
		m_fDistance = _Distance;
	}
private:
	void ShakeCamera()
	{
		m_vShakePos.x += (rand() % (int)(m_fShakePower *100))/100.f - (m_fShakePower*100.f)/100.f / 2.f;
		m_vShakePos.y += (rand() % (int)(m_fShakePower *100))/100.f - (m_fShakePower*100.f)/100.f / 2.f;
		m_vShakePos.z += (rand() % (int)(m_fShakePower *100))/100.f - (m_fShakePower*100.f)/100.f / 2.f;
	}

public:
	bool m_bScrolling = false;
	float m_fScrollSpeed;
	float m_fCurSpeed;
	bool RayCast(CMeshRenderer* _pTarget, Vector3 _vPos, Vector3 _vDirection, float _fDistance, CollisionInfo& _Info);

	bool RayCastAtBox(Vector3 _Radius, Matrix _matWorld, Vector3 _vPos, Vector3 _vDirection, float _fDistance, CollisionInfo& _Info);
	bool RayCastAtSphere(LPD3DXMESH _Sphere, Matrix _matWorld, Vector3 _vPos, Vector3 _vDirection, float _fDistance, CollisionInfo& _Info);

};

#define CAMERA (*CCameraManager::GetInstance())
