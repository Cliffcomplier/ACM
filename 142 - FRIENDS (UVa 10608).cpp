/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 47117
 * Submitted at:  2017-12-17 16:42:22
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    142
 * Problem Name:  FRIENDS (UVa 10608)
 */

#include <stdio.h>
int fa[30001],tot[30001];
int find(int u)
{
    fa[u]==u?u:fa[u]=find(fa[u]);
    return fa[u];

}
int main()
{
    int t,n,m,i,x,y,u,v,maxx;
      scanf("%d",&t);
        while (t--)
          {
              scanf("%d%d",&n,&m);
                for (i=1;i<=n;i++) {fa[i]=i,tot[i]=0;}
                  for (i=1;i<=m;i++)
                  {
                      scanf("%d%d",&u,&v);
                        x=find(u);y=find(v);
                      if (x!=y) fa[x]=y;
                  }
                  for (i=1;i<=n;i++) tot[find(i)]++;
                maxx=tot[1];
              for (i=2;i<=n;i++) if (tot[i]>maxx) maxx=tot[i];
            printf("%d\n",maxx);
          }
    return 0;
}