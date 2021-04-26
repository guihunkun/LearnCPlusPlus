#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

static bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	// ��pair�Եĵ�2�����Ĵ�С�Ӵ���С���� 
	return a.second > b.second;
}

int main()
{
	vector<pair<int, int> > scores;
	scores.push_back(make_pair(1, 3));
	scores.push_back(make_pair(2, 1));
	scores.push_back(make_pair(3, 2));
	cout<<"before sort : "<<endl;
	for(int i = 0; i < scores.size(); i++)
	{
		cout<<scores[i].first<<" "<<scores[i].second<<endl;
	}
	//sort(scores.begin(), scores.end(), cmp); // ���㷨���ݺ��� 
	sort(scores.begin(),scores.end(), [](const pair<int, int>& a, const pair<int, int>& b){ return a.second > b.second; }); // lambda���ʽ 
	cout<<"after sort : "<<endl; 
	for(int i = 0; i < scores.size(); i++)
	{
		cout<<scores[i].first<<" "<<scores[i].second<<endl;
	}
	return 0;
}

