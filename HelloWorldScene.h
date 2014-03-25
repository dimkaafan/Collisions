#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Point3 :public Point
{

public:
	float z;
	Point3(float xx = 0, float yy = 0, float zz = 0) : Point(xx, yy), z(zz){}

	inline float dot(const Point3& other) const {
		return x*other.x + y*other.y + z*other.z;
	}
	void setPoint(float xx, float yy, float zz)
	{
		this->x = xx;
		this->y = yy;
		this->z = zz;
	}

	inline float getLength() const {
		return sqrtf(x*x + y*y +z*z);
	};

	inline Point3 vectmult(const Point3& other) const {
		return Point3(y*other.z - z*other.y, -(x*other.z - z*other.x), x*other.y - y*other.x);
	};

	Point3 operator*(float a) const
	{
		return Point3(this->x * a, this->y * a, this-> z* a);
	}

	Point3 operator/(float a) const
	{
		CCASSERT(a != 0, "CCPoint division by 0.");
		return Point3(this->x / a, this->y / a, this->z / a);
	}

	Point3 operator+(const Point3& right) const
	{
		return Point3(this->x + right.x, this->y + right.y, this->z + right.z);
	}

	Point3 operator-(const Point3& right) const
	{
		return Point3(this->x - right.x, this->y - right.y, this->z - right.z);
	}
};

class HelloWorld : public cocos2d::Layer
{
private:
	CCArray *_moles;
	Point	m_center;
	Node*	m_actoveSprite;
	Point	m_speed;
	float	m_speedVal;
	float	m_aZY;
	float	m_aZX;
	Point3	m_normal;
	Point3	m_lF;
	Point3	m_lx;
	Point3	m_ly;
	Point3	m_mG;
	void setTouch(Touch *);
	void setNormal(float aZY, float aZX);
public:
	~HelloWorld();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(); 

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void menuCloseCallback(Object* sender);
	void menuSwitchSnd(Object* sender);
	void changeSndVolume(Object* sender, float delta);
	void tryPopMoles(float dt);
	void moveSprite(float dt);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchMoved(Touch *touch, Event *unused_event);

	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);


	//void onAcceleration(Acceleration* acc, Event* unused_event);

};

#endif // __HELLOWORLD_SCENE_H__
