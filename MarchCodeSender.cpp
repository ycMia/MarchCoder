#include<windows.h>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

bool CopyToClipboard(const char* pszData, const int nDataLen)
{
    if(::OpenClipboard(NULL))
    { 
        ::EmptyClipboard();
        HGLOBAL clipbuffer;
        char *buffer;
        clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen+1); 
        buffer = (char *)::GlobalLock(clipbuffer);
        strcpy(buffer, pszData);
        ::GlobalUnlock(clipbuffer);
        ::SetClipboardData(CF_TEXT, clipbuffer);
        ::CloseClipboard();
        return true;
    }
    return false;
}

int main()
{
	string str;
	string str2;
	
	cout<<"************************"<<endl
		<<"*--MarchCoder--ver1.0--*"<<endl
		<<"*--     SENDER       --*"<<endl
		<<"************************"<<endl<<endl
		<<"---Press in data before U"<<endl
		<<"---really have sent an   "<<endl
		<<"---enter - EOF(ctrl+Z) - enter "<<endl
		<<"---like this:"<<endl<<endl
		<<"---XXXXX(enter)"<<endl
		<<"---^Z(enter)"<<endl
		<<endl<<endl<<endl;
	while(true)
	{
		cout<<"ENJOY!>"<<endl;
			
		while(!cin.eof())
		{
			char z = 0;
			cin.get(z);
			if(z==EOF)
			{
				break;
			}
			str.push_back(z);
		}
		str.pop_back();
		
		int *str2intArr = new int[str.length()];
		stringstream ss;
		for(int i=0;i<str.length();i++)
		{
			str2intArr[i] = str[i];
		}
		
		//output
		for(int i=0;i<str.length();i++)
		{
	//		cout<<str2intArr[i]<<" ";
			str2intArr[i]++;
			ss<<str2intArr[i];
			ss<<" ";
		}
		
		cout<<endl;
		
		while(!ss.eof())
		{
			str2.push_back((char)ss.get());
			cout<<str2.back();
		}
		str2.pop_back();
		str2.pop_back(); 
		
		delete str2intArr;
		str2intArr = NULL;
		cout<<endl;
		
		CopyToClipboard(str2.c_str(),str2.length());
		
		cin.clear();
		cin.sync();
	}
//	system("pause");
	return 0;
}
