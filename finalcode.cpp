#include <iostream>
#include <cstring>

using namespace std;

class projectinfo
{               
    public:
    char na[100];
    int ht,py,dsa,j,sql;
    bool ar0,ar1,ar2,ar3,ar4;
};

class candidateinfo
{
    public:
    char na[100];
    int ht,py,dsa,j,sql;
};

/* The following functions are used to allocate mentioned roles if needed and                                                                      
once allocated the specific candidate is not going to be allocated to any other role.  
This is done by making all the skill levels of that candidate as -1*/

void htallocator(candidateinfo* c,int n,projectinfo* p,int m,int* men,int i)
{
    bool allo=true;
    while(allo)
     {
              for(int j=0 ; j<n ; j++)
               {
                  if(p->ht==0)break;    //checks if project has a html role

                  else if( p->ht<=c[j].ht)  //If needed, checks whether candidate has skills greater than or equal to required
                   {
                     if(p->ht<c[j].ht)men[i]++;  //If candidate has high skill than required then it is noted in men array
                       p->ar0=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;
                       break;
                   }

                   else if(p->ht-c[j].ht == 1 && men[i]>0) //If candidate has skill one less than required then men array is checked and if it is non zero this is allocated
                   {
                     men[i]--;                              //men count is decremented
                     p->ar0=1;                              //men stands for mentors
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;
                       break;
                   }
                   else allo=false;
               }
          
          break;
     }
}

void pyallocator(candidateinfo* c,int n,projectinfo* p,int m,int* men,int i)
{
   bool allo=true;
    while(allo)
     {
              for(int j=0 ; j<n ; j++)
               {
                if(p->py==0)break;

               else if(p->py<=c[j].py)
                   {
                   if(p->py<c[j].py)men[i]++;
                       p->ar1=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;break;
                   }
                else if(p->py-c[j].py==1 && men[i]>0)
                {
                men[i]--;
                    p->ar1=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1; 
                       allo=true;break;
                }
                   else allo=false;
               }
          break;
     }
}

void dsaallocator(candidateinfo* c,int n,projectinfo* p,int m,int* men, int i)
{
   bool allo=true;
    while(allo)
     {
              for(int j=0 ; j<n ; j++)
               {
               if(p->dsa ==0 )break;
               else if(p->dsa<=c[j].dsa)
                   {
                   if(p->dsa<c[j].dsa)men[i]++;
                       p->ar2=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;break;
                   }

                else if(p->dsa-c[j].dsa==1 && men[i]>0)
                {
                 men[i]--;
                 p->ar2=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;break;

                }
                   else allo=false;
               }
          break;
     }
     
}

void jallocator(candidateinfo* c,int n,projectinfo* p,int m,int* men, int i)
{
    bool allo=true;
    while(allo)
     {
         
              for(int j=0 ; j<n ; j++)
               {
               if(p->j ==0 )break;

               else if(p->j<=c[j].j)
                   {
                   if(p->j <=c[j].j )men[i]++;
                       p->ar3=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;break;
                   }
                else if(p->j-c[j].j==1 && men[i]>0)
                  {
                   men[i]--;
                   p->ar3=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;break;
                  }
                   else allo=false;
               }
          
          break;
     }
}

void sqlallocator(candidateinfo* c,int n,projectinfo* p,int m,int* men, int i)
{
    bool allo=true;
    while(allo)
     {
              for(int j=0 ; j<n ; j++)
               {
               if(p->sql ==0)break;

               else if(p->sql<=c[j].sql)
                   {
                    if(p->sql<c[j].sql) men[i]++;
                       p->ar4=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;break;
                   }
                else if(p->sql-c[j].sql==1 && men[i]>0)
                  {
                    men[i]--;
                    p->ar4=1;
                       c[j].py=c[j].ht=c[j].dsa=c[j].sql=c[j].j=-1;
                       allo=true;break;
                  }
                   else allo=false;
               }
          break;
     }
}

