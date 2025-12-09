#include "Transform.h"

Transform::Transform(Vector3 position, Vector3 scale)
{
    this->position = position;
    this->scale = scale;
    UpdateMatrix();
}

Transform::Transform(Vector3 position)
{
    this->position = position;
    scale = {1,1,1};
    UpdateMatrix();
}

Transform::Transform()
{
    position = {0,0,0};
    scale = {1,1,1};
    UpdateMatrix();
}

void Transform::UpdateMatrix()
{
    tMat = MatrixTranslate(position)/*Rotate Here*/* MatrixScale(scale);
}

const Matrix4x4& Transform::GetMatrix()
{
    return tMat;
}

const Vector3& Transform::GetPostion()
{
    return position;
}

void Transform::SetPosition(Vector3& v)
{
    position = v;
}