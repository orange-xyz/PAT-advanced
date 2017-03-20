#include<iostream>  
#include<string>  
#include<cstdio>  
#include<cstring>  
#include<vector>  
#include<set>  
#include<map>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
struct road  
{  
    vector<int> path;  
    int costSum;  
    int happinessSum;  
}tmp;  
map<int,string> idToName;  
map<string,int> nameToId;  
map<int,int> idToHappiness;  
vector<int> path;  
vector<struct road> ans;  
bool visited[205];  
int mapx[205][205];  
int n;  
void dfs(int st,int ed,int costSum,int happiniessSum)  
{  
    if(st==ed)  
    {  
        tmp.path.clear();  
        int len=path.size();  
        for(int i=0;i<len;++i)  
            tmp.path.push_back(path[i]);  
        tmp.costSum=costSum;  
        tmp.happinessSum=happiniessSum;  
        ans.push_back(tmp);  
        return;  
    }  
    for(int i=0;i<n;++i)  
    {  
        if(mapx[st][i]>0&&(!visited[i]))  
        {  
            path.push_back(i);  
            costSum+=mapx[st][i];  
            happiniessSum+=idToHappiness[i];  
            visited[i]=true;  
            dfs(i,ed,costSum,happiniessSum);  
            visited[i]=false;  
            costSum-=mapx[st][i];  
            happiniessSum-=idToHappiness[i];  
            path.pop_back();  
        }  
    }  
}  
bool cmp(const struct road &a,const struct road &b)  
{  
    return a.costSum!=b.costSum?(a.costSum<b.costSum):(a.happinessSum!=b.happinessSum?(a.happinessSum>b.happinessSum):(a.happinessSum/(double)(a.path.size()-1)>b.happinessSum/(double)(b.path.size()-1)));  
}  
int main()  
{  
    int k,a,endCity;  
    char c[15],s[15];  
    scanf("%d%d%s",&n,&k,c);  
    idToName.insert(make_pair(0,string(c)));  
    nameToId.insert(make_pair(string(c),0));  
    idToHappiness.insert(make_pair(0,0));  
    for(int i=1; i<n; ++i)  
    {  
        scanf("%s%d",c,&a);  
        idToName.insert(make_pair(i,string(c)));  
        nameToId.insert(make_pair(string(c),i));  
        idToHappiness.insert(make_pair(i,a));  
        if(strcmp(c,"ROM")==0) endCity=i;  
    }  
    memset(mapx,0,sizeof(mapx));  
    for(int i=0,ida,idb;i<k;++i)  
    {  
        scanf("%s%s%d",c,s,&a);  
        ida=nameToId[string(c)];  
        idb=nameToId[string(s)];  
        mapx[ida][idb]=mapx[idb][ida]=a;  
    }  
    memset(visited,false,sizeof(visited));  
    path.push_back(0);  
    visited[0]=true;  
    dfs(0,endCity,0,0);  
    sort(ans.begin(),ans.end(),cmp);  
    int out=ans[0].costSum,countx=1;  
    for(;out==ans[countx].costSum;++countx);  
    printf("%d %d %d %d\n",countx,ans[0].costSum,ans[0].happinessSum,(int)(ans[0].happinessSum/(double)(ans[0].path.size()-1)));  
    printf("%s",idToName[ans[0].path[0]].c_str());  
    for(int i=1;i<ans[0].path.size();++i)  
         printf("->%s",idToName[ans[0].path[i]].c_str());  
    printf("\n");  
    return 0;  
}  