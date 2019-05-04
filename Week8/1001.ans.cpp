#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string  S="";                                                              //开始符号 
struct  { int number;string sign[20]; bool get[20];bool enable[20]; string result[20]; } not_endsign={0};   //非终结符
struct  { int number;string sign[20];} end_sign={0};                      //终结符
struct  { int number;string left[100],right[100];bool enable[100] ; } production={0};        //产生式 

struct  { int number;string sign[20];bool exit[20]; string result[20] ;} out={0};  

void input();        //输入开始符号、非终结符、终结符、产生式 
void print();        //打印结果 
bool into(string a,string b);
bool reachable(string test);
bool reach(string test);
bool ceyan();
 
int main(){
    input();        
    for(int i=0;i<production.number;i++ ){
        if(production.left[i]==production.right[i]){
            production.enable[i] = 0;
            cout<<"delete self production:"<<production.left[i]<<"::="<<production.right[i]<<endl;    
        }          
    } 
    
    for(int i=0;i<not_endsign.number;i++){
        for(int j=0;j<production.number;j++){
            if(not_endsign.sign[i]==production.left[j]&&production.enable[j] ){
                not_endsign.result[i]+=production.right[j]+" | ";  
            }
        }  
        if(S==not_endsign.sign[i] ) not_endsign.enable[i] = 0;
    }
    
    for(int i=0;i<not_endsign.number;i++){
        if(S == not_endsign.sign[i]) not_endsign.enable[i] = 0;        
    }
        
    bool xunhuan = 1;
    while(xunhuan ){
        //每循环一次检查一次“不可达非终结符”  
        xunhuan = 0;       
        for(int i=not_endsign.number-1;i>=0;i-- ){  
            if(not_endsign.enable[i] && !reachable(not_endsign.sign[i]) ){
                not_endsign.enable[i] = 0; 
                cout<<"unreached Vn:"<<not_endsign.sign[i]<<endl;
                cout<<"delete VN:"<<not_endsign.sign[i]<<endl;
                xunhuan = 1; 
                for(int j=0;j<production.number;j++ ){
                    if(into(not_endsign.sign[i],production.left[j] )|| into(not_endsign.sign[i],production.right[j] )  ){
                        if(production.enable[j])  {
                            production.enable[j] = 0;  
                            cout<<"delete production:"<<production.left[j]<<"::="<<production.right[j]<<endl; 
                        }
                            
                    }
                }
                
            }
        }
        
        //每次循环一次检查一次“不可用非终结符” 
        for(int i=not_endsign.number-1;i>=0;i-- ){
            bool det = 0;
            for(int j=0;j< not_endsign.result[i].length();j++ ){
                if(reach (not_endsign.result[i].substr(j,1)) )  det = 1;
            }
            
            if(!det&&not_endsign.enable[i]==1){
                xunhuan = 1;
                not_endsign.enable[i] = 0;
                cout<<"unusefulNv:"<<not_endsign.sign[i]<<endl;
                cout<<"delete VN:"<<not_endsign.sign[i]<<endl;
                for(int j=0;j<production.number;j++ ){
                    if(into(not_endsign.sign[i],production.left[j] )|| into(not_endsign.sign[i],production.right[j] )  ){
                        if(production.enable[j]) {  
                            production.enable[j] = 0;
                            cout<<"delete production:"<<production.left[j]<<"::="<<production.right[j]<<endl;     
                        } 
                    }
                }
            }
        } 
        
    }
        
    print();
    return 0; 
} 

//测试test中是否有终结符 
bool reach(string test){
    for(int i=0;i<end_sign.number;i++){
        if(test==end_sign.sign[i]) return 1;
    } 
    return 0;
} 

//测试test是否可达 
bool reachable(string test){
    for(int i=0;i<production.number;i++){
        if(production.enable[i] &&into(test,production.right[i] ) )  return 1;
    }  
    return 0;
} 

bool  into(string a,string b){
    //a是待测试的非终结符，单字符，即产生式左边的部分 
    for(int i=0;i<b.size();i++){
        if(a==b.substr(i,1) ) return 1;
    }  
    return 0;
}

void print(){
    cout<<"G["<<S<<"]:\n";
    for(int i=0;i<not_endsign.number;i++ ){
        out.exit[out.number] = 0;
        out.sign[out.number++ ] = not_endsign.sign[i];
        
    }
    
    for(int i=0;i<production.number;i++){
        for(int j=0;j<out.number;j++){
            if(production.enable[i]){ 
                if(production.left[i]==out.sign[j] ){
                    out.result[j]+=production.right[i]+" | ";
                    out.exit[j] = 1;
                }
            } 
        }
    }
    
    for(int i=0;i<out.number;i++){
        if(out.exit[i]){ 
            cout<<out.sign[i]<<"::="<<out.result[i].substr(0,out.result[i].length()-3 )<<endl;
        }
    }
    
    return ;
} 

void input(){
    //输入开始符号 
    cin>>S;
    
    //输入非终结符 
    cin>>not_endsign.number;
    for(int i=0;i<not_endsign.number;i++ ){
        cin>>not_endsign.sign[i];
        not_endsign.get[i] = 0;        //说明非终结符没有输入源   
        not_endsign.enable[i] = 1;  //说明非终结符现在还可用，还没被删除 
    }
    
    //输入终结符 
    cin>>end_sign.number;
    for(int j=0;j<end_sign.number;j++ ){
        cin>>end_sign.sign[j];
    }
    
    //输入产生式 
    cin>>production.number;
    for(int z=0;z<production.number;z++){
        cin>>production.left[z]>>production.right[z];
        production.enable[z] = 1;   //说明该产生式还可用，还没被删除   
    }
    return ;
}