int mcounter(projectinfo* p,int m)
{
int numcomp=0;
    for(int i=0 ; i<m ; i++)
     {
        if(p[i].ht==0 && p[i].py==0 && p[i].j==0 && p[i].sql==0 && p[i].dsa==0) continue;
       
        if(((p[i].ht!=0 && p[i].ar0==1)||p[i].ht==0)&& ((p[i].py!=0 && p[i].ar1==1)||p[i].py==0)&& ((p[i].dsa!=0 && p[i].ar2==1)||p[i].dsa==0)&& ((p[i].j!=0 && p[i].ar3==1)||p[i].j==0) && ((p[i].sql!=0 && p[i].ar4==1)||p[i].sql==0))
        numcomp++;
     }

     return numcomp;
}

int zerocounter(projectinfo p)
 {
     int count=0;
     if(p.ht==0)count++; if(p.py==0)count++;if(p.dsa==0)count++;if(p.j==0)count++;if(p.sql==0)count++;
     return count;
 }
 
void projectsorter(projectinfo* p,int m) //sorts the projectinfo array in ascendong order of number of roles present
{
    for(int i=m ; i>0 ; i--)
     {
         for(int j=1 ; j<i ; j++)
          {
              if(zerocounter(p[j])>zerocounter(p[j-1]))
               {
                   projectinfo x=p[j];
                   p[j]=p[j-1];
                   p[j-1]=x;
               }
          }
     }
}

template <typename y>void fetcher(char* ar,y& x) // splits the string and stores accordingly
{
    int val[5]={0,0,0,0,0};
    
    char* tok = strtok(ar," ");int i=0;
    for( i ; tok[i]!='\0';i++)x.na[i]=tok[i];
    x.na[i]='\0';
    i=0;
    int t=0;
    
    while(tok != NULL)
     {
        if(i==0){i++;tok=strtok(NULL," "); continue;}
        bool flag;
        
        for(int x=0 ; tok[x]!='\0' ; x++)
         { 
             flag=false;
             if( (tok[x]>='a'&&tok[x]<='z') || (tok[x]>='A'&&tok[x]<='Z') ){flag=true;break;}
         }
         
         if(flag==true){tok=strtok(NULL," ");continue;}
         
         else {val[t++]=(tok[0]-48);tok=strtok(NULL," ");}
     }
     x.ht=val[0];x.py=val[1];x.dsa=val[2];x.j=val[3];x.sql=val[4];
}

int main()
{
    int n,m;
    
    cin>>n>>ws;
    candidateinfo c[n];

    for(int i=0 ; i<n ; i++)c[i].ht=c[i].py=c[i].dsa=c[i].j=c[i].sql=0;
        
     for(int i=0 ; i<n ; i++)
     {
        char ar[1000];
       cin.getline(ar,1000);
        
        fetcher<candidateinfo>(ar,c[i]);
     }   
     
   cin>>m>>ws;
    projectinfo p[m];
    int men[m];
    for(int i=0 ; i<m ; i++)men[i]=0; // for checking availability of mentors

     
    for(int i=0 ; i<m ; i++)p[i].ht=p[i].py=p[i].dsa=p[i].j=p[i].sql=0;
    for(int i=0 ; i<m ; i++)p[i].ar0=p[i].ar1=p[i].ar2=p[i].ar3=p[i].ar4=0;

    for(int i=0 ; i<m ; i++)
     {
        char ar[1000];
       cin.getline(ar,1000);
        
        fetcher<projectinfo>(ar,p[i]);
     }
     
     projectsorter(p,m); // project with least number of role are allocated first

for(int i=0 ; i<m ; i++)
{
     htallocator(c,n,&p[i],m,men,i);    //For a particular project allocates all the required roles and moves on to the next
     pyallocator(c,n,&p[i],m,men,i);
     dsaallocator(c,n,&p[i],m,men,i);
     jallocator(c,n,&p[i],m,men,i);
     sqlallocator(c,n,&p[i],m,men,i);
}
     cout<<mcounter(p,m);

    return 0;
}
