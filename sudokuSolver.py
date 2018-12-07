def printGrid(arr): 
	for i in range(9): 
		for j in range(9): 
			print(arr[i][j], end="\t") 
		print('\n') 
 
def findEmptyLocation(arr,l): 
	for row in range(9): 
		for col in range(9): 
			if(arr[row][col]==0): 
				l[0]=row 
				l[1]=col 
				return True
	return False

def inRow(arr,row,num): 
	for i in range(9): 
		if(arr[row][i] == num): 
			return True
	return False

def inCol(arr,col,num): 
	for i in range(9): 
		if(arr[i][col] == num): 
			return True
	return False

def inBox(arr,row,col,num): 
	for i in range(3): 
		for j in range(3): 
			if(arr[i+row][j+col] == num): 
				return True
	return False
 
def isSafeLocation(arr,row,col,num):
	return not inRow(arr,row,num) and not inCol(arr,col,num) and not inBox(arr,row - row%3,col - col%3,num) 
 
def solveSudoku(arr): 
	l=[0,0] 
	if(not findEmptyLocation(arr,l)): 
		return True
	
	row=l[0] 
	col=l[1] 
	for num in range(1,10): 
		if(isSafeLocation(arr,row,col,num)): 
			arr[row][col]=num 
			if(solveSudoku(arr)): 
				return True
			arr[row][col] = 0
	return False

if __name__=="__main__": 
	grid=[] 

	for i in range(1, 10):
		a = []
		a.append(list(map(int, input("Row {}:\t".format(i)))))
		if(len(a[0]) != 9):
			print("Please check your input!")
			a = []
			a.append(list(input("Row {}:\t".format(i))))
		grid.append(a[0])

	if(solveSudoku(grid)): 
		printGrid(grid) 
	else: 
		print("No solution exists")