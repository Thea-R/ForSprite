#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;

int n;
int ci=144, cn=138, cp=112;
string ssi[]={"A","Bae","Baek","Bak","Ban","Bang","Beom","Beon","Bi","Bin","Bing","Bong","Bu","Cha","Chang","Cho","Choe","Chong","Chu","Chun","Da","Dae","Dam","Dan","Dang","Deungjeong","Dok","Dokgo","Don","Dong","Dongbang","Du","Eo","Eogeum","Eom","Eum","Gae","Gal","Gam","Geum","Geun","Gi","Gil","Gim","Go","Gong","Guk","Gung","Gwak","Gwan","Gwon","Gyeon","Gyeong","Gyo","Ha","Hae","Hak","Ham","Han","Heo","Ho","Hong","Hu","Hwa","Hwan","Hwang","Hwangbo","Hwangmok","Hyeong","I","Im","In","Jam","Jang","Je","Jeo","Jeong","Jeup","Jin","Ju","Jun","Kwae","Mae","Maeng","Man","Mangjeol","Mi","Min","Mo","Mok","Mu","Muk","Myeong","Myo","Na","Nae","No","Noe","Nu","O","Ong","Pan","Po","Pung","Pyeon","Pyeong","Pyo","Ra","Ran","Rang","Roe","Ryeo","Sa","Sagong","Sam","Seo","Seok","Seomun","Seong","Seonu","Seung","Si","Sim","Sin","So","Song","Su","Sun","Tae","Tak","Tan","Tang","U","Un","Wan","Wang","Won","Ya","Yeong","Yeop","Yo","Yong","Yu","Yuk"};
string san[]={"Abe","Adati","Aizawa","Akimoto","Akiyama","Andou","Aoyagi","Arai","Araki","Araya","Asada","Asano","Azuma","Baba","Eguti","Endou","Fukazawa","Fukuda","Fukui","Fukumoto","Fukunaga","Fukuoka","Fukusima","Furukawa","Fuzii","Fuzimoto","Fuzimura","Fuzino","Fuzita","Fuziwara","Hamada","Hamaguti","Hamano","Hara","Harada","Haraguti","Hasegawa","Hatakeyama","Hatanaka","Hattori","Hayakawa","Hayasi","Hayasida","Hidaka","Higa","Higuti","Hiramatu","Hirano","Hirata","Hirayama","Hirose","Hirota","Honma","Horiguti","Horikawa","Horiuti","Hosi","Hosokawa","Hotta","Iiduka","Iizima","Ikeda","Ikegami","Imamura","Inada","Inagaki","Inoue","Isibasi","Isida","Isiguro","Isihara","Isii","Isiyama","Itikawa","Itou","Iwai","Iwamoto","Iwase","Iwata","Izumi","Kamata","Kamei","Kamiya","Kanai","Kanazawa","Kaneda","Kanesiro","Kanno","Kanou","Kasahara","Kasiwagi","Kataoka","Kawabata","Kawaguti","Kawahara","Kawai","Kawamoto","Kawamura","Kawasima","Kawata","Kaziwara","Kimura","Kitagawa","Kitano","Kitazima","Kobayasi","Koga","Koide","Koizumi","Komatu","Komori","Kondou","Konisi","Kosaka","Kouda","Kouno","Koyanagi","Kozima","Kubo","Kubota","Kudou","Kumagaya","Kurihara","Kurita","Kuroda","Kurokawa","Kurosawa","Maeda","Makino","Matubara","Matui","Matumoto","Matumura","Matuno","Matuoka","Matusita","Matuyama","Matuzaki","Miki","Minami","Misima","Miura","Miwa","Miyagawa","Miyahara","Miyamoto","Miyasita","Miyata","Miyazaki","Miyazawa","Miyazima","Miyosi","Mizoguti","Mizuno","Mizutani","Mogi","Mori","Morikawa","Morioka","Morisita","Morita","Motiduki","Mukai","Murai","Murakami","Murase","Murayama","Nagaoka","Nagasima","Nagata","Naitou","Nakagawa","Nakahara","Nakanisi","Nakao","Nakata","Nakatani","Nakayama","Nakazima","Narita","Negisi","Nemoto","Ninomiya","Nisi","Nisida","Nisihara","Nisikawa","Nisimoto","Nisimura","Nisio","Nisioka","Nisiyama","Nisizawa","Niwa","Noda","Noguti","Nomura","Nozaki","Numata","Oda","Ogasawara","Ogata","Ogawa","Ogino","Oikawa","Oka","Okabe","Okamoto","Okano","Okazaki","Okuda","Okumura","Okuyama","Ono","Onodera","Ooba","Oohira","Ookawa","Ookubo","Oomori","Oomura","Oonisi","Oono","Oosaki","Oosawa","Oosima","Oosiro","Oota","Ootake","Ootuka","Oouti","Oti","Otiai","Ozawa","Saeki","Saitou","Sakaguti","Sakai","Sakakibara","Sakamoto","Sakata","Sakuma","Sakurai","Satou","Seki","Sekine","Senda","Seto","Sibata","Sibuya","Simada","Simamura","Simizu","Simura","Sinden","Sinoda","Sinohara","Sinozaki","Siraisi","Sonoda","Suda","Sudou","Sugahara","Suge","Sugihara","Sugimoto","Sugita","Sugiura","Suzuki","Syouzi","Tabata","Taguti","Tahara","Takada","Takagi","Takahasi","Takai","Takase","Takasima","Takeda","Takei","Takemura","Takenaka","Takesita","Taketa","Takeuti","Takizawa","Tamura","Tanabe","Tani","Tanigawa","Tanoue","Tasiro","Tazima","Terada","Terazima","Tiba","Tomita","Toyoda","Tuda","Tukada","Tukamoto","Tutiya","Tutui","Tutumi","Tuzi","Ueda","Uehara","Uemura","Umeda","Uno","Usui","Utiyama","Wada","Yagi","Yaguti","Yamaguti","Yamamoto","Yamamura","Yamanaka","Yamane","Yamaoka","Yamazaki","Yano","Yasuda","Yazima","Yokawa","Yokoi","Yokota","Yokoyama","Yosida","Yosihara","Yosii","Yosimoto","Yosimura","Yosino","Yosizawa","Yuasa"};
string p[]={"a","ae","ba","be","bi","bo","bu","bya","byo","byu","da","de","do","e","eo","eu","ga","ge","gi","go","gu","gya","gyo","gyu","ha","he","hi","ho","hu","hya","hyo","hyu","i","ke","ki","ko","ku","kya","kyo","kyu","ma","me","mi","mo","mu","mya","myo","myu","n","na","ne","ni","no","nu","nya","nyo","nyu","o","oe","pa","pe","pi","po","pu","pya","pyo","pyu","ra","re","ri","ro","ru","rya","ryo","ryu","sa","se","si","so","su","sya","syo","syu","ta","te","ti","to","tu","tya","tyo","tyu","u","ui","wa","wae","we","wi","wo","ya","yae","ye","yeo","yo","yu","za","ze","zi","zo","zu","zya","zyo","zyu"};
double ti=1386, tn=1409;
double si[]={526,148,8,10,14,15,3,0,0,0,6,7,12,827,604,106,20,26,46,16,50,1,12,23,73,48,11,41,72,2,1,0,1387,0,1,0,2,0,0,1,10,1,24,13,8,0,0,0,1073,16,4,11,4,9,0,5,1,883,10,4,0,5,0,1,0,16,0,24,3,23,5,0,0,5,3,13,102,1387,6,62,0,0,0,12,0,1,2,1,0,0,0,582,57,70,0,0,6,32,6,0,291,274,58,58,0,0,0,0,0,0,0,0};
double sn[]={1409,21,4,0,3,1,20,0,0,0,12,19,5,292,6,0,9,8,5,11,10,0,0,0,51,1,56,43,0,0,0,0,861,25,141,82,39,0,1,0,28,14,122,36,11,0,0,0,1409,139,31,6,100,1,0,1,0,660,9,0,5,0,0,0,0,0,0,30,15,123,71,63,0,0,0,1409,21,80,1,50,2,0,1,44,4,44,84,97,0,0,0,650,22,12,1,0,0,1,60,1,0,0,83,98,1,0,34,10,63,0,0,5};

set<string> sti, stn;

void init()
{
	for(int i=0; i<ci; i++) sti.insert(ssi[i]);
	for(int i=0; i<cn; i++) stn.insert(san[i]);
	for(int i=0; i<cp; i++)	si[i]/=ti, sn[i]/=tn;
	return ;
}

void judge(string a, string b)
{
	if(sti.find(a)!=sti.end())	printf("-ssi\n");
	else if(stn.find(a)!=stn.end())	printf("-san\n");
	else
	{
		double pi=0, pn=0;
		for(int i=0; i<cp; i++) if(b.find(p[i])!=-1)
		{
			if(si[i]==0 && sn[i]==0)	continue;
			else if(si[i]==0)
			{
				++pn;
			}
			else if(sn[i]==0)
			{
				++pi;
			}
			else
			{
				++pn, ++pi;
			}
		}
		if(pi>=pn)	printf("-ssi\n");
		else printf("-san\n");
	}
	return ;
}

int main()
{
	init();

	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		string a, b;
		cin>>a>>b;
		for(int j=0; j<a.size(); j++) printf("%c", a[j]);
		printf(" ");
		for(int j=0; j<b.size(); j++) printf("%c", b[j]);
		judge(a, b);
	}
	return 0;
}
