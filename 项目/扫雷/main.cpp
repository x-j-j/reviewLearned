//可以运行***********************
#include <iostream>
using namespace std;
void printthem(int nm[30][30], int n, int m) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(nm[i][j] == -1)
                cout<<nm[i][j]<<" ";
             else
                cout<<nm[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void addlei(int GamePanel[30][30], int nm[30][30], int n, int m, int x, int y, int num) {
    int sum = 0;
    for(int time=1; time<=2; ++time) {
        if(x>=1 && y>=1)
            if(GamePanel[x-1][y-1] == -1 || nm[x-1][y-1] == 999) {
                if(time == 1)
                    ++sum;
                else
                    nm[x-1][y-1] = 999;
            }
        if(y >= 1)
            if(GamePanel[x][y-1] == -1 || nm[x][y-1] == 999) {
                if(time == 1)
                    ++sum;
                else
                    nm[x][y-1] = 999;
            }
        if(x<=n-2 && y>=1)
            if(GamePanel[x+1][y-1] == -1 || nm[x+1][y-1] == 999) {
                if(time == 1)
                    ++sum;
                else
                    nm[x+1][y-1] = 999;
            }
        if(x >= 1)
            if(GamePanel[x-1][y] == -1 || nm[x-1][y] == 999)
            {
                if(time == 1)
                    ++sum;
                else
                    nm[x-1][y] = 999;
            }
        if(x <= n-2)
            if(GamePanel[x+1][y] == -1 || nm[x+1][y] == 999)
            {
                if(time == 1)
                    ++sum;
                else
                    nm[x+1][y] = 999;
            }
        if(x>=1 && y<=m-2)
            if(GamePanel[x-1][y+1] == -1 || nm[x-1][y+1] == 999)
            {
                if(time == 1)
                    ++sum;
                else
                    nm[x-1][y+1] = 999;
            }
        if(y <= m-2)
            if(GamePanel[x][y+1] == -1 || nm[x][y+1] == 999)
            {
                if(time == 1)
                    ++sum;
                else
                    nm[x][y+1] = 999;
            }
        if(x<=n-2 && y<=m-2)
            if(GamePanel[x+1][y+1] == -1 || nm[x+1][y+1] == 999)
            {
                if(time == 1)
                    ++sum;
                else
                    nm[x+1][y+1] = 999;
            }
        if(sum == num) {
            if(time == 1)
               continue;
            else
                return;
        }
        else
            return;
    }
}
void findlei(int GamePanel[30][30], int nm[30][30], int n, int m) {
    for(int x=0; x<n; ++x) {
        for(int y=0 ;y<m; ++y) {
            if(GamePanel[x][y] == 1)
                addlei(GamePanel, nm, n, m, x, y, 1);
            else if (GamePanel[x][y] == 2)
                addlei(GamePanel, nm, n, m, x, y, 2);
            else if (GamePanel[x][y] == 3)
                addlei(GamePanel, nm, n, m, x, y, 3);
            else if (GamePanel[x][y] == 4)
                addlei(GamePanel, nm, n, m, x, y, 4);
            else if (GamePanel[x][y] == 5)
                addlei(GamePanel, nm, n, m, x, y, 5);
            else if (GamePanel[x][y] == 6)
                addlei(GamePanel, nm, n, m, x, y, 6);
            else if (GamePanel[x][y] == 7)
                addlei(GamePanel, nm, n, m, x, y, 7);
            else if (GamePanel[x][y] == 8)
                addlei(GamePanel, nm, n, m, x, y, 8);
        }
    }
}//找雷

int findlocate(int GamePanel[30][30], int nm[30][30], int n, int m, int& x, int& y) {
    int sum = 0;
    for(int time=1; time<=2; ++time) {
        if(x>=1 && y>=1) {
            if(nm[x-1][y-1] == 999) {
                if(time == 1)
                    ++sum;
            } else if (GamePanel[x-1][y-1] == -1)
                if(time == 2) {
                    x = x-1;
                    y = y-1;
                    return 1;
                }
        }
        if(y >= 1){
            if(nm[x][y-1] == 999) {
                if(time == 1)
                    ++sum;
            } else if (GamePanel[x][y-1] == -1)
                if(time == 2) {
                    y = y-1;
                    return 1;
                }
        }
        if(x<=n-2 && y>=1){
            if(nm[x+1][y-1] == 999) {
                if(time == 1)
                    ++sum;
            } else if (GamePanel[x+1][y-1] == -1)
                if(time == 2) {
                    x = x+1;
                    y = y-1;
                    return 1;
                }
        }
        if(x >= 1){
            if(nm[x-1][y] == 999) {
                if(time == 1)
                    ++sum;
            } else if (GamePanel[x-1][y] == -1)
                if(time == 2) {
                    x = x-1;
                    return 1;
                }
        }
        if(x <= n-2){
            if(nm[x+1][y] == 999) {
                if(time == 1)
                    ++sum;
            } else if (GamePanel[x+1][y] == -1)
                if(time == 2) {
                    x = x+1;
                    return 1;
                }
        }
        if(x>=1 && y<=m-2){
            if(nm[x-1][y+1] == 999) {
                if(time == 1)
                    ++sum;
            } else if (GamePanel[x-1][y+1] == -1)
                if(time == 2) {
                    x = x-1;
                    y = y+1;
                    return 1;
                }
        }
        if(y <= m-2){
            if(nm[x][y+1] == 999) {
                if(time == 1)
                    ++sum;
            } else if (GamePanel[x][y+1] == -1)
                if(time == 2) {
                    y = y+1;
                    return 1;
                }
        }
        if(x<=n-2 && y<=m-2){
            if(nm[x+1][y+1] == 999) {
                if(time == 1)
                    ++sum;
            } else if (GamePanel[x+1][y+1] == -1)
                if(time == 2) {
                    x = x+1;
                    y = y+1;
                    return 1;
                }
        }
        if(sum == GamePanel[x][y]) {
            if(time == 1)
               continue;
            else
                return 0;
        }
        else
            return 0;
    }
    return 0;
}
void machine(int GamePanel[30][30], int n, int m, int& x, int& y) {
    int nm[30][30];

    //
    for(int i=0; i<30; ++i) {
        for(int j=0; j<30; ++j){
            nm[i][j] = 0;
        }
    }
    //

    findlei(GamePanel, nm,  n, m);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(GamePanel[n][m] != -1) {
                int a = i;
                int b = j;
                if(findlocate(GamePanel, nm, n, m, a, b)) {
                    x = a;
                    y = b;
                    return;
                }
            }
        }
    }
