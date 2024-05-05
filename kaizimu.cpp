#include <bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
string /*×Öµä*/dic[2000]={"A Balanced Diet","A Complete Catalogue","A Furious Cocktail","A Seedy Place","A Terrible Fortress","A Throwaway Joke","Acquire Hardware","Adventuring Time","Arbalistic","Beaconator","Bee Our Guest","Best Friends Forever","Birthday Song","Blowback","Bring Home the Beacon","Bullseye","Careful Restoration","Caves & Cliffs","Country Lode, Take Me Home","Cover Me in Debris","Cover Me with Diamonds","Crafters Crafting Crafters","Crafting a New Look","Diamonds","Enchanter","Eye Spy","Feels Like Home","Fishy Business","Free the End","Getting an Upgrade","Glow and Behold","Good as New","Great View From Up Here","Hero of the Village","Hidden in the Depths","Hired Help","Hot Stuff","Hot Tourist Destinations","How Did We Get Here","Husbandry","Ice Bucket Challenge","Into Fire","Is It a Balloon","Is It a Bird","Is It a Plane","Isn't It Iron Pick","Isn't It Scute","It Spreads","Light as a Rabbit","Lighten Up","Little Sniffs","Local Brewery","Minecraft","Monsters Hunted","Nether","Not Today, Thank You","Oh Shiny","Ol' Betsy","Over-Overkill","Planting the Past","Postmortal","Remote Getaway","Respecting the Remnants","Return to Sender","Revaulting","Serious Dedication","Shear Brilliance","Sky's the Limit","Smells Interesting","Smithing with Style","Sneak 100","Sniper Duel","Sound of Music","Spooky Scary Skeleton","Star Trader","Sticky Situation","Stone Age","Subspace Bubble","Suit Up","Surge Protector","Sweet Dreams","Tactical Fishing","Take Aim","The City at the End of the Game","The Cutest Predator","The End","The End... Again...","The End","The Healing Power of Friendship","The Next Generation","The Parrots and the Bats","The Power of Books","The Whole Pack","This Boat Has Legs","Those Were the Days","Total Beelocation","Two Birds, One Arrow","Two by Two","Under Lock and Key","Uneasy Alliance","Very Very Frightening","Voluntary Exile","War Pigs","Wax Off","Wax On","We Need to Go Deeper","What a Deal","Whatever Floats Your Goat","When the Squad Hops into Town","Who Needs Rockets","Who is Cutting Onions","Who's the Pillager Now","With Our Powers Combined","Withering Heights","You Need a Mint","You've Got a Friend in Me","Zombie Doctor"};
bool used[2000],firstkai=1,correct[2000];
int n=12345678,cnt=1,index,sum=1,guessb;
string abef[2000];
string aaft[2000];
string guess;
char f,mode,eat;
vector <char>yikai;//ÒÑ¾­¿ª¹ýµÄ´Ê 

