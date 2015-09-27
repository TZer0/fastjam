#ifndef UTIL_H
#define UTIL_H

template <class T>
class Vector2D {
public:
	Vector2D() : mX(0), mY(0) {}
	Vector2D(T x, T y) : mX(x), mY(y) {}
	T mX, mY;
};

class Shape {
};

template <class T>
class Rectangle : Shape {
public:
	Rectangle(Vector2D<T> pos, Vector2D<T> size) : mPos(pos), mSize(size) {}
	Vector2D<T> mPos, mSize;
	bool collides(Vector2D<T> pos, Vector2D<T> trans = Vector2D<T>()) const {
		T tX = trans.mX + mPos.mX;
		T tY = trans.mY + mPos.mY;
		return tX <= pos.mX && pos.mX < tX + mSize.mX && tY <= pos.mY && pos.mY < tY + mSize.mY;
	}
};

#endif // UTIL_H
