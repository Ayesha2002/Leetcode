class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n=commands.size();
        int ans=0;
        char dir='N';
        set<pair<int,int>> st;
        for(auto it:obstacles){
            st.insert({it[0],it[1]});
        }
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            if(commands[i]==-2){
                if(dir=='N'){
                    dir='W';
                }
                else if(dir=='W'){
                    dir='S';
                }
                else if(dir=='S'){
                    dir='E';
                }
                else if(dir=='E'){
                    dir='N';
                }
            }
            else if(commands[i]==-1){
                if(dir=='N'){
                    dir='E';
                }
                else if(dir=='W'){
                    dir='N';
                }
                else if(dir=='S'){
                    dir='W';
                }
                else if(dir=='E'){
                    dir='S';
                }
            }
            else{
                int dir_x=0;
                int dir_y=0;
                if(dir=='N'){
                    dir_x=0;
                    dir_y=1;
                }
                else if(dir=='E'){
                    dir_x=1;
                    dir_y=0;
                }
                else if(dir=='W'){
                    dir_x=-1;
                    dir_y=0;
                }
                else if(dir=='S'){
                    dir_x=0;
                    dir_y=-1;
                }
                cout<<dir<<endl;
                for(int j=1;j<=commands[i];j++){
                    int nrow=x+dir_x;
                    int ncol=y+dir_y;

                    if(st.count({nrow,ncol})==1){
                        break;
                    }

                    x=nrow;
                    y=ncol;

                    cout<<x<<" "<<y<<endl;
                }

                int temp=x*x+y*y;
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