void kai(char x){
	for(int i=1;i<=n;i++){
		for(int j=0;j<aaft[i].length();j++){
			if(abef[i][j]==x){
				aaft[i][j]=x;
			}
		}
	}
}
void sayzm(){
	for(int i=1;i<=n;i++){
		cout<<i<<'.';
		for(int j=0;j<aaft[i].length();j++){
			cout<<aaft[i][j];
		}
		if(correct[i]) cout<<"£¨ÒÑ¿ª¶Ô£©";
		cout<<endl;
	}
}
void init(){
	for(int i=0;i<200;i++){
		aaft[i]="                                                                ";
	}
	cout<<"ÇëËµ³ö´ÊµÄÊýÁ¿£º"; 
	while(n>117){
		cin>>n;
		if(n>117) cout<<"nµÄÊýÁ¿Ì«´ó£¬±ØÐëÐ¡ÓÚµÈÓÚ117£¡"<<endl;
	}
	srand(time(0));
	while(cnt<=n){
		index=rand()%117;//×ÖµäÒ»¹²117¸ö´Ê£¬ÏÂ±êÎª0-116£¬rand()%117Êä³öµÄÊÇ0-116µÄËæ»úÊý 
		if(!used[index]){
			abef[cnt]=dic[index];
			cnt++;
			used[index]=1;
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<i<<'.';
		for(int j=0;j<abef[i].length();j++){
			if(abef[i][j]!=' '){
				aaft[i][j]='*';
				cout<<aaft[i][j];
			}else{
				aaft[i][j]=' ';
				cout<<aaft[i][j];
			}
		}
		cout<<endl;
	}
	//abefÊÇ´Ó×ÖµäÀïËæ»úÑ¡È¡µÄ´Ê£¬aaftÊÇ½«ËûÃÇ×ª»»ÎªÈ«ÊÇ*ºÍ¿Õ¸ñÖ®ºóµÄ´Ê 
}
bool dequal(string a,string b){//´óÐ¡Ð´²»Ãô¸ÐµÄÅÐ¶ÏÏàµÈ 
	for(int i=0;i<a.length();i++){
		if(a[i]>='A' && a[i]<='Z'){
			a[i]+='a'-'A';
		}
	}
	for(int i=0;i<b.length();i++){
		if(b[i]>='A' && b[i]<='Z'){
			b[i]+='a'-'A';
		}
	}
	//È«×ª»»³ÉÐ¡Ð´
	if(a==b) return 1;
	return 0; 
}
int main(){
	//0-117
	init();
	while(sum<=n){
		cout<<"ÊäÈë1ÒÔ¿ªÒ»¸ö×ÖÄ¸£¬ÊäÈë2ÒÔ²ÂÒ»¸ö´Ê"<<endl;
		mode=_getch();
		if(mode=='1'){
			cout<<"¿ªÊ²Ã´×ÖÄ¸£¿"<<endl;
			f=_getch();
			system("cls");//ÇåÆÁ 
			if((find(yikai.begin(),yikai.end(),f) != yikai.end()) && firstkai==0){
				cout<<"Õâ¸ö×ÖÄ¸ÒÑ¾­¿ª¹ý¿©~"<<endl;
				sayzm();
			}else{
				firstkai=0;
				yikai.push_back(f);
				cout<<"ÒÑ¿ª£º";
				for(int i=0;i<yikai.size();i++){
					cout<<yikai[i]<<' ';
				}
				cout<<endl;
				
				if(f>='A' && f<='Z'){//Èç²ÂµÄÊÇ´óÐ´×ÖÄ¸£¬Ôò½«Ð¡Ð´Ò»¿é¿ªÁË 
					kai(f);
					kai(char(f+'a'-'A'));
				}else if(f>='a' && f<='z'){//Èç²ÂµÄÊÇÐ¡Ð´×ÖÄ¸£¬Ôò½«´óÐ´Ò»¿é¿ªÁË 
					kai(f);
					kai(char(f-'a'+'A'));
				}else if(int(f)>32 && int(f)<127){
					kai(f);
				}else{
					cout<<"ÊäÈëÎÞÐ§£¡"<<endl;
				}
				sayzm();
			}
			
		}else if(mode=='2'){
			cout<<"ÇëÊäÈë±àºÅºÍÄã²ÂµÄ´Ê£¬±ØÐëÒ»×Ö²»²î£¨µ«ÊÇ´óÐ¡Ð´²»Ãô¸Ð£©"<<endl;
			cin>>guessb;
			scanf("%c",&eat); //³ÔµôÖÐ¼äµÄ¿Õ¸ñ 
		 	getline(cin,guess);
		 	if(dequal(abef[guessb],guess)){
		 		system("cls");
		 		cout<<"¹§Ï²Äã²Â¶ÔÁË£¡"<<endl;
		 		aaft[guessb]=abef[guessb];
		 		sum++;//sumÊÇ²Â¶ÔµÄ´ÊÊý
		 		correct[guessb]=1;
		 		sayzm();
			}else{
				system("cls");
				cout<<"¹§Ï²Äã²Â´íÁË£¡"<<endl;
				sayzm();
			}
		}else{
			system("cls");
			cout<<"²»ÊÇ¸çÃÇ£¬ÄãÊäÈëµÄÊÇÉ¶£¿£¿"<<endl;
			sayzm();
		}
	}
	cout<<"¹§Ï²°ÑÌâÈ«²¿²Â¶Ô£¡"<<endl;
	cout<<"¿ªµÄ×ÖÄ¸Êý£º"<<yikai.size()<<endl; 
	cout<<"Thanks for playing!"; 
	return 0;
}
