#include<Windows.h>
#include<iostream>
using namespace std;
struct Sound
{DWORD Hz;
 void beep(int len)
 {Beep(Hz,len);
 }
};

Sound
do_[3]={{128},{256},{512}},
re_[3]={{144},{288},{576}},
mi_[3]={{160},{320},{640}},
fa_[3]={{171},{341},{683}},
so_[3]={{192},{384},{768}},
la_[3]={{213},{427},{853}},
si_[3]={{240},{480},{960}};
Sound sound[8]=
{{0},
 {256},
 {288},
 {320},
 {341},
 {384},
 {427},
 {480}
};
struct Music
{Sound *s;
 int lenth;
 DWORD *len;
 Music(int Lent)
 {lenth=Lent;
  s=new Sound[lenth];
  len=new DWORD[lenth];
 }
 ~Music()
 {delete[]s;
  delete[]len;
 }
 void Set(int pos_from_0,Sound S,DWORD lent)
 {*(s+pos_from_0)=S;
  *(len+pos_from_0)=lent;
 }
 void Play()
 {for(int i=0;i<lenth;i++)
     {Beep(s[i].Hz,len[i]);
     cout<<s[i].Hz<<" "<<len[i]<<endl;
      //Sleep(len[i]); 
	 }
 }
};

