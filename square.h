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

private:
	float x, y, size;
};

#endif // SQUARE_H