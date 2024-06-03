// 1 based, point update and range queries
int segment(int low, int high, 
			int pos, int strip) { 
	if (high == low)
		ini_seg[strip][pos] = rect[strip][low]; 
	else { 
		int mid = (low + high) / 2; 
		segment(low, mid, 2 * pos, strip); 
		segment(mid + 1, high, 2 * pos + 1, strip); 
		ini_seg[strip][pos] = ini_seg[strip][2 * pos] + 
							ini_seg[strip][2 * pos + 1]; 
	} 
} 

int finalSegment(int low, int high, int pos) { 
	if (high == low) { 

		for (int i = 1; i < 2 * sizes; i++) 
			fin_seg[pos][i] = ini_seg[low][i]; 
	} 
	else { 
		int mid = (low + high) / 2; 
		finalSegment(low, mid, 2 * pos); 
		finalSegment(mid + 1, high, 2 * pos + 1); 

		for (int i = 1; i < 2 * sizes; i++) 
			fin_seg[pos][i] = fin_seg[2 * pos][i] + 
							fin_seg[2 * pos + 1][i]; 
	} 
} 

int finalQuery(int pos, int start, int end, 
			int x1, int x2, int node) { 
	if (x2 < start || end < x1)
		return 0; 

	if (x1 <= start && end <= x2)
		return fin_seg[node][pos]; 

	int mid = (start + end) / 2; 
	int p1 = finalQuery(2 * pos, start, mid, 
						x1, x2, node); 

	int p2 = finalQuery(2 * pos + 1, mid + 1, 
						end, x1, x2, node); 

	return (p1 + p2); 
} 

int query(int pos, int start, int end, 
		int y1, int y2, int x1, int x2) { 
	if (y2 < start || end < y1)
		return 0; 

	if (y1 <= start && end <= y2)
		return (finalQuery(1, 1, 4, x1, x2, pos)); 

	int mid = (start + end) / 2; 
	int p1 = query(2 * pos, start, 
				mid, y1, y2, x1, x2); 
	int p2 = query(2 * pos + 1, mid + 1, 
				end, y1, y2, x1, x2); 

	return (p1 + p2); 
} 

int finalUpdate(int pos, int low, int high, 
				int x, int val, int node) { 
	if (low == high)
		fin_seg[node][pos] = val; 
	else { 
		int mid = (low + high) / 2; 

		if (low <= x && x <= mid)
			finalUpdate(2 * pos, low, mid, x, val, node); 
		else
			finalUpdate(2 * pos + 1, mid + 1, high, 
									x, val, node);  

		fin_seg[node][pos] = fin_seg[node][2 * pos] + 
							fin_seg[node][2 * pos + 1]; 
	} 
} 

int update(int pos, int low, int high, int x, int y, int val) { 
	if (low == high)
		finalUpdate(1, 1, 4, x, val, pos); 
	else { 
		int mid = (low + high) / 2; 

		if (low <= y && y <= mid)
			update(2 * pos, low, mid, x, y, val); 
		else
			update(2 * pos + 1, mid + 1, high, x, y, val); 

		for (int i = 1; i < sizes; i++) 
			fin_seg[pos][i] = fin_seg[2 * pos][i] + 
							fin_seg[2 * pos + 1][i]; 
	} 
} 