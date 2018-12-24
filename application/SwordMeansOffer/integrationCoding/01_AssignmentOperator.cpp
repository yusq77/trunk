/*  Copyright (C) 2018 * Ltd. All rights reserved.
 *      Create date : 2018-12-11 10:54:00
 *================================================*/

/* 01 assignmenti operators*/
#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(const char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();

private:
    char* m_pData;
};

CMyString::CMyString(const char *pData)
{
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

// senior programmer
CMyString& CMyString::operator = (const CMyString& str)
{
    if(this != &str)
    {
        CMyString strTemp(str);

        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}

/*
// junior programmer
CMyString& CMyString::operator = (const CMyString& str)
{
    if(this == &str)
        return *this;

    delete []m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
*/

// ==================== AssignmentOperatorTesting ====================
void CMyString::Print()
{
    printf("%s", m_pData);
}

void AssignmentOperatorTest1()
{
    printf("AssignmentOperatorTest1 begins:\n");

    const char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// myself assignment
void AssignmentOperatorTest2()
{
    printf("AssignmentOperatorTest2 begins:\n");

    const char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// continues assignment
void AssignmentOperatorTest3()
{
    printf("AssignmentOperatorTest3 begins:\n");

    const char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    AssignmentOperatorTest1();
    AssignmentOperatorTest2();
    AssignmentOperatorTest3();

    return 0;
}

