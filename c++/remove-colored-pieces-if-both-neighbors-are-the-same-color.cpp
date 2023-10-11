class Solution {
public:
    bool solve(int i,int n,string &colors,bool flag)
    {
        if(i==n-2)
        {
            if(flag==true)return false;
            else return true;
        }
        if(flag==true)
        {
            if(colors[i]!=colors[i+1]|| colors[i]!=colors[i+2]||
            colors[i]!='A')
            {
                return false;
            }
            colors.erase(colors.begin()+i+1);
            solve(i+1,n,colors,false);
        }
        if(flag==false)
        {
           if(colors[i]!=colors[i+1]|| colors[i]!=colors[i+2]||
            colors[i]!='B')
            {
                return true;
            }
            colors.erase(colors.begin()+i+1);
            solve(i+1,n,colors,true);
        }
         
         
        return 1;
    }
    bool winnerOfGame(string colors) {
        bool flag=true;
        int n=colors.size();
        int alice=0;
        int bob=0;
        for(int i=1;i<n-1;i++)
        {
            if(colors[i]==colors[i-1]&& colors[i]==colors[i+1])
            {
                if(colors[i]=='A')
                {
                    alice++;
                }
                else
                {
                    bob++;
                }
            }
        }
        return alice>bob;
    }
};
