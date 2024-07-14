// // #include <bits/stdc++.h>
// // #define int long long int
// // #define yes cout << "YES" << endl;
// // #define no cout << "NO" << endl
// // #define MOD 1000000007
// // // const int maxsize = 1e5;
// // // int arr[maxsize+1];
// // #define test     \
// //     int monu;    \
// //     cin >> monu; \
// //     while (monu--)
// // using namespace std;
// // string ans = "";
// // int num = INT_MAX;
// // bool valid(int i, int j, int n, int m)
// // {
// //     if (i >= 0 and i < n and j >= 0 and j < m)
// //         return true;
// //     else
// //         return false;
// // }
// // void dfs(int i, int j, vector<vector<int>> &arr, vector<vector<bool>> &vis, int &n, int &m, string &str, vector<int> &dir, vector<char> &chdir)
// // {
// //     vis[i][j] = true;
// //     if (arr[i][j] == -1)
// //     {
// //         if (num > str.size())
// //         {
// //             ans = str;
// //             num = str.length();
// //         }
// //         return;
// //     }
// //     for (int it = 1; it < dir.size(); it++)
// //     {
// //         int r = i + dir[it - 1], c = j + dir[it];
// //         if (valid(r, c, n, m) and vis[r][c] == false and arr[r][c])
// //         {
// //             str += chdir[it - 1];
// //             dfs(r, c, arr, vis, n, m, str, dir, chdir);
// //             str.pop_back();
// //         }
// //     }
// //     vis[i][j] = false;
// // }
// // signed main()
// // {
// //     int n, m;
// //     cin >> n >> m;
// //     vector<vector<int>> arr(n, vector<int>(m, 0));
// //     vector<vector<bool>> vis(n, vector<bool>(m, 0));
// //     pair<int, int> start;
// //     for (int i = 0; i < n; i++)
// //     {
// //         for (int j = 0; j < m; j++)
// //         {
// //             char ch;
// //             cin >> ch;
// //             if (ch == 'A')
// //             {
// //                 start = {i, j};
// //             }
// //             else if (ch == 'B')
// //                 arr[i][j] = -1;
// //             else
// //                 arr[i][j] = (ch == '.') ? 1 : 0;
// //         }
// //     }
// //     vector<int> dir = {0, 1, 0, -1, 0};
// //     vector<char> chdir = {'R', 'D', 'L', 'U'};
// //     string str = "";
// //     dfs(start.first, start.second, arr, vis, n, m, str, dir, chdir);
// //     if (num != INT_MAX)
// //     {
// //         yes
// //                 cout
// //             << num << endl;
// //         cout << ans << endl;
// //     }
// //     else
// //     {
// //         no;
// //     }
// //     // dusro ka code copy karne se ghar nahi chalta bhai
// // }
// #include <bits/stdc++.h>
// // #define int long long int
// #define yes cout << "YES" << endl;
// #define no cout << "NO" << endl
// // #define MOD 1000000007
// // const int maxsize = 1e5;
// // int arr[maxsize+1];
// #define test     \
//     int monu;    \
//     cin >> monu; \
//     while (monu--)
// using namespace std;
// int n, m;
// int arr[1001][1001];
// bool vis[1001][1001];
// char ent[1001][1001];
// signed main()
// {
//     // int n, m;
//     cin >> n >> m;
//     // vector<vector<int>> arr(n, vector<int>(m, 0));
//     // vector<vector<bool>> vis(n, vector<bool>(m, 0));
//     pair<int, int> start;
//     // vector<vector<char>> ent(n,vector<char>(m,'.'));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             char ch;
//             cin >> ch;
//             if (ch == 'A')
//             {
//                 start = {i, j};
//             }
//             else if (ch == 'B')
//                 arr[i][j] = -1;
//             else
//                 arr[i][j] = (ch == '.') ? 1 : 0;
//         }
//     }
//     queue<pair<int, int>> q;
//     vector<int> dir = {0, 1, 0, -1, 0};
//     vector<char> chdir = {'R', 'D', 'L', 'U'};
//     q.push(start);
//     while (!q.empty())
//     {
//         int i = q.front().first, j = q.front().second;
//         q.pop();
//         if (arr[i][j] == -1)
//         {
//             yes;
//             string str = "";
//             while (i != start.first or j != start.second)
//             {
//                 str += ent[i][j];
//                 if (ent[i][j] == 'U')
//                 {
//                     i = i + 1;
//                 }
//                 else if (ent[i][j] == 'D')
//                 {
//                     i = i - 1;
//                 }
//                 else if (ent[i][j] == 'L')
//                 {
//                     j = j + 1;
//                 }
//                 else
//                 {
//                     j = j - 1;
//                 }
//             }
//             cout << str.length() << endl;
//             for (int i = str.length() - 1; i >= 0; i--)
//                 cout << str[i];
//             return 0;
//         }
//         vis[i][j] = true;
//         for (int it = 1; it < dir.size(); it++)
//         {
//             int r = i + dir[it - 1], c = j + dir[it];
//             if ((i >= 0 and i < n and j >= 0 and j < m) and vis[r][c] == false and (arr[r][c] == -1 or arr[r][c]))
//             {
//                 ent[r][c] = chdir[it - 1];
//                 q.push({r, c});
//             }
//         }
//         // for (int it = 0; it < n; it++)
//         // {
//         //     for (int jt = 0; jt < m; jt++)
//         //     {
//         //         // if(it==start.first and jt==start.second) cout<<'A'<<" ";
//         //         // else if(arr[it][jt]==-1) cout<<'B'<<" ";
//         //         // else
//         //         // cout<<vis[it][jt]<<" ";
//         //         cout<<ent[it][jt]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         //  cout<<endl;
//     }
//     no;
//     // dusro ka code copy karne se ghar nahi chalta bhai
// }

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
 
