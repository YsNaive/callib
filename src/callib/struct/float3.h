#ifndef CALLIB_FLOAT3_H_
#define CALLIB_FLOAT3_H_

namespace collib{
    struct float3
    {
        float x;
        float y;
        float z;

        float3();
        float3(float xVal, float yVal, float zVal);
        
        float3 operator + (float3 const &f3);
        float3 operator - (float3 const &f3);
        float3 operator * (float3 const &f3);
        float3 operator / (float3 const &f3);
        float3 operator * (float const &f);
        float3 operator / (float const &f);

        float sum();
    };
}


#endif