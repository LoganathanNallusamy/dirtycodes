#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef struct result {
int iter;
int weigh;

}result;

int compa(const void *a,const void *b) {
	result *a1 = (result *)a;
        result *b1 = (result *)b;
        if (a1->weigh <= b1->weigh) return 1;
        return -1;  

}
int main()
{
   vector<result> res;
   result r;
   
   r.iter  = 0;   
   r.weigh = 51;   
   res.push_back(r);

   r.iter  = 1;   
   r.weigh = 41;   
   res.push_back(r);
  
   r.iter  = 2;   
   r.weigh = 131;   
   res.push_back(r);
   cout<<"Total size is "<<res.size()<<endl;

   qsort(&res[0], res.size(), sizeof(res[0]), compa);
   for(int i=0; i<res.size(); ++i) {
     cout<<"iter : "<<res[i].iter<<" weight "<<res[i].weigh<<endl;
   }

   return 0;
}
