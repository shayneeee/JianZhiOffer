#include <iostream>
#include <cstring>
using namespace std;

class CMyString
{
public:
    CMyString(char *pData=nullptr);
    CMyString(const CMyString  &str);
    ~CMyString();
    CMyString& operator=(const CMyString &str);
private:
    char *m_pData;
};
CMyString::CMyString(char *pData):m_pData(pData){}
CMyString::CMyString(const CMyString &str)
{
    m_pData=new char[strlen(str.m_pData)+1];
    strcpy(this->m_pData,str.m_pData);
}
CMyString::~CMyString(){delete []m_pData;}

CMyString& CMyString::operator=(const CMyString &str)
{
    if (this==str)
        return *this;

    if(m_pData)
        delete []m_pData;

    m_pData=new char[strlen(str.m_pData)+1];
    strcpy(this->m_pData,str.m_pData);
    return *this;
}

CMyString& CMyString::operator=(const CMyString &str)
{
    if(this!=&str)
    {
        CMyString tmps(str);

        char *tmpp=tmps.m_pData;
        tmps.m_pData=this->m_pData;
        this->m_pData=tmpp;
    }
    return *this;
}

int main()
{
    return 0;
}
