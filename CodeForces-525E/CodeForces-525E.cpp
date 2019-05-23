#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long ll;
ll n, k, s, ans = 0;
ll a[30], fact[30], canuse[30];
map<ll, int> mp[30]; // ���� i ���׳ˣ� sumΪ firts �� second����
void dfs1(int cur, int r, ll sum)
{
    // �ڼ������֣����˼�����̾�ţ� Ŀǰ�Ĵ��Ƕ���
    if (cur == n / 2 + 1) {
        mp[r][sum]++;
        return;
    }
    if (sum > s)
        return;

    dfs1(cur + 1, r, sum + a[cur]); // ѡ�������
    dfs1(cur + 1, r, sum); // ��ѡ
    if (r < k && canuse[cur]) {
        dfs1(cur + 1, r + 1, sum + fact[cur]); // �׳�
    }
}
void dfs2(int cur, int r, ll sum)
{
    // �ڼ������֣����˼�����̾�ţ� Ŀǰ�Ĵ��Ƕ���
    if (cur == n / 2) {
        ll tar = s - sum;
        for (int i = 0; i <= k - r; i++) {
            ans += mp[i][tar];
        }
        return;
    }
    if (sum > s)
        return;

    dfs2(cur - 1, r, sum + a[cur]); // ѡ�������
    dfs2(cur - 1, r, sum); // ��ѡ
    if (r < k && canuse[cur]) {
        dfs2(cur - 1, r + 1, sum + fact[cur]); // �׳�
    }
}
int main()
{

    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        fact[i] = 1;
        canuse[i] = 1;
        for (int j = 2; j <= a[i]; j++) {
            fact[i] *= j;
            if (fact[i] > s) {
                canuse[i] = 0;
                break;
            }
        }
    }
    dfs1(0, 0, 0);
    dfs2(n - 1, 0, 0);
    cout << ans << endl;
    return 0;
}