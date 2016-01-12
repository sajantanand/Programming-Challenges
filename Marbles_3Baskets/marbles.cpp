#include <iostream>
#include <iomanip>
using namespace std;

void print();

bool tried[60][60][60];

struct node
{
	int numbers[3];
	node * next;
	node * prev;
	node * parent;

	node()
	{
		next = NULL;
		prev = NULL;
		parent = NULL;
	}

	~node()
	{
		//cout << "hello" << endl;
		//next = NULL;
		//prev = NULL;
		//parent = NULL;
		//if ( next ) delete next;
		next = 0;
		prev = 0;
		parent = 0;
	}
	
};

void print(node * p)
{
	if ( p )
		cout << setw(4) << right << p->numbers[0] << setw(4) << right << p->numbers[1] << setw(4) << right << p->numbers[2] << endl;
	
}

node * printSolution(node * p)
{
	if ( p->parent == NULL )
	{
		print(p);
		return NULL;
	}
	else	
	{
		if ( printSolution(p->parent) == NULL )
		{
			delete p->parent;
			p->parent = NULL;
		}
		//p->parent = printSolution(p->parent);
		return printSolution(p);
	}
}

void maxPositions ( int * array, int & a, int & b, int & c )
{
	a = 0;
	b = 1;
	c = 2;

	if ( array[0] <= array[1] && array[0] <= array[2] )
	{
		if ( array[1] > array[2] )
		{
			b = 2;
			c = 1;
		}
	}
	else if ( array[1] <= array[2] && array[1] <= array[0] )
	{
		a = 1;
		if ( array[0] < array[2] )
		{
			b = 0;
			c = 2;
		}
		else
		{
			b = 2;
			c = 0;
		}
	}
	else
	{
		a = 2;
		if ( array[0] < array[1] )
		{
			b = 0;
			c = 1;
		}
		else
		{
			b = 1;
			c = 0;
		}
	}
}

struct queue
{
	node * head;
	node * tail;
	int count;
	int solution;

	queue(int x, int y, int z)
	{
		head = new (nothrow) node;
		head->parent = NULL;
		head->numbers[0] = x;
		head->numbers[1] = y;
		head->numbers[2] = z;
		tried[x][y][z] = 1;
		tail = head;
		count = 1;	
		solution = -1;	
		if ( (x + y + z)%6 == 0 )
		{
			solution = (x + y + z)/3;
		}
	}

	void enqueue(int x, int y, int z, node * t)
	{
		if ( count > 0 )
		{
			tail->next = new (nothrow) node;
			tail = tail->next;
			tail->numbers[0] = x;
			tail->numbers[1] = y;
			tail->numbers[2] = z;
			tail-> parent = t;
		}
		else
		{
			if ( head ) delete head;
			head = new (nothrow) node;
			head->numbers[0] = x;
			head->numbers[1] = y;
			head->numbers[2] = z;
			tail = head;
			tail-> parent = t;
			count = 0;
		}
		count++;
	}

	node * dequeue()
	{
		node * temp = NULL;
		//cout << "here" << endl;
		if ( count > 0 )
		{
			temp = head;
			head = head->next;
			if ( count > 1 ) head->prev = NULL;
			count--;
		}
		return temp;
	}

	~queue()
	{
		if ( head ) delete head;
		count = -1;
		solution = -1;
	}
};

int visit(queue * line)
{
	node * temp = line->dequeue();
	if ( temp == NULL )
	{
		return 0;		//UNSOLVABLE
	}
	else if ( temp->numbers[0] == line-> solution && temp->numbers[1] == line-> solution && temp->numbers[2] == line-> solution )
	{
		printSolution( temp );	//SOLUTION
		return 1;
	}
	else if ( line->solution == -1 )
	{				//UNSOLVABLE
		return 0;
	}
	else
	{
		int x, y, z;
		maxPositions(temp->numbers, x, y, z);
		int possible[3];

		possible[z] = temp->numbers[z] - temp->numbers[x];
		possible[x] = 2 * temp->numbers[x];
		possible[y] = temp->numbers[y];
		//cout << possible[0] << possible[1] << possible[2] << endl;
		if ( tried[possible[0]][possible[1]][possible[2]] == 0 )
		{
			tried[possible[0]][possible[1]][possible[2]] = 1;
			line->enqueue(possible[0], possible[1], possible[2], temp);
		}

		possible[z] = temp->numbers[z] - temp->numbers[y];
		possible[y] = 2 * temp->numbers[y];
		possible[x] = temp->numbers[x];
		//cout << possible[0] << possible[1] << possible[2] << endl;
		if ( tried[possible[0]][possible[1]][possible[2]] == 0 )
		{
			tried[possible[0]][possible[1]][possible[2]] = 1;
			line->enqueue(possible[0], possible[1], possible[2], temp);
		}

		possible[y] = temp->numbers[y] - temp->numbers[x];
		possible[x] = 2 * temp->numbers[x];
		possible[z] = temp->numbers[z];
		//cout << possible[0] << possible[1] << possible[2] << endl;
		if ( tried[possible[0]][possible[1]][possible[2]] == 0 )
		{
			tried[possible[0]][possible[1]][possible[2]] = 1;
			line->enqueue(possible[0], possible[1], possible[2], temp);
		}	
		return 2;
	}

	if ( temp ) delete temp;	
}

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	while (!cin.eof())
	{
		queue * tree = new (nothrow) queue(x, y, z);
		node * first = tree->head;
		int status;

		do {
			status = visit ( tree );
		} while ( status == 2 );

		if (status == 0)
		{
			print(first);
		}
		cout << "============" << endl;
		if ( tree ) delete tree;
		cin >> x >> y >> z;
	}
	return 0;
}