//方法1
//弊端：雷数量大的时候失败率非常高
    int i=rand()%n;
    int j=rand()%m;
    while(GamePanel[i][j] != -1 || nm[i][j] == 999) {
        i=rand()%n;
        j=rand()%m;
    }
    x = i;
    y = j;
//方法2
//    for(int i=0; i<n; ++i) {
//        for(int j=0; j<m; ++j) {
//            if(GamePanel[i][j] == -1 && nm[i][j] != 999) {
//                x = i;
//                y = j;
//                return;
//            }
//        }
//    }//没有可以推理的位置
}
void add(int nm[30][30], int n, int m, int x, int y) {
    if(x<0 || x>n-1) {
        return;
    }
    if(y<0 || y>m-1) {
        return;
    }
    if(nm[x][y] == 999) {
        return;
    } else {
        ++nm[x][y];
    }
}

void turntozero(int nm[30][30], int printnm[30][30], int n, int m, int i, int j, int yes[30][30]) {
    if(i<0 || i>n-1 || j<0 || j>m-1) {
        return;
    } else if(yes[i][j] == 1) {
        return;//雷处事先设置好1了
    } else if (nm[i][j] != 0) {
        printnm[i][j] = nm[i][j];
        yes[i][j] = 1;
    } else if(nm[i][j] == 0) {
        printnm[i][j] = 0;
        yes[i][j] = 1;
        if(i!=n-1 && yes[i+1][j] != 1) {
            turntozero(nm, printnm, n, m, i+1, j, yes);
        }
        if(j!=m-1 && yes[i][j+1] != 1) {
            turntozero(nm, printnm, n, m, i, j+1, yes);
        }
        if(i!=0 && yes[i-1][j] != 1) {
            turntozero(nm, printnm, n, m, i-1, j, yes);
        }
        if(j!=0 && yes[i][j-1] != 1) {
            turntozero(nm, printnm, n, m, i, j-1, yes);
        }
        if(i!=n-1 && j!=0 && yes[i+1][j-1] != 1) {
            turntozero(nm, printnm, n, m, i+1, j-1, yes);
        }
        if(i!=0 && j!=m-1 && yes[i-1][j+1] != 1) {
            turntozero(nm, printnm, n, m, i-1, j+1, yes);
        }
        if(i!=0 && j!=0 && yes[i-1][j-1] != 1) {
            turntozero(nm, printnm, n, m, i-1, j-1, yes);
        }
        if(i!=n-1 && j!=m-1 && yes[i+1][j+1] != 1) {
            turntozero(nm, printnm, n, m, i+1, j+1, yes);
        }
    }
}
int numoffuyi(int printnm[30][30], int n, int m) {
    int sum = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(printnm[i][j] == -1) {
                ++sum;
            }
        }
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    int n=0,m=0,k=0,l=0;
    cin>>n>>m>>k>>l;
    int nm[30][30];
    int printnm[30][30];
    int yes[30][30];

    for(int i=0; i<n; ++i) {//幕后图
        for(int j=0; j<m; ++j) {
            nm[i][j] = 0;
        }
    }
    //打印图
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            printnm[i][j] = -1;
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            yes[i][j] = 0;
        }
    }
    int x, y;//雷的位置
    
    for(int num=1; num <= k; ++num) {
        x = rand()%n;
        y = rand()%m;
        while(nm[x][y] == 999) {
            x = rand()%n;
            y = rand()%m;
        }
        nm[x][y] = 999;
        add(nm, n, m, x+1, y+1);
        add(nm, n, m, x+1, y);
        add(nm, n, m, x+1, y-1);
        add(nm, n, m, x, y+1);
        add(nm, n, m, x, y-1);
        add(nm, n, m, x-1, y+1);
        add(nm, n, m, x-1, y);
        add(nm, n, m, x-1, y-1);
    }
    //判断和输出
    int i, j;
    for(int times = 0; times < l; ++times) {
        machine(printnm, n, m, i, j);
        cout<<endl<<times+1<<"次坐标"<<i<<","<<j<<endl;
        if(nm[i][j] == 999) {
            cout<<"You lose";
            exit(0);
        } else if (printnm[i][j] != -1) {
            continue;
            //点按除了-1外无效
        } else if (nm[i][j] != 999 && nm[i][j] != 0) {
            printnm[i][j] = nm[i][j];
            printthem(printnm, n, m);
            //点按代数字的
        } else if (nm[i][j] == 0) {
            turntozero(nm, printnm, n, m, i, j, yes);
            printthem(printnm, n, m);
            //点按后更新一大片
        }
        if (numoffuyi(printnm, n, m) == k) {
            cout<<"You win";
            exit(0);
        }
        cout<<endl;
    }
    cout<<"You lose";
    return 0;
}
