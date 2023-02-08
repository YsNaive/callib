#include "float3.h"

namespace collib{

    float3::float3(){
        x = 0;
        y = 0;
        z = 0;
    }
    float3::float3(float xVal, float yVal, float zVal){
        x = xVal;
        y = yVal;
        z = zVal;
    }

    float3 float3::operator+ (float3 const &f3){
        float3 output;
        output.x = x + f3.x;
        output.y = y + f3.y;
        output.z = z + f3.z;
        return output;
    }
    float3 float3::operator- (float3 const &f3){
        float3 output;
        output.x = x - f3.x;
        output.y = y - f3.y;
        output.z = z - f3.z;
        return output;
    }
    float3 float3::operator* (float3 const &f3){
        float3 output;
        output.x = x * f3.x;
        output.y = y * f3.y;
        output.z = z * f3.z;
        return output;
    }
    float3 float3::operator/ (float3 const &f3){
        float3 output;
        output.x = x / f3.x;
        output.y = y / f3.y;
        output.z = z / f3.z;
        return output;
    }

    float3 float3::operator* (float const &f){
        float3 output;
        output.x *= f;
        output.y *= f;
        output.z *= f;
        return output;
    }
    float3 float3::operator/ (float const &f){
        float3 output;
        output.x /= f;
        output.y /= f;
        output.z /= f;
        return output;
    }

    float float3::sum(){
        return x+y+z;
    }
}