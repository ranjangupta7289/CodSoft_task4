#include <iostream>
#include<vector>
#include<string>
using namespace std;
class listnode{
    public:
     string data;
     bool status;
     listnode(string str){data=str;status=false;}
};
void showlist(vector<listnode*>&list,string &listname){int size=list.size();
    if(size==0){cout<<"Your list "<<listname<<" is empty.Nothing to show."<<endl;return;}
    cout<<listname<<endl;
    cout<<"serial no. "<<"     status"<<"              Description"<<endl;
    for(int i=1;i<=size;i++){
        cout<<"     "<<i;
        if(list[i-1]->status){cout<<"         done           ";}
        else{cout<<"         pending       ";}
        cout<<list[i-1]->data<<endl;
    }

}
bool changestatus(vector<listnode*>&list,int pos,bool done){int size=list.size();
    if(pos>size||pos<1){return false;}
    list[pos-1]->status=done;return true;
}
void adddata(vector<listnode*>&list,string &description){
    int s=list.size();
    listnode*a=new listnode(description);
    list.push_back(a);
}
bool deletedata(vector<listnode*>&list,int pos){
    if(pos>list.size()){return false;}
    delete(list[pos-1]);
    for(int i=pos-1;i<list.size();i++){list[i]=list[i+1];}
    list.pop_back();return true;
}
int main()
{
    cout<<endl<<"Welcome to application of To do list."<<endl;
    while(true){
        cout<<"Let's first give your list a name."<<endl<<"Enter name of your list below"<<endl;
        string listname;
        getline(cin, listname);
        //cin>>listname;
        vector<listnode*>list;
        bool endlist=false;
        while(true){
            cout<<"press "<<endl;
            cout<<"1 to see list"<<endl;
            cout<<"2 to add new task to list"<<endl;
            cout<<"3 to change status of a task in list"<<endl;
            cout<<"4 to delete a task from list"<<endl;
            cout<<"5 to exit from list"<<endl;
            int input;cin>>input;cin.ignore();
            
            if(input==1){
                showlist(list,listname);
        }
            else if(input==2){
                string data1;
                cout<<"Enter description for your new task"<<endl;
                getline(cin, data1);
                adddata(list,data1);
                cout<<"New task has been added succesfully."<<endl;
                }
            else if(input==3){
                cout<<"Enter serial number for which you want to change status."<<endl;
                int sno;cin>>sno;cin.ignore();
                int statu;
                while(true){cout<<"Enter 1 for done and 2 for not done"<<endl;cin>>statu;if(statu!=1&&statu!=2){cout<<"enter valid input and try again."<<endl;}else{break;}}
                bool send;if(statu==1){send=true;}else{send=false;}
                bool done=changestatus(list,sno,send);
                if(done){cout<<"Status changed succesfully."<<endl;}
                else{cout<<"status change failed, task did not exist."<<endl;}
                }
            else if(input==4){
                cout<<"Enter serial number of task that you want to delete."<<endl;
                int pos;cin>>pos;cin.ignore();
                bool done=deletedata(list,pos);
                if(done){cout<<"task deleted succesfully."<<endl;}
                else{cout<<"task deletion failed, task did not exist."<<endl;}
                }
            else if(input==5) 
                {endlist=true;}
                
            
            else
                {cout<<"Enter a valid input and try again"<<endl;}
                
            
            if(endlist){break;}
        }
        bool playagain;
        while(true){
            cout<<"Enter 0 to exit application 1 to create another list."<<endl;
            int inputuser;
            cin>>inputuser;cin.ignore();
            if(inputuser==0){playagain=false;break;}
            else if(inputuser==1){playagain=true;break;}
            else{cout<<"Please enter a valid input"<<endl;}
            }
            if(playagain){continue;}
            else{break;}
    }

    return 0;
}