/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <cstdio>
#include <cstring>

/*length Ϊ�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���*/
void ReplaceBlank(char str[], int length)
{
    if(str == nullptr && length <= 0)
        return;

    /*originalLength Ϊ�ַ���str��ʵ�ʳ���*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;

        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}

// ====================���Դ���====================
void Test(const char* testName, char str[], int length, const char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// �ո��ھ����м�
void replaceSpacesTest1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("replaceSpacesTest1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void replaceSpacesTest2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("replaceSpacesTest2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void replaceSpacesTest3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("replaceSpacesTest3", str, length, "helloworld%20");
}

// �����������ո�
void replaceSpacesTest4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("replaceSpacesTest4", str, length, "hello%20%20world");
}

// ����nullptr
void replaceSpacesTest5()
{
    Test("replaceSpacesTest5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void replaceSpacesTest6()
{
    const int length = 100;

    char str[length] = "";
    Test("replaceSpacesTest6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void replaceSpacesTest7()
{
    const int length = 100;

    char str[length] = " ";
    Test("replaceSpacesTest7", str, length, "%20");
}

// ������ַ���û�пո�
void replaceSpacesTest8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("replaceSpacesTest8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void replaceSpacesTest9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("replaceSpacesTest9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    replaceSpacesTest1();
    replaceSpacesTest2();
    replaceSpacesTest3();
    replaceSpacesTest4();
    replaceSpacesTest5();
    replaceSpacesTest6();
    replaceSpacesTest7();
    replaceSpacesTest8();
    replaceSpacesTest9();

    return 0;
}

