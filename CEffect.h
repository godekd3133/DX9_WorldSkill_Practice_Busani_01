#pragma once
#include "CComponent.h"
class CEffect :
	public CComponent
{
public:
	CEffect();
	~CEffect();

public:
	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void OnDestroy() override;
	virtual void OnCollision(CGameObject * _pObject) override;

public:
	void Init(string _ResKey, float _Delay, Vector3 _vPos);
};

#define EFFECT(Pos,Scale,resKey){ CGameObject * Effect= OBJ.Create(); Effect->tf->m_vScale = Scale; Effect->ac<CEffect>()->Init(resKey,0.05f,Pos);}
#define EFFECT2(Pos,Scale,resKey){ CGameObject * Effect= OBJ.Create(); Effect->tf->m_vScale = Scale; Effect->ac<CEffect>()->Init(resKey,0.05f,Pos); Effect->gc<CSpriteRenderer>()->m_RenderMode = RenderMode::RM_BillboardNonUI; }