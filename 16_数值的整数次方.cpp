#include <iostream>
using namespace std;

double Power(double base, int exponent)
{
    if(exponent<0)
    {
        if(base==0)
            throw new exception("error input");
        else
            return 1/Power(base, -exponent);
    }
    else if(exponent==0)
        return 0;
    else
    {
        double result=base;
        while(exponent>1)
        {
            result*=base;
            exponent--;
        }
        return result;
    }
}


double Power1(double base, int exponent)
{
    if(exponent<0)
    {
        if(base==0)
            throw new exception("error input");
        else
            return 1/Power1(base, -exponent);
    }
    else if(exponent==0)
        return 0;
    else
    {
        double result=base;
        int m=exponent%2;
        while(exponent/2)
        {
            double tmp=Power1(base,exponent>>1);
            result=tmp*tmp;
        }
        if(m)
            result*=base;
        return result;
    }

}
