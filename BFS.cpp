/*
根据上述例子，我们需要每次记录本轮循环队列中的节点数量，以便最终判定最短路径长度；
另一方面，对于已生成的节点，我们需要标记，防止重复被生成。
一般而言，为了写代码时更加方便直观，我们在扩展过程中不判断是否找到了答案，而是每次弹出队头元素时进行判断。
*/
//（1）初始化队列及标记数组，存入起点
queue<int> q;
vector<bool> vis(n);

q.push(begin_node);//存入起点
vis[begin_node] = true;//标记

//BFS搜索🔍
while(1){
	int cnt = q.size();//BFS搜索需要扩展的节点个数
	if(cnt == 0){
		break;//队列中没有需要扩展的节点，退出
	}
	
	while(cnt--){
		int cur = q.front();//弹出队头元素
		q.pop();
		
		if(cur == target){
			break;//找到答案，退出搜索
		}
		
		action(cur);//特殊情况：对当前元素进行处理
		
		for(auto x : cur.children){
			if(!vis[x]){//避免重复访问
				q.push(x);//访问其子节点，对没有访问的元素压入队列并进行标记
				vis[x] = true;
			}
		}
	}
	
	if(!cnt){
		break;//扩展完成，找到目标元素，退出搜素
	}
}

//节点Node包含元素和距离
// 1.初始化队列及标记数组，存入起点
queue<pair<int, int>> q;
vector<bool> vis(n);

q.push({begin_node, 0}); // 存入起点，起始距离0，标记
vis[begin_node] = true;

// 2.开始搜索
while(!q.empty()) {
    auto [cur, dist] = q.front(); // 弹出队头元素
    q.pop();

    // 找到答案，返回结果
    if(cur == target) return dist;
    
    action(cur); //有些题目需要对当前元素做处理

    for(int x : cur.children) {
        if(!vis[x]) {
            q.push({x, dist + 1});
            vis[x] = true;
        }
    }
}
