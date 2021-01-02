#include <stdio.h>
#include <conio.h>
#define INFINITY 999
#define MAX 10
void FindPath(int C[MAX][MAX], int n, int s); int main()
{
    int i,j,n,s;
    int C[MAX][MAX];
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix<999 for infinity>:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&C[i][j]);
    printf("\n Given Cost matrix \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(C[i][j] < 0)
            {
                printf(" \n\n ERROR..!! Negative Values are denied in the network\n"); return 0;
            }
            printf("%d \t" , C[i][j]);
        }
    printf("\n");
    }
for(;;)
    {
        printf("\nEnter the node whose distance table required, -1 to exit : "); scanf("%d",&s);
        if((s == -1) || (s > n-1))
        {
            printf("EXIT ..!!"); break;
        }
        FindPath(C,n,s);
    }
return 0;
}

void FindPath(int G[MAX][MAX], int n, int start)
{ int DT[MAX][4],value, k;
int i,j,count,nCount =0,min,nextNode;
int C[MAX][MAX],dist[MAX],path[MAX],v[MAX]; int RT[MAX][4];

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(G[i][j]==0)
            C[i][j] = INFINITY;
        else
            C[i][j] = G[i][j];
        for(i=0;i<n;i++)
        {
            dist[i]= C[start][i];
            if(C[start][i] != 0 && C[start][i] != 999)
            {
                nCount++;
            }
            path[i]=start; v[i]=0;
            for(j=0;j<4;j++)
        RT[i][j] = 0;
        }
        dist[start]= 0; v[start]=1; count =1;
        while(count < n-1)
        {
        min = INFINITY;
        for(i=0;i<n;i++)
        {
            if(dist[i] < min && !v[i])
            {
                min = dist[i]; 
                nextNode = i;
            }
        }

        v[nextNode] =1; for(i=0;i<n;i++)
        {
            if(!v[i])
            {
                if(min+C[nextNode][i] < dist[i])
                {
                dist[i] = min+C[nextNode][i]; 
                path[i]= nextNode;
                }
            }
        }
        count++;
        }
    k=0; 
    int next = start; 
    for(i=0;i<n;i++)
    {
    if(i != start)
    {
        RT[k][0] = i;
        RT[k][3] = dist[i];
        j=i;
        if(path[j]==start)
        {
            RT[k][1] =i;
            RT[k][2] = start;
            k++;
            continue;
        }
        else
        RT[k][2] = path[j];
        while(j !=start)
        {
        next = j;
        j= path[j];
        }
        if(next == i)
            RT[k][1] = start;
        else
            RT[k][1] = next;
            k++;
    }
}
printf("\n\tDISTANCE TABLE OF NODE %d \n",start);
printf("\n \n");
printf(" Dst node nextHop predHop distance\t\n");
for(i=0;i<n-1;i++)
{
    printf(" %d\t %d\t %d\t %d\t",RT[i][0],RT[i][1],RT[i][2],RT[i][3]); printf("\n");
}
printf("%d has %d neighbor \n", start,nCount);
for(i=0;i<n;i++)
{
    if(C[start][i] != 0 && C[start][i] != 999)
    {
        printf("Enter the DT of neighbor %d \n",i); for(k=0;k<n-1;k++)
        for(j=0;j<4;j++)
            scanf("%d",&DT[k][j]);
            for(j=0;j<4;j++)
            {
            if(RT[j][0]==i)
            value= RT[j][3];
            }
        for(j=0;j<n-1;j++)
        {
        if(DT[j][0] != start)
        {
            for(k=0;k<4;k++)
            {
            if(RT[k][0]==DT[j][0])
            {
                if(RT[k][3] > (value + DT[j][3]))
                {
                    RT[k][3] = (value + DT[j][3]);
                    RT[k][1] = DT[j][1];
                    RT[k][2] = DT[j][2];
                }
            break;
            }
            }
        }
        }
printf("\n\tUPADATED DISTANCE TABLE OF NODE %d \n",start);
printf("\n \n");
printf(" Dst node nextHop predHop distance\t\n");
for(j=0;j<n-1;j++)
{
    printf(" %d\t %d\t %d\t %d\t",RT[j][0],RT[j][1],RT[j][2],RT[j][3]);
    printf("\n");
}
}
}
}

