/*
// 1.
// 示例输入：
// 10
// 0 0 1 0 0 0 0 1 0 0
#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin >> m;
    if (m<=1)   cout<<0;

    vector<int> vec(m), visited(m, 0);
    for (int i=0;i<m;++i)       cin>>vec[i];

    //  暂不考虑全0
    for (int i=0;i<m;++i)
    {
        if (1==vec[i])
        {
            visited[i] = 1;
            if (i-1 > 0)    visited[i-1] = 1;
            if (i+1 < m)    visited[i+1] = 1;
        }
    }
    //for (int i=0;i<m;++i)       cout <<visited[i] <<" ";
    int p, cnt = 0;
    if (m < 2)      cout << 0;
    else {
        if (vec[0] == 0 && vec[1] == 0)
            cnt++;

        p = 1;
        while (p + 1 < m && p + 2 < m) {
            if (vec[p] == 0 && vec[p + 1] == 0 && vec[p + 2] == 0){
                cnt++;
                vec[p+1] = 1;
            }
            p = p + 1;
        }

        if(vec[p]==0 && vec[p+1]==0)
            cnt++;
    }

    cout << cnt;

    ///*
    int cnt = 0;
    for (int i=0;i<m;++i)
    {
        if (0==visited[i] && 0==vec[i])
        {
            ++ cnt;
            visited[i] = 1;
            //if (i-1 > 0)    visited[i-1] = 1;
            if (i+1 < m)    visited[i+1] = 1;
        }

    }
    cout << cnt;
    ////
    return 0;
}
*/





// 2. 消灭星星

/*
输入示例
5 4
1 2 1 4 1
1 1 1 1 3
2 4 1 2 3
2 5 1 3 2
5 2 1 5 5
1 2
1 3
1 5
3 4
*/

#include <iostream>
using namespace std;


class Star
{
public:
    int ROW;
    int COL;
	enum Stat_star
	{
		willRemoved = -2,
		hasRemoved,
		normal
	};

	Star()
	{
		for (unsigned i = 0; i < ROW; i++)
		{
			for (unsigned j = 0; j < COL; j++)
			{
				m_arr[i][j].state = normal;
				m_arr[i][j].visited = false;
			}
		}
	}
	~Star(){}


	void print()
	{
		cout << "=====================" << endl;
		for (unsigned i = 0; i < ROW; i++)
		{
			for (unsigned j = 0; j < COL; j++)
			{cout << m_arr[i][j].data << "(" << m_arr[i][j].state << ")" << "\t";}
			cout << endl;
		}
	}

	void resetVisited()
	{
		for (unsigned i = 0; i < ROW; i++)
		{
			for (unsigned j = 0; j < COL; j++)
			{
				if(m_arr[i][j].state != hasRemoved)
				{m_arr[i][j].visited = false;}
			}
		}
	}

	//检测是否游戏结束
	bool checkGameOver()
	{
		for (unsigned i = 0; i < ROW; i++)
		{
			for (unsigned j = 0; j < COL; j++)
			{
				if(findWillRemove(i, j) > 1)
				{return false;}
			}
		}

		return true;
	}

	//检测是否要整列移动
	void checkColMove()
	{
		int dt = 0;	//列的增量
		for (int i = 0; i < COL - dt; i++)
		{
			bool allRemoved = true;
			//检测某列是否整列为空
			for (int j = 0; j < ROW; j++)
			{
				if(m_arr[j][i].state != hasRemoved)
				{
					allRemoved = false;
					break;
				}
			}

			//开始移动列
			if(allRemoved)
			{
				for (int x = i; x < COL; x++)
				{
					for (int y = 0; y < ROW; y++)
					{
						if(x + 1 < COL)
						{
							Star_data tempStar = m_arr[y][x];
							m_arr[y][x] = m_arr[y][x + 1];
						}
					}
				}
				//最后一列置空
				for (int y = 0; y < ROW; y++)
				{m_arr[y][COL - 1].state = hasRemoved;}
				i--;
				dt++;
			}
		}
	}

