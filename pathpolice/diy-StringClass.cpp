#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char * str;
    int strLen;

public:
    String()
    {
        str = NULL;
    }

    String(const char * s)
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    String(const String& ref)
    {
        str = new char[strlen(ref.str) + 1];
        strcpy(str, ref.str);
    }

    String& operator=(const String& ref)
    {
        delete []str;
        str = new char[strlen(ref.str) + 1];
        strcpy(str, ref.str);
        return *this;
    }

    String operator+(const String& ref)
    {
        char * tmp = new char[strlen(str) + strlen(ref.str)];
        strcpy(tmp, str);
        strcat(tmp, ref.str);

        String strTmp(tmp);

        return strTmp;
    }

    String& operator+=(const String& ref)
    {
        char * tmp = new char[strlen(str) + strlen(ref.str) + 1];
        strcat(tmp, str);
        strcat(tmp, ref.str);

        delete []str;
        str = tmp;

        return *this;
    }

    bool operator==(const String& ref)
    {
        if (strcmp(str, ref.str)==0)
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream& os, const String& s);
    friend istream& operator>>(istream& is, String& s);

    ~String()
    {
        delete []str;
    }
};

ostream& operator<<(ostream& os, const String& s)
{
    os<<s.str<<endl;
    return os;
}

istream& operator>>(istream& is, String& s)
{
    char str[100];
    is>>str;
    s = String(str);

    return is;
}

int main(void)
{
	String str1="I like ";
	String str2="string class";
	String str3=str1+str2;

	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;

	str1+=str2;
	if(str1==str3) 	
		cout<<"동일 문자열!"<<endl;
	else
		cout<<"동일하지 않은 문자열!"<<endl;

	String str4;
	cout<<"문자열 입력: ";
	cin>>str4;
	cout<<"입력한 문자열: "<<str4<<endl;
	return 0;
}