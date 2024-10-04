#pragma once

#ifndef SQUARE_H
#define SQUARE_H

#include "renderable.h"

class Square : public Renderable
{
public:
	Square(float startX, float startY, float size);

	void render() override;
	void update(float deltaTime) override;

	void onClick(float posX, float posY) override;
	void onDrag(float posX, float posY) override;
	bool isMouseOver(float poxX, float posY) override;
	void onRelease() override;

	float getX() { return x; };
	float getY() { return y; };

	~Square() {}

private:
	float x, y, size;
	bool selected = false;
};

#endif // SQUARE_H