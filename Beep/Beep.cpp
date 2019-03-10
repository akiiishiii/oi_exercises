#include<windows.h>
#include<fstream>
#include"Music.hpp"
using namespace std;
fstream f;
int main(int count,char **chars)
{f.open(chars[1]);
 if(!f)
   {if(count<3)cout<<"打开文件失败";
    return -1;
   }
 {string s="",sin;
  while(f>>sin)s+=sin;
  f.close(); 
  int c;
  for(c=0;;c++)
  {if(s[c]=='`')break;
   cout<<s[c];
  }
  int tl=0;
  for(c++;s[c]!='`';c++)
     {tl*=10;
      tl+=s[c]-'0';
	 } 
  int len=0;
  for(int i=c;i<s.length();i++)
     if(s[i]>='0'&&s[i]<='7')len++;
  cout<<len<<endl;
  Music M(len);
  for(int i=0;i<len;i++)
     {int t=tl,add=0;
      double so=1;
      while(1)
      {c++;
	   if(s[c]=='+')
         {so/=2;
	 	 }
	   if(s[c]=='-')
	     {add+=tl;
	     }
	   if(s[c]=='/')
	     {t/=2;
		 }
	   if(s[c]=='*')
	     {so*=2;
		 }
	   if(s[c]>='0'&&s[c]<='7')
	     {DWORD sou=so*sound[s[c]-'0'].Hz;
	      Sound soun;
	      soun.Hz=sou;
	      int ft=t+add;
	      M.Set(i,soun,ft);
		  break;
		 }
	  }
	 }
  M.Play();
 }
 return 0;
}
