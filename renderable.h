#pragma once

#ifndef RENDERABLE_H
#define RENDERABLE_H

class Renderable
{
public:
	virtual ~Renderable() {}

	virtual void render() = 0;

	virtual void update(float deltaTime) = 0;
};

#endif // RENDERABLE_H