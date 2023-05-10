#ifndef sort_h
#define sort_h
#include "file.h"
#include <string.h>
#include "student.h"
using namespace std;

// ================== Swap =====================
void Swap(undergradute &a, undergradute &b)
{
	undergradute temp = a;
	a = b;
	b = temp;
}
// =============Standard string=================
string adjustName(string name)
{
	string correctName;
	int a, b;
	int l = name.length();
	for (int i = l - 1; i >= 0; i--)
	{
		if (name.at(i) != ' ')
		{
			a = i;
			break;
		}
	}
	for (int i = a; i >= 0; i--)
	{
		if (name.at(i) == ' ')
		{
			correctName = name.substr(i + 1, a - i);
			b = i;
			break;
		}
	}
	for (int i = 0; i < b; i++)
	{
		if (name.at(i) != ' ')
			correctName += name.substr(i, 1);
	}
	return correctName;
}
int Is_Compare(string a, string b)
{
	string c = adjustName(a);
	string d = adjustName(b);
	return c.compare(d);
}
// =============select sort Name================
void SelectionSortName(undergradute a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Is_Compare(a[i].name,a[j].name)>0)
				Swap(a[i], a[j]);
		}
	}
}
// ===============select sort class===============
void SelectionSortClass(undergradute a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].classRoom.compare(a[j].classRoom)>0)
				Swap(a[i], a[j]);
		}
	}
}
// ===============select sort grade=============
void SelectionSortGradeMedium(undergradute a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].getGradeMedium() > a[j].getGradeMedium())
				Swap(a[i], a[j]);
		}
	}
}
// ===============select sort id ===============
void SelectionSortID(undergradute a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].id.compare(a[j].id)>0)
				Swap(a[i], a[j]);
		}
	}
}
//================Quick sort name===============
void QuickSortName(undergradute a[], int l, int r)
{
	undergradute p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j)
	{
		while (Is_Compare(a[i].name, p.name) < 0)
		{
			i++;
		}
		while (Is_Compare(a[j].name, p.name) > 0)
		{
			j--;
		}
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r)
	{
		QuickSortName(a, i, r);
	}
	if (l < j)
	{
		QuickSortName(a, l, j);
	}
}
// ============Quick sort grade medium==========
void QuickSortGradeMedium(undergradute a[], int l, int r)
{
	undergradute p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j)
	{
		while (a[i].getGradeMedium() < p.getGradeMedium())
		{
			i++;
		}
		while (a[j].getGradeMedium() > p.getGradeMedium())
		{
			j--;		
		}
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r)
	{
		QuickSortGradeMedium(a, i, r);
	}
	if (l < j)
	{
		QuickSortGradeMedium(a, l, j);
	}
}
// ==============Quick sort class===============
void QuickSortClass(undergradute a[], int l, int r)
{
	undergradute p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j)
	{
		while (a[i].classRoom.compare(p.classRoom ) < 0)
		{
			i++;
		}
		while (a[j].classRoom.compare(p.classRoom ) > 0)
		{
			j--;
		}
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r)
	{
		QuickSortClass(a, i, r);
	}
	if (l < j)
	{
		QuickSortClass(a, l, j);
	}
}
#endif