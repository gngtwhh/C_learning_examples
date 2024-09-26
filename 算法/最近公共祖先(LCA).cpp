//P3379
#include<iostream>
using namespace std;
const int maxn=500010;
int f[maxn][33];
int n,m,s;
struct edge
{
    int to,next;
} e[2*maxn];
int cnt;
int head[maxn];
void add(int u,int v)
{

    e[++cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int dep[maxn];
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    for(int i=0;i<32&&f[x][i];++i)
    {
f[x][i+1]=f[f[x][i]][i];//递推式
}
for(int i=head[x];i!=0;i=e[i].next)
{
    int y=e[i].to;
    if(y!=fa) f[y][0]=x,dfs(y,x);
}
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=dep[x]-dep[y],k=0;i;i>>=1,++k)
    {
        if(i&1) x=f[x][k];
    }
    if(x==y) return x;
    for(int i=32;i>=0;--i)
    {
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
int main()
{
    cin>>n>>m>>s;
    int a,b;
    for(int i=1;i<=n-1;++i)
    {
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dep[s]=1;
    dfs(s,0);
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}