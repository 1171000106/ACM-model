#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct LinearBasis{
    int sz,cnt;
    ll bs[74],p[74];
    set<int>num;
    LinearBasis(int Sz=63){
        sz=Sz;cnt=0;
        memset(p,0,sizeof(p));
        memset(bs,0,sizeof(bs));
        num.clear();
    }
    bool ins(ll x,int sit){ // ����
        for(ll i=sz-1,bin=(1LL<<(sz-1));i>=0;i--,bin>>=1){
            if(x&bin){
                if(!bs[i]){
                    bs[i]=x;
                    num.insert(sit);
                    break;
                }
                x^=bs[i];
            }
        }
        return x>0;
    }
    /**
        ���Ҫ��֤һ�������Ƿ�����������Կռ�Ļ���ֻ��Ҫ��������ֲ������Ի���
        �������false����������ִ��ڣ����򲻴��ڡ�
    **/
    ll getmax(){ // ��ȡ�������ռ��ڵ����ֵ
        ll res=0;
        for(ll i=sz-1;i>=0;i--){
            if((res^bs[i])>res)res^=bs[i];
        }
        return res;
    }
    ll getmin(){ // ��ȡ�������ռ��ڵ���Сֵ
        for(ll i=0;i<sz;i++){
            if(bs[i])return bs[i];
        }
        return 0;
    }
    void rebuild(){ // �ع����Ի������ڲ�ѯ��kС
        for(int i=sz-1;i>=0;i--)
            for(int j=i-1;j>=0;j--)
                if(bs[i]&(1LL<<j))bs[i]^=bs[j];
        for(int i=0;i<sz;i++)
        if(bs[i])p[cnt++]=bs[i];
    }
    ll getK(ll k){// ��ȡ�������ռ��е�kС��ֵ
        ll ret=0;
        if(k>=(1LL<<cnt))return -1;
        for(int i=sz-1;i>=0;i--)
            if(k&(1LL<<i))ret^=p[i];
        return ret;
    }
};
// �ϲ���������
LinearBasis Merge(const LinearBasis &n1,const LinearBasis &n2){
    LinearBasis ret=n1;
    for(int i=n2.sz-1;i>=0;i--)
        if(n2.bs[i])ret.ins(n2.bs[i],i);
    return ret;
}

// ���Ի��󽻼�
LinearBasis Inter(LinearBasis n1,LinearBasis n2){
    LinearBasis a=n2,b=n2;
    LinearBasis ret=LinearBasis();
    for(int i=0;i<n1.sz;i++){
        if(!n1.bs[i])continue;
        ll temp=0,x=n1.bs[i];
        int j;
        for(j=i;j>=0;j--){
            if(x&(1LL<<j)){
                if(a.bs[j]){
                    x^=a.bs[j];
                    temp^=b.bs[j];
                }
                else break;
            }
        }
        if(x==0)ret.bs[i]=temp;
        else{
            a.bs[j]=x;
            b.bs[j]=temp;
        }
    }
    return ret;
}
int main(){

    return 0;
}
