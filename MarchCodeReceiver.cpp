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
	int * intArr;
	
	cout<<"************************"<<endl
		<<"*--MarchCoder--ver1.0--*"<<endl
		<<"*--    RECEIVER      --*"<<endl
		<<"************************"<<endl<<endl
		<<"---Press in data U have..."<<endl<<endl<<endl;
	while(true)
	{
		string strOut;
		intArr = new int [1024*1024];
		cout<<"RECEIVE>"<<endl;
		int count=0;
		for(int i=count;cin.peek()!='\n';i++,count++)
		{
			cin>>intArr[i];
			intArr[i]--;
		}
		
		//	cout<<"out of : "<<count;
		
		for(int i = 0;i<count;i++)
		{
			strOut.push_back((char)intArr[i]);
		}
		
		cout<<strOut<<endl;
		
		delete intArr;
		intArr = NULL;
			
		cin.clear();
		cin.sync();
	}
	
	return 0;
}
