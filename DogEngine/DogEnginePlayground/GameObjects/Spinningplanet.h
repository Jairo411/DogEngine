#ifndef SPINNINGPLANET_H
#define SPINNINGPLANET_H
#include "GameObject.h"
#include "../Components/C_Sprite.h"
class SpinningPlanet : public GameObject
{
public:
	SpinningPlanet();
	virtual ~SpinningPlanet();

	virtual void OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Render() override;
	virtual void Update(float dt_) override;
private:
	C_Sprite sprite;
};
#endif // !SPINNINGPLANET_H
