#include"algorithm"  
#include"map"  
#include"vector"  
#include"string"  
#include"iostream"  
#include"stack"  
using namespace std;  
  
#define max 300  
#define inf 2100000000//!!!  
int dis[max][max]={0};  
int n=0;  
int visited[max]={0};  
int father[max]={0};  
int same[max]={0};  
int happies[max]={0};  
int finalhappies[max]={0};  
int precnt[max]={0};  
map<int,string> cityname;  
map<string,int> citynum;  
stack<string> ans;  
void dijstrak(int s)  
{    
    same[0]=1;  
    visited[s]=1;  
    for(int i=0;i<n;i++)  
    {  
         int min=inf;  
         int mark=-1;  
         for(int j=0;j<n;j++)  
         {//find min  
             if(visited[j]==0&&dis[s][j]<min)  
             {  
                min=dis[s][j];  
                mark=j;  
             }  
         }  
         if(mark==-1)  
             return ;  
         visited[mark]=1;//marked  
         for(int k=0;k<n;k++)  
         {//updata  
             if(visited[k]==1)  
                 continue;  
             int raw=dis[s][k];  
             int another=dis[s][mark]+dis[mark][k];  
            if(raw>another)  
            {   same[k]=same[mark];  
                dis[s][k]=dis[s][mark]+dis[mark][k];  
                father[k]=mark;  
                finalhappies[k]=finalhappies[mark]+happies[k];  
                precnt[k]=precnt[mark]+1;  
            }  
            else if(raw==another)  
            {  
                same[k]+=same[mark];  
                if(finalhappies[k]<finalhappies[mark]+happies[k])  
                {  
                    father[k]=mark;  
                    finalhappies[k]=finalhappies[mark]+happies[k];  
                    precnt[k]=precnt[mark]+1;  
                }  
                else if(finalhappies[k]==finalhappies[mark]+happies[k])  
                {  
                   if(precnt[k]>(precnt[mark]+1))  
                   {  
                       father[k]=mark;  
                       precnt[k]=precnt[mark]+1;  
                   }  
                }  
            }  
  
            }  
                  
         }  
    }  
  
int main()  
{  
    for(int i=0;i<max;i++)  
        for(int j=0;j<max;j++){  
            dis[i][j]=inf;  
            dis[j][i]=inf;  
            dis[i][i]=inf;  
            dis[j][j]=inf;  
    }  
   int k=0;  
   string s;  
   cin>>n>>k>>s;  
   cityname[0]=s;  
   string citystr;  
   int happy=0;  
   for(int i=1;i<n;i++)  
   {  
    cin>>citystr>>happy;  
    cityname[i]=citystr;  
    citynum[citystr]=i;  
    happies[i]=happy;  
    finalhappies[i]=happy;  
    precnt[i]=1;  
    same[i]=1;  
   }  
   string city1,city2;  
   int cost=0;  
   for(int i=0;i<k;i++){  
     cin>>city1>>city2>>cost;  
     int j=citynum[city1];  
     int b=citynum[city2];  
     dis[j][b]=cost;  
     dis[b][j]=cost;  
   }  
  
   dijstrak(0);     
  
   int romanum=citynum["ROM"];  
   int index=romanum;  
   string path;  
   path+=s;//"HZH"  
   ans.push("ROM");  
   while(father[index]!=0)  
   {  
     string pathcity=cityname[father[index]];  
     ans.push(pathcity);  
     index=father[index];  
   }  
   while(!ans.empty()){  
       path+="->";  
       path+=ans.top();  
       ans.pop();  
   }  
   cout<<same[romanum]<<" "<<dis[0][romanum]<<" "<<finalhappies[romanum]<<" "<<finalhappies[romanum]/precnt[romanum]<<endl;  
   cout<<path<<endl;  
  return 0;  
}