    #include<bits/stdc++.h>
    using namespace std;
    int main() {
        int r,x,y,x1,y1;
        scanf("%d %d %d %d %d",&r,&x,&y,&x1,&y1);
        double d=sqrt(pow((y1-y),2)+pow((x1-x),2));
        cout<<ceil(d/(2*r))<<endl;
        return 0;
    }