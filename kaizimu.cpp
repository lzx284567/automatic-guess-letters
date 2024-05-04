#include <bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
string dic[200]={"A Balanced Diet","A Complete Catalogue","A Furious Cocktail","A Seedy Place","A Terrible Fortress","A Throwaway Joke","Acquire Hardware","Adventuring Time","Arbalistic","Beaconator","Bee Our Guest","Best Friends Forever","Birthday Song","Blowback","Bring Home the Beacon","Bullseye","Careful Restoration","Caves & Cliffs","Country Lode, Take Me Home","Cover Me in Debris","Cover Me with Diamonds","Crafters Crafting Crafters","Crafting a New Look","Diamonds","Enchanter","Eye Spy","Feels Like Home","Fishy Business","Free the End","Getting an Upgrade","Glow and Behold","Good as New","Great View From Up Here","Hero of the Village","Hidden in the Depths","Hired Help","Hot Stuff","Hot Tourist Destinations","How Did We Get Here","Husbandry","Ice Bucket Challenge","Into Fire","Is It a Balloon","Is It a Bird","Is It a Plane","Isn't It Iron Pick","Isn't It Scute","It Spreads","Light as a Rabbit","Lighten Up","Little Sniffs","Local Brewery","Minecraft","Monsters Hunted","Nether","Not Today, Thank You","Oh Shiny","Ol' Betsy","Over-Overkill","Planting the Past","Postmortal","Remote Getaway","Respecting the Remnants","Return to Sender","Revaulting","Serious Dedication","Shear Brilliance","Sky's the Limit","Smells Interesting","Smithing with Style","Sneak 100","Sniper Duel","Sound of Music","Spooky Scary Skeleton","Star Trader","Sticky Situation","Stone Age","Subspace Bubble","Suit Up","Surge Protector","Sweet Dreams","Tactical Fishing","Take Aim","The City at the End of the Game","The Cutest Predator","The End","The End... Again...","The End","The Healing Power of Friendship","The Next Generation","The Parrots and the Bats","The Power of Books","The Whole Pack","This Boat Has Legs","Those Were the Days","Total Beelocation","Two Birds, One Arrow","Two by Two","Under Lock and Key","Uneasy Alliance","Very Very Frightening","Voluntary Exile","War Pigs","Wax Off","Wax On","We Need to Go Deeper","What a Deal","Whatever Floats Your Goat","When the Squad Hops into Town","Who Needs Rockets","Who is Cutting Onions","Who's the Pillager Now","With Our Powers Combined","Withering Heights","You Need a Mint","You've Got a Friend in Me","Zombie Doctor"};
bool used[200],firstkai=1;
int n,cnt=1,index,sum=1,guessb;
string abef[200];
string aaft[200];
string guess;
char f,mode,eat;
vector <char>yikai;
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
		cout<<endl;
	}
}
void init(){
	for(int i=0;i<200;i++){
		aaft[i]="                                                                ";
	}
	cout<<"请说出词的数量："; 
	cin>>n;
	srand(time(0));
	while(cnt<=n){
		index=rand()%117;//0-116
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
}
int main(){
	//0-117
	init();
	while(sum<=n){
		cout<<"输入1以开一个字母，输入2以猜一个词"<<endl;
		cin>>mode;
		if(mode=='1'){
			cout<<"开什么字母？"<<endl;
			cin>>f;
			system("cls");
			if((find(yikai.begin(),yikai.end(),f) != yikai.end()) && firstkai==0){
				cout<<"这个字母已经开过咯~"<<endl;
				sayzm();
			}else{
				firstkai=0;
				yikai.push_back(f);
				cout<<"已开：";
				for(int i=0;i<yikai.size();i++){
					cout<<yikai[i]<<' ';
				}
				cout<<endl;
				if(f>='1' && f<='9'){
					kai(f);
					sayzm();
				}else if(f>='A' && f<='Z'){
					kai(f);
					kai(char(f+'a'-'A'));
					sayzm();
				}else if(f>='a' && f<='z'){
					kai(f);
					kai(char(f-'a'+'A'));
					sayzm();
				}else{
					cout<<"输入无效！"<<endl;
				}
			}
			
		}else if(mode=='2'){
			cout<<"请输入编号和你猜的词，必须一字不差"<<endl;
			cin>>guessb;
			scanf("%c",&eat); 
		 	getline(cin,guess);
		 	if(abef[guessb]==guess){
		 		cout<<"恭喜你猜对了！"<<endl;
		 		aaft[guessb]=abef[guessb];
		 		sum++;
			}else{
				cout<<"恭喜你猜错了！"<<endl;
			}
		}else{
			cout<<"不是哥们，你输入的是啥？？"<<endl;
		}
	}
	cout<<"恭喜把题全部猜对！"<<endl;
	cout<<"Thanks for playing!"; 
	return 0;
}
