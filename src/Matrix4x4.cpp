#include "Matrix4x4.h"

#include "Vectors.h"
#include "Settings.h"


Matrix4x4 operator*(const Matrix4x4& a, const Matrix4x4& b)
{
    float resultData[32];
    
    resultData[ 0] = a[ 0]*b[ 0] + a[ 1]*b[ 4] + a[ 2]*b[ 8] + a[ 3]*b[12];
    resultData[ 1] = a[ 0]*b[ 1] + a[ 1]*b[ 5] + a[ 2]*b[ 9] + a[ 3]*b[13];
    resultData[ 2] = a[ 0]*b[ 2] + a[ 1]*b[ 6] + a[ 2]*b[10] + a[ 3]*b[14];
    resultData[ 3] = a[ 0]*b[ 3] + a[ 1]*b[ 7] + a[ 2]*b[11] + a[ 3]*b[15];
        
    resultData[ 4] = a[ 4]*b[ 0] + a[ 5]*b[ 4] + a[ 6]*b[ 8] + a[ 7]*b[12];
    resultData[ 5] = a[ 4]*b[ 1] + a[ 5]*b[ 5] + a[ 6]*b[ 9] + a[ 7]*b[13];
    resultData[ 6] = a[ 4]*b[ 2] + a[ 5]*b[ 6] + a[ 6]*b[10] + a[ 7]*b[14];
    resultData[ 7] = a[ 4]*b[ 3] + a[ 5]*b[ 7] + a[ 6]*b[11] + a[ 7]*b[15];
        
    resultData[ 8] = a[ 8]*b[ 0] + a[ 9]*b[ 4] + a[10]*b[ 8] + a[11]*b[12];
    resultData[ 9] = a[ 8]*b[ 1] + a[ 9]*b[ 5] + a[10]*b[ 9] + a[11]*b[13];
    resultData[10] = a[ 8]*b[ 2] + a[ 9]*b[ 6] + a[10]*b[10] + a[11]*b[14];
    resultData[11] = a[ 8]*b[ 3] + a[ 9]*b[ 7] + a[10]*b[11] + a[11]*b[15];
        
    resultData[12] = a[12]*b[ 0] + a[13]*b[ 4] + a[14]*b[ 8] + a[15]*b[12];
    resultData[13] = a[12]*b[ 1] + a[13]*b[ 5] + a[14]*b[ 9] + a[15]*b[13];
    resultData[14] = a[12]*b[ 2] + a[13]*b[ 6] + a[14]*b[10] + a[15]*b[14];
    resultData[15] = a[12]*b[ 3] + a[13]*b[ 7] + a[14]*b[11] + a[15]*b[15];
        
    return Matrix4x4(resultData);
}


float Matrix4x4::operator[](int i) const
{
    return entries[i];
}

const float * Matrix4x4::Data() const
{
    
    return entries;
}

Vector4 operator*(const Matrix4x4& a, const Vector4& b)
{
    const float * d = a.Data();
    return 
    {
        d[ 0]*b.x + d[ 1]*b.y + d[ 2]*b.z + d[ 3]*b.w,
        d[ 4]*b.x + d[ 5]*b.y + d[ 6]*b.z + d[ 7]*b.w,
        d[ 8]*b.x + d[ 9]*b.y + d[10]*b.z + d[11]*b.w,
        d[12]*b.x + d[13]*b.y + d[14]*b.z + d[15]*b.w
    };
}

Vector4 operator*(const Matrix4x4& a, const Vector3& b)
{
    const float * d = a.Data();
    return 
    {
        d[ 0]*b.x + d[ 1]*b.y + d[ 2]*b.z + d[ 3],
        d[ 4]*b.x + d[ 5]*b.y + d[ 6]*b.z + d[ 7],
        d[ 8]*b.x + d[ 9]*b.y + d[10]*b.z + d[11],
        d[12]*b.x + d[13]*b.y + d[14]*b.z + d[15]
    };
}

Matrix4x4 MatrixProject()  
{
    float data[16] = 
    {
        (float)Settings::GetLargestScreenDim()/2.f, 0,0,0,
        0,-(float)Settings::GetLargestScreenDim()/2.f,0,0,
        0, 0,-Settings::GetZMult(),0,
        0, 0,0,1
    };
    return Matrix4x4(data);
}