	//找到相同的球后，删除相同的球
	void removeSameStar()
	{
		//以列来找
		for (int j = 0; j < COL; j++)
		{
			for (int i = ROW - 1; i >= 0; i--)
			{
				if(m_arr[i][j].state == willRemoved)
				{
					Star_data tempStar = m_arr[i][j];
					//依次把星星下移，并且把空的星星放到最上面
					for (int x = i; x >= 0; x--)
					{
						if(x - 1 >= 0)
						{m_arr[x][j] = m_arr[x - 1][j];}
					}
					m_arr[0][j] = tempStar;
					m_arr[0][j].state = hasRemoved;
					i++;
				}
			}
		}
	}
//点击某个星星。找到将要被移除的星星
	int findWillRemove(int i, int j)
	{
		int findCount = 0;
		findWillRemove(i, j, findCount);
		resetVisited();
		return findCount;
	}
	//查找将要被移除的
	void findWillRemove(int i, int j,  int &findCount)
	{
		if(i >= ROW || i < 0 || j >= COL || j < 0 || m_arr[i][j].state == hasRemoved || m_arr[i][j].visited)
		{return;}

		m_arr[i][j].visited = true;
		findCount++;

		//左
		if(i - 1 >= 0 && m_arr[i - 1][j].state != hasRemoved && m_arr[i - 1][j].data == m_arr[i][j].data)
		{
			m_arr[i][j].state = willRemoved;
			m_arr[i - 1][j].state = willRemoved;
			findWillRemove(i - 1, j, findCount);
		}
		//右
		if(i + 1 < ROW && m_arr[i + 1][j].state != hasRemoved && m_arr[i + 1][j].data == m_arr[i][j].data)
		{
			m_arr[i][j].state = willRemoved;
			m_arr[i + 1][j].state = willRemoved;
			findWillRemove(i + 1, j, findCount);
		}
		//上
		if(j + 1 < COL && m_arr[i][j + 1].state != hasRemoved && m_arr[i][j + 1].data == m_arr[i][j].data)
		{
			m_arr[i][j].state = willRemoved;
			m_arr[i][j + 1].state = willRemoved;
			findWillRemove(i, j + 1, findCount);
		}
		//下
		if(j - 1 >= 0 && m_arr[i][j - 1].state != hasRemoved && m_arr[i][j - 1].data == m_arr[i][j].data)
		{
			m_arr[i][j].state = willRemoved;
			m_arr[i][j - 1].state = willRemoved;
			findWillRemove(i, j - 1, findCount);
		}
	}

	struct Star_data
	{
		int data;	//数据
		Stat_star state;	//状态
		bool visited;	//是否访问
	};
	Star_data m_arr[100][100];
};


int main()
{
    int row, nshot;
	cin >> row >> nshot;
	int arr[row][row];
	Star star;
	star.ROW = row;
	star.COL = row;
	for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
        {
            cin >> arr[i][j];
        }

	for (unsigned i = 0; i < row; i++)
	{
		for (unsigned j = 0; j < row; j++)
		{star.m_arr[i][j].data = arr[i][j];}
	}

	//star.print();
    for (int i = 0; i < nshot; ++i)
    {
        int x, y;
        cin >> x >> y;
        int cnt = star.findWillRemove(row-x, y-1);
        //cout << cnt << endl;
        //int cnt = star.findWillRemove(x, y);
        switch(cnt)
        {
            case 0:
                cout << "empty!\n"; break;
            case 1:
                cout << "only one!\n"; break;
            default:
                cout << cnt << endl;

        }
        star.removeSameStar();
        star.checkColMove();
        //star.print();
        if(star.checkGameOver())
            exit(0);
    }

	system("pause");
	return 0;
}




/*
// 3.
#include <bits/stdc++.h>
using namespace std;

int main (){
    int n, m, k;
	cin >> n >> m >> k;
	//cout << n << m << k;
	int arr[n][m][k];
	for ( int t = 0; t < k; ++t)
	{
		for ( int i = 0; i < n; ++ i)
		{
			for ( int j = 0; j < m; ++ j)
            {
                cin >> arr[i][j][t];
				//cout << i << j << t << endl;
            }
		}
		//cout << endl;
	}
	int cnt = 0;
	int idx = 1;
	if (k > m * n)
		cout << -1;
	else {
		while (idx < k) {
			idx *= 2;
			cnt++;
		}
		cout << cnt;
	}
	return 0;
}
*/