char ar[1001][1001];
char br[1001][1001];
bool vis[1001][1001];
int n , m;
vector<char> path;
 
bool isValid(int x , int y){
	
	if(x < 1 || x > n || y < 1 || y > m) return false;
	
	if(ar[x][y] == '#' || vis[x][y] == true) return false;
	
	return true;
}
 
bool bfs(int x , int y)
{
	queue<pair<int,int> > q;
	q.push({x , y});
	vis[x][y] = true;
	
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		
		if(ar[a][b] == 'B'){
			while(1){
				path.push_back(br[a][b]);
			
				if(path.back() == 'L') b++;
				if(path.back() == 'R') b--;
				if(path.back() == 'U') a++;
				if(path.back() == 'D') a--;
				
				if(a == x && b == y)
				break;
			}
			return true;
		}
		
		//left
		if(isValid(a , b - 1)) br[a][b-1] = 'L' , q.push({a , b-1}) , vis[a][b-1] = true;
		
		//right
		if(isValid(a , b + 1)) br[a][b+1] = 'R' , q.push({a , b+1}) , vis[a][b+1] = true;
		
		//up
		if(isValid(a - 1, b)) br[a - 1][b] = 'U' , q.push({a - 1 , b}) , vis[a-1][b] = true;
		
		//down
		if(isValid(a + 1, b)) br[a + 1][b] = 'D' , q.push({a + 1 , b}) , vis[a+1][b] = true;
		
	}
	
	return false;
}
 
int main()
{
	cin>>n>>m;
	int x;
	int y;
	
	REP(i , n) REP(j , m){
		cin>>ar[i][j];
		if(ar[i][j] == 'A') x = i , y = j;
	}
	
	if(bfs(x , y) == true){
		cout<<"YES"<<endl<<path.size()<<endl;
		while(path.size() > 0) cout<<path.back() , path.pop_back();
	}
	else{
		cout<<"NO";
	}
}
 
 
 