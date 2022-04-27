#include <iostream>
#include <string>
#include <cstddef>
#include <locale>

using namespace std;

int main()
{
	/* C-style string exemple */
	{
		char* strHello = new char[7];
		strcpy_s(strHello, sizeof(char) * 7, "hello!");
		cout << strHello << "\n";
	}	 

	/* basic_string<> - string, wstring */
	{
		// basic_string이라는 클래스의 템플릿의 서로 다른 인스턴시에이션
		string str;
		wstring wstr;

		// wchar_t = unsigned short
		// 긴 문자열 또는 국제어 unicode를 위해 사용한다.
		wchar_t wc;

		const std::wstring texts[] =
		{
			 L"안녕하세요", //Korean
			 L"Ñá", //Spanish
			 L"forêt intérêt", //French
			 L"Gesäß", //German
			 L"取消波蘇日奇諾", //Chinese
			 L"日本人のビット", //Japanese
			 L"немного русский", //Russian
			 L"ένα κομμάτι της ελληνικής", // Greek
			 L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
			 L"کمی از ایران ", // Persian (I know it, from 300 movie)
			 L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
			 L"Но какво, по дяволите, е това?" //Bulgarian
		};

		cout << "여러 나라 문자들 \n";
		
		std::locale::global(std::locale("")); // 시스템이 사용하는 locale로 지정 
		wcout.imbue(std::locale());

		for (size_t i = 0; i < texts->size(); ++i)
			wcout << texts[i] << endl;
	}
}