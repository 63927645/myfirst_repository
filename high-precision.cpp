#include <iostream>
#include <string>
#include <cctype>
using namespace std;


void swap1(int a[],int b[]){
    int smp[210]={0};
    for(int i=0;i<210;i++){
        smp[i]=a[i];
        a[i]=b[i];
        b[i]=smp[i];
    }
}


void swap2(string s1,string s2){
    string s3;
    s3=s1;
    s1=s2;
    s2=s3;
}


// 比较两个高精度数字的大小
// 返回值: 1 (A > B), 0 (A == B), -1 (A < B)
int compareStrings(const string &A, const string &B) {
    if (A.size() != B.size()) {
        return A.size() > B.size() ? 1 : -1;
    }
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] != B[i]) {
            return A[i] > B[i] ? 1 : -1;
        }
    }
    return 0;
}


void highadd(string s1,string s2,int a){
    int a1[210]={0},a2[210]={0},a3[210]={0};
    int tmp;


    for(int i=0;i<s1.size();i++){
        a1[s1.size()-i-1]=s1[i]-'0';
    }
    for(int i=0;i<s2.size();i++){
        a2[s2.size()-i-1]=s2[i]-'0';
    }
    int len=s1.size();
    if(s1.size()<s2.size()){
        len=s2.size();
    }


    for(int i=0;i<len;i++){
        a3[i]=a1[i]+a2[i];
    }
    for(int i=0;i<len;i++){
        if(a3[i]>=10){
            a3[i]-=10;
            a3[i+1]++;
        }
    }

    if(a3[len]!=0){
        len++;
    }

    
    cout << "运算结果是： " << endl;

    if(a!=0){
        cout << "-";
    }

    for(int i=len-1;i>=0;i--){
        cout << a3[i];
    }
}


void highminus(string s1,string s2){
    int a1[210]={0},a2[210]={0},a3[210]={0};
    int tmp;


    for(int i=0;i<s1.size();i++){
        a1[s1.size()-i-1]=s1[i]-'0';
    }
    for(int i=0;i<s2.size();i++){
        a2[s2.size()-i-1]=s2[i]-'0';
    }


    int q=0;


    if(s1.size()<s2.size()){
        swap1(a1,a2);
        swap2(s1,s2);
        q++;
    }
    else{
        for(int i=0;i<s1.size();i++){
            if(a1[s1.size()-i-1]<a2[s1.size()-i-1]){
                swap1(a1,a2);
                swap2(s1,s2);
                q++;
                break;
            }
            else if(a1[s1.size()-i-1]>a2[s1.size()-i-1]){
                break;
            }
        }
    }


    int len=s1.size();
    if(s1.size()<s2.size()){
        len=s2.size();
    }
    for(int i=0;i<len;i++){
        a3[i]=a1[i]-a2[i];
    }


    for(int i=0;i<len;i++){
        if(a3[i]<0){
            a3[i]=a3[i]+10;
            a3[i+1]=a3[i+1]-1;
        }
    }


    for(int i=len-1;i>=0;i--){
        if(a3[i]==0){
            len--;
        }
        else if(a3[i]!=0){
            break;
        }
    }


    cout << "运算结果是： " << endl;

    
    if(q!=0){
        cout << "-";
    }
    
    
    for(int j=len-1;j>=0;j--){
        if(a3[j]!=0){
            for(int i=j;i>=0;i--){
                cout << a3[i];
            }
            break;
        }
    }
}


void highmultipication(string s1,string s2){
    int a1[210]={0},a2[210]={0},a3[210]={0};
    int tmp;
    int type1=0;


    if(s1[0]=='-'){
        type1++;
        s1.erase(0,1);
    }
    if(s2[0]=='-'){
        type1++;
        s2.erase(0,1);
    }


    for(int i=0;i<s1.size();i++){
        a1[s1.size()-1-i]=s1[i]-'0';
    }
    for(int i=0;i<s2.size();i++){
        a2[s2.size()-1-i]=s2[i]-'0';
    }

    for(int i=0;i<s2.size();i++){
        for(int j=0;j<s1.size();j++){
            a3[i+j]+=a1[j]*a2[i];
        }
    }


    for(int i=0;i<s1.size()+s2.size();i++){
        while(a3[i]/10!=0){
            a3[i]-=10;
            a3[i+1]++;
        }
    }


    cout << "运算结果是： " << endl;


    if(type1%2==1){
        cout << "-";
    }
    for(int j=s1.size()+s2.size();j>=0;j--){
            if(a3[j]!=0){
                for(int i=j;i>=0;i--){
                    cout << a3[i];
                }
                break;
            }
        }

}

int string_to_digit(string s2){
    int result=0;

    for(char C:s2){
        int digit=C-'0';
        result = result*10 + digit;
    }
    return result;
}


//被淘汰的除法——初级算法
void highdivision1_unsigned(string s1,string s2){
    int s4=string_to_digit(s2);
    if(s4==0){
        cout << "错误,除数不能为0。";
        return;
    }
    int a1[210]={0},a3[210]={0};


    int s3=string_to_digit(s2);

    for(int i=0;i<s1.size();i++){
        a1[i]=s1[i]-'0';
    }
    int C;
    int R;
    int q=0;


    int a2[210]={0};
    a2[0]=a1[0];
    for(int i=0;i<s1.size();i++){

        C=a2[i]/s3;
        if(C==0){
            a2[i+1]=a2[i]*10+a1[i+1];
            if(q!=0){
                a3[q]=0;
                q++;
            }
            continue;
        }
        else{
            a2[i+1]=a2[i] % s3*10+a1[i+1];
            a3[q]=a2[i] / s3;
            q++;
        }


    }
    cout << "运算所得商为：" << endl;
    if(q==0){
        cout << 0 << endl;
    }
    else{
        for(int i=0;i<q;i++){
            cout << a3[i];
        }
        cout << endl;
    }


    cout << "运算所得余数为： " << endl;
    if(q!=0){
        cout << a2[s1.size()]/10;
    }
    else{
        for(int i=0;i<s1.size();i++){
        cout << s1[i];
        }
    }
}







int main(){
    int inp;
    string s1;
    string s2;
    cout << "请输入第一个数字： " << endl;
    getline(cin,s1);
    cout << "请输入第二个数字： " << endl;
    getline(cin,s2);
    char op;
    cout << "请输入运算符（其中除法暂时不支持负数运算）： " << endl;
    cin >> op;
    switch(op){
        case '+':
        if(s1[0]!='-'&&s2[0]!='-'){
            highadd(s1,s2,0);
        }
        else if(s1[0]=='-'&&s2[0]!='-'){
            s1.erase(0,1);
            highminus(s2,s1);
        }
        else if(s1[0]!='-'&&s2[0]=='-'){
            s2.erase(0,1);
            highminus(s1,s2);
        }
        else{
            s1.erase(0,1);
            s2.erase(0,1);
            highadd(s1,s2,1);
        }
        break;
        case '-':
        if(s1[0]!='-'&&s2[0]!='-'){
            highminus(s1,s2);
        }
        else if(s1[0]=='-'&&s2[0]!='-'){
            s1.erase(0,1);
            highadd(s1,s2,1);
        }
        else if(s1[0]!='-'&&s2[0]=='-'){
            s2.erase(0,1);
            highadd(s1,s2,0);
        }
        else{
            s1.erase(0,1);
            s2.erase(0,1);
            highminus(s2,s1);
        }
        break;
        case '*':
        highmultipication(s1,s2);
        break;
        case '/':
        highdivision1_unsigned(s1,s2);
        break;
        

    }

    cin.get();
    cin.get();
    return 0;
}