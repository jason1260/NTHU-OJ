#include <bits/stdc++.h>
using namespace std;
class event {
    public:
    int age;
    string emotion;
    event() : age(0), emotion("") {}; 
    event(int a, string emo) : age(a), emotion(emo) {};
    bool operator< (event &e) {
        return (age != e.age) ? age < e.age : (emotion < e.emotion) ? 1 : 0;
    }
};
template <class T>
void mSort(T arg[], int st, int ed) {
    if (st >= ed) return;
    T arr[ed + 5];
    int mid = ((ed - st) >> 1) + st;
    int st1 = st, ed1 = mid;
    int st2 = mid + 1, ed2 = ed;
    mSort(arg, st1, ed1);
    mSort(arg, st2, ed2);
    int k = st;
    while (st1 <= ed1 && st2 <= ed2) arr[k++] = arg[st1] < arg[st2] ? arg[st1++] : arg[st2++];
    while (st1 <= ed1) arr[k++] = arg[st1++];
    while (st2 <= ed2) arr[k++] = arg[st2++];
    for (k = st; k <= ed; k++) arg[k] = arr[k];
}
int main() {
    int cnt = 0;
    int a, n; cin >> a >> n;
    event lt1[n + 5];
    vector<int> match_age;
    for (int i = 0; i < n; i++) {
        int tmp; string emo;
        cin >> tmp >> emo; event ttt = event(tmp, emo);
        lt1[i] = ttt;
    }
    mSort(lt1, 0, n - 1);
    lt1[n].age = 99999999;
    int b, k; cin >> b >> k;
    event lt2[k + 5];
    for (int i = 0; i < k; i++) {
        int tmp; string emo;
        cin >> tmp >> emo; event ttt = event(tmp, emo);
        lt2[i] = ttt;
    }
    mSort(lt2, 0, k - 1);
    lt2[k].age = 99999999;
    int index_1 = 0, index_2 = 0, cur_age = 0;
    int angry[2] = {0, 0}, fearful[2] = {0, 0}, happy[2] = {0, 0}, sad[2] = {0, 0};
    while (cur_age <= a || cur_age <= b) {
        //cout << index_1 << ' ' << index_2 << ' ' << cur_age << '\n';
        if (index_1 < n || index_2 < k) {
            if (lt1[index_1].age < lt2[index_2].age && lt1[index_1].age <= cur_age && index_1 < n) {
                //cout << "here\n";
                int tmp_age = lt1[index_1].age;
                while (lt1[index_1].age == tmp_age) {
                    if (lt1[index_1].emotion == "Angry") angry[0]++;
                    else if (lt1[index_1].emotion == "Fearful") fearful[0]++;
                    else if (lt1[index_1].emotion == "Happy") happy[0]++;
                    else sad[0]++;
                    index_1++;
                }
            }
            else if (lt1[index_1].age > lt2[index_2].age && lt2[index_2].age <= cur_age && index_2 < k) {
                //cout << "there\n";
                int tmp_age = lt2[index_2].age;
                while (lt2[index_2].age == tmp_age) {
                    if (lt2[index_2].emotion == "Angry") angry[1]++;
                    else if (lt2[index_2].emotion == "Fearful") fearful[1]++;
                    else if (lt2[index_2].emotion == "Happy") happy[1]++;
                    else sad[1]++;
                    index_2++;
                }
            }
            else if (index_1 < n && index_2 < k && lt1[index_1].age == lt2[index_2].age && lt2[index_2].age <= cur_age) {
                //cout << "fghjk\n";
                int tmp_age = lt1[index_1].age;
                while (lt1[index_1].age == tmp_age) {
                    if (lt1[index_1].emotion == "Angry") angry[0]++;
                    else if (lt1[index_1].emotion == "Fearful") fearful[0]++;
                    else if (lt1[index_1].emotion == "Happy") happy[0]++;
                    else sad[0]++;
                    index_1++;
                }
                tmp_age = lt2[index_2].age;
                while (lt2[index_2].age == tmp_age) {
                    if (lt2[index_2].emotion == "Angry") angry[1]++;
                    else if (lt2[index_2].emotion == "Fearful") fearful[1]++;
                    else if (lt2[index_2].emotion == "Happy") happy[1]++;
                    else sad[1]++;
                    index_2++;
                }
            }
        }
        if (angry[0] == angry[1] && fearful[0] == fearful[1] && happy[0] == happy[1] && sad[0] == sad[1]) {
            match_age.emplace_back(cur_age); cnt++;
        }
        //cout << happy[0] << ' ' << angry[0] << ' ' << fearful[0] << ' ' << sad[0] << '\n';
        cur_age++;
    }
    cout << cnt << '\n';
    if (cnt != 0) {
        for (int i = 0; i < match_age.size(); i++) {
            (i != match_age.size() - 1) ? cout << match_age[i] << ' ' : cout << match_age[i] << '\n';
        }
    }
